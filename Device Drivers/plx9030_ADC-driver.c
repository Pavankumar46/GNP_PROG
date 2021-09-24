/***************************************************************************
 *  PLX9030 Generic PCI Device Driver

 * Written By Bhushan V. Mhatre.
 
 *   Copyright (C) 2009 by bhushan / TATA POWER SED. 
 *   bvmhatre.tatapowersed.com  
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
/*
 *	Description:
 *	
 *	PCI 9030 LOCAL BUS INTERFACE CARD.
 *
 *	-----[ANY  FPGA] -- Xfrms -- Span 1
 *                  | | |                 |
 *               Local Bus                +----- Span 2
 *                | | |                   |
 *             [ PCI 9030 ]               +----- Span 3
 *              | | | | |                 |
 *               PCI BUS                  +----- Span 4
 * 
 *	All communicatiosn to the FPGA performed
 *  	through the PCI 9030 part using memory mapped I/O.
 *	FPGA act as A to D Convertor , Digital Input Output,
 *	D to A Convertor etc.
 *
 *	PCI 9030 mapped 3 Address Spaces BAR into PCs
 *
 *	BAR 0 -Memory Mapped I/O
 * 	PCI 9030 Configuration Register 128 bytes
 *
 *	BAR 1-I/O Mapped 
 *	
 *
 *	BAR 2 -Memory Mapped I/O
 *	FPGA Register Address 16 Kbytes.	
 *
 *
*/ 

// Header Files.

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/ioport.h>
#include <asm/uaccess.h>
#include <linux/kernel.h>
#include <linux/compiler.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/gfp.h>
#include <linux/interrupt.h>
//#include <asm/semaphore.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <linux/irq.h>

#define DEBUG

#ifdef DEBUG
	#define PDEBUG(data,str...)	printk(KERN_INFOdata,##str)
#else
	#define PDEBUG(data,str...) 
#endif

//Definations.

#define 	DRIVER_NAME 			"pci9030_adc"
#define		NUMBER_OF_BAR			6
#define 	PCI9030_VENDOR_ID 		0x10B5
#define 	PCI9030_DEVICE_ID		0x9030U
#define 	PCI9030_SUBVENDOR_ID	0x4321
#define 	PCI9030_SUBDEVICE_ID	0x0006
#define 	MFC_SLOT_NO				80
#define 	ADC_SLOT_NO				104
#define 	GPS_SLOT_NO				88
#define 	DIO1_SLOT_NO			90
#define 	DIO2_SLOT_NO			98

// PCI 9030 Configuration Address Space Registers. 

#define		PCISTATUS				0x06				//Satus Register
#define		PCICOMMAND				0x04				//Command Register.
#define		PCIBAS0MEMLOCALCONFIG	0x10				//BAR 1 Base Address(Memory Mapped Local Config)
#define		PCIBAS1IOLOCALCONFIG	0x14				//BAR 2 Base Address(I/O Mapped Local Config)
#define		PCIBAS2LAS0				0x18				//BAR 3 Base Address of Local Address Space
#define		PCIBAS3LAS1				0x1C				//BAR 4 Base Address of Local Address Space
#define		PCIBAS4LAS2				0x20				//BAR 5 Base Address of Local Address Space
#define		PCIBAS5LAS3				0x24				//BAR 6 Base Address of Local Address Space
#define		PCIBASLEROM				0x30				//Base Address of EEPROM
#define		PCIINTLINE				0x3C				//Interrupt Line.
#define		PCIINTPIN				0x3D				//Interrupt Pin.

// PCI 9030 Local Address Space Registes. 

#define		LAS0RR					0x00
#define		LAS1RR					0x04
#define		LAS2RR					0x08
#define		LAS3RR					0x0C
#define		EROMRR					0x10
#define		LAS0BA					0x14
#define		LAS1BA					0x18
#define		LAS2BA					0x1C
#define		LAS3BA					0x20
#define		EROMBA					0x24
#define		LAS0BRD					0x28
#define		LAS1BRD					0x2C
#define		LAS2BRD					0x30
#define		LAS3BRD					0x34
#define		EROMBRD					0x38
#define		CS0BASE					0x3C
#define		CS1BASE					0x40
#define		CS2BASE					0x44
#define		CS3BASE					0x48
#define		INTCSR					0x4C
#define		PROT_AREA				0x4E
#define		CNTRL					0x50
#define		GPIOC					0x54

#define 	NO_CARDS				2


static struct pci9030_adc_info
{
	int mj;
	int MOD_COUNT;
	struct semaphore *sem;							//Semaphore Lock.
	unsigned long local_base_add;						//local address space base address
	unsigned long config_base_add;						// configuration register base address
	unsigned long io_base;							//I/O base address
	unsigned long resource_flag;						//Resource flag of local address space
	unsigned long size;							//Size of local address space
	char *driver_name;							//Name of driver.
	unsigned long sub_deviceid;						//subdeviceid.
	unsigned long deviceid;							//Device ID
	unsigned long sub_vendorid;						// Sub Vendor ID
	unsigned long vendorid;							// Vendor ID
	u8 *irq_no;								//Interrupt Number 
	unsigned int BUS_WIDTH;							//Width of Local Bus
	
	struct pci_dev *pdev;
	
	
}*p_info_adc[NO_CARDS];

struct class *pci9030_adc_class;
EXPORT_SYMBOL(pci9030_adc_class);

//int MAJOR_NUM=0;									//Major Number For Charater Driver-Dynamic
static struct cdev pci9030_adc_cdev[NO_CARDS];
static dev_t dev[NO_CARDS];
//static int DIO_COUNT=0;
static int ADC_COUNT=0;
//static int DEF_COUNT=0;
//static int DAC_COUNT=0;
//static int MFC_COUNT=0;
static int USE_MOD_COUNT=0;
static int CURR_MOD_COUNT=0;

static int pci9030_adc_probe(struct pci_dev *pdev,const struct pci_device_id *pci9030_table_id);
static void pci9030_adc_disconnect(struct pci_dev *pdev);
//static int pci9030_suspend(struct pci_dev *pdev,u32 state);
//static int pci9030_resume(struct pci_dev *pdev);
static ssize_t pci9030_adc_write(struct file *flip,const char *name,size_t size,loff_t *fpos);
static ssize_t pci9030_adc_read(struct file *flip,char *name,size_t size,loff_t *fpos);
static int pci9030_adc_ioctl(struct inode *node,struct file *flip,unsigned int cmd,unsigned long count);
static int pci9030_adc_open(struct inode *node,struct file *flip);
static int pci9030_adc_release(struct inode *node,struct file *flip);
static loff_t pci9030_adc_llseek(struct file *filp, loff_t off, int whence);
static void Find_device(struct inode *node);

static struct pci_device_id pci9030_table_id[]  =
{
	{
		.vendor		=	PCI9030_VENDOR_ID,
		.device		=	PCI9030_DEVICE_ID,
		.subvendor	=	PCI9030_SUBVENDOR_ID,
		.subdevice	=	PCI9030_SUBDEVICE_ID,
			
	},
	{0,}
};

MODULE_DEVICE_TABLE(pci, pci9030_table_id);

/*static irqreturn_t pci9030_handler(int irq, void *dev_id, struct pt_regs *regs)
{
	return IRQ_HANDLED;
}*/

static ssize_t pci9030_adc_write(struct file *flip,const char __user *data,size_t size,loff_t *fpos)
{
	Find_device(flip->f_dentry->d_inode);
	unsigned long pci_base=p_info_adc[CURR_MOD_COUNT]->local_base_add,ssize=0;
	char * buf;
	short *buf16;
	int i,j,bwidth=0;
	
	unsigned long Address=pci_base + flip->f_pos;
	ssize=p_info_adc[CURR_MOD_COUNT]->size;
	bwidth=p_info_adc[CURR_MOD_COUNT]->BUS_WIDTH;
	//printk(KERN_INFO "pci9030_adc_adc: Write Character Device request size=%d\n",size);
	if (down_interruptible(p_info_adc[CURR_MOD_COUNT]->sem))
    		return -ERESTARTSYS;
	
	buf=(char *)kmalloc(sizeof(char *)*size,GFP_KERNEL);
	if(!buf)
	{
		up(p_info_adc[CURR_MOD_COUNT]->sem);
		kfree(buf);
		return -ENOMEM;

	}


	buf16=(short *)kmalloc(sizeof(short *)*size,GFP_KERNEL);
	if(!buf16)
	{
		up(p_info_adc[CURR_MOD_COUNT]->sem);
		kfree(buf);
		kfree(buf16);
		return -ENOMEM;
	}




	if(ssize < size + *fpos)
		size = ssize-(*fpos);

	//printk(KERN_INFO "pci9030_adc: Write Character Device base=0x%lx base+offset=0x%lld size=%d\n",Address,flip->f_pos,size);

	if(copy_from_user(buf,data,size))
	{
		up(p_info_adc[CURR_MOD_COUNT]->sem);
			return -EFAULT;

	}


	if(bwidth == 16)
	{
		for(i=0,j=0;i<size,j<(size/2);j++,i=i+2)
		{
			buf16[j]=((buf[i+1]<<8)|(buf[i]&0xFF));
			iowrite16(buf16[j],(void *)Address);
			Address=Address+0x02;
			//printk(KERN_INFO "pci9030_adc_adc: Write Character Device  data=0x%x datalsb=0x%x datamsb=0x%x\n",buf16[0],buf[0],buf[1]);
		}
		
		
	}

	flip->f_pos=0;
	up(p_info_adc[CURR_MOD_COUNT]->sem);
	kfree(buf);
	kfree(buf16);
	return size;

	
}

static ssize_t pci9030_adc_read(struct file *flip,char __user *data,size_t size,loff_t *filePos)
{
	Find_device(flip->f_dentry->d_inode);
	unsigned long pci_base=p_info_adc[CURR_MOD_COUNT]->local_base_add;
	char * buf;
	short *buf16;
	int /**buf32,*/i,j;
	unsigned long Address=(pci_base)+(flip->f_pos);

	unsigned long ssize=p_info_adc[CURR_MOD_COUNT]->size;
	int bwidth=p_info_adc[CURR_MOD_COUNT]->BUS_WIDTH;

	//printk(KERN_INFO "pci9030_adc: Read Character Device request size=%d\n",size);

	if (down_interruptible(p_info_adc[CURR_MOD_COUNT]->sem))
    		return -ERESTARTSYS;

	buf=(char *)kmalloc(sizeof(char *)*size,GFP_KERNEL);
	if(!buf)
	{
		up(p_info_adc[CURR_MOD_COUNT]->sem);
		kfree(buf);
		return -ENOMEM;
	}

	buf16=(short *)kmalloc(sizeof(short *)*size,GFP_KERNEL);
	if(!buf16)
	{
		up(p_info_adc[CURR_MOD_COUNT]->sem);
		kfree(buf);
		kfree(buf16);
		return -ENOMEM;

	}

	if(ssize < size + *filePos)
		size = ssize-(*filePos);

	//printk(KERN_INFO "pci9030_adc: Read Character Device on base_address=%lx base+offset=%lld size=%d\n",Address,flip->f_pos,size);

	if(bwidth == 16)
	{
		for(i=0,j=0;i<size,j<(size/2);j++,i=i+2)
		{
			buf16[j]=ioread16((void *)Address);
			//stoh(buf16[j],&buf[i]);
			buf[i+1]=((buf16[j]>>8));
			buf[i]=(buf16[j] & 0xFF);
			Address=Address+0x02;
			//i=i+2;
		}
		//printk(KERN_INFO "pci9030_adc: Write Character Device data 0x%lx-0x%lx-0x%lx\n",buf16[0],buf[0],buf[1]);
		
	}

	//printk(KERN_INFO "pci9030_adc: Read Character Device data=0x%x datalsb=0x%x datamsb=0x%x\n",buf16[0],buf[0],buf[1]);
	
	if(copy_to_user(data,buf,size))
	{
		up(p_info_adc[CURR_MOD_COUNT]->sem);
		kfree(buf);
		kfree(buf16);
		return -EFAULT;
	}
	flip->f_pos=0;
	up(p_info_adc[CURR_MOD_COUNT]->sem);
	kfree(buf);
	kfree(buf16);
	return size;
	
}

static loff_t pci9030_adc_llseek(struct file *filp, loff_t off, int whence)
{
	loff_t newpos;
	switch(whence) 
	{
		case 0: /* SEEK_SET */
			newpos = off;
			break;
		case 1: /* SEEK_CUR */
			newpos = filp->f_pos + off;
			break;
		case 2: /* SEEK_END */
			newpos = p_info_adc[CURR_MOD_COUNT]->size + off;
			break;
		default: /* can't happen */
			return -EINVAL;
	}
	if (newpos < 0) return -EINVAL;
	filp->f_pos = newpos;
	return newpos;

}

static int pci9030_adc_ioctl(struct inode *node,struct file *flip,unsigned int cmd,unsigned long count)
{
	switch(cmd)
	{
		case 0:
						
		case 1:

		case 2:

		break; 

		default:
			return 0;
	}
	return 0;
}
static int pci9030_adc_open(struct inode *node,struct file *flip)
{

	Find_device(node);
	//printk(KERN_INFO"pci9030_adc: open Character Device with base_address=%lx\n",p_info_adc[CURR_MOD_COUNT]->local_base_add);
	
	return 0;
}

static int pci9030_adc_release(struct inode *node,struct file *flip)
{
	//free_irq((*p_info_adc[CURR_MOD_COUNT]->irq_no), NULL);
	//printk(KERN_INFO "pci9030_adc: close Character Device\n");
	return 0;
}

static struct file_operations pci9030_fops=
{
	.owner 	= 	THIS_MODULE,
	.read	=	pci9030_adc_read,
	.write	=	pci9030_adc_write,
	.unlocked_ioctl	=	pci9030_adc_ioctl,
	.open	=	pci9030_adc_open,
	.release=	pci9030_adc_release,
	.llseek	=	pci9030_adc_llseek,
};



static int  pci9030_adc_probe(struct pci_dev *pdev,const struct pci_device_id *pci9030_table_id)
{
	
	unsigned long start_add=0;
	int ret=0,sz;
	//u16 sdat=0;
	int MAJOR_NUM=0;
	char * cstr;
			
	cstr=(char *)kmalloc(sizeof(char)*64,GFP_KERNEL);
	
	p_info_adc[USE_MOD_COUNT]=(struct pci9030_adc_info *)kmalloc(sizeof(struct pci9030_adc_info),GFP_KERNEL);
	
	if (!p_info_adc[USE_MOD_COUNT] || !cstr)
              return -ENOMEM;

	ret=pci_enable_device(pdev);
	if(ret)
	{
		printk(KERN_ERR "pci9030_adc: not able to enable device %d\n", ret);
		kfree (p_info_adc[USE_MOD_COUNT]);
		return -ENODEV;

	}
	else
		printk(KERN_WARNING "pci9030_adc: Sucessfully Enbale PCI Device\n");
	ret=pci_request_regions(pdev, DRIVER_NAME);
	if(ret)
	{
		printk(KERN_ERR "pci9030_adc: invalid requested region %d\n", ret);
		pci_disable_device(pdev);
		return -ENODEV;

	}
	else
		printk(KERN_WARNING "pci9030_adc: Sucessfully requested region of PCI Device\n");
	
	start_add=pci_resource_start(pdev,0);
	sz=pci_resource_len(pdev,0);
	p_info_adc[USE_MOD_COUNT]->config_base_add=(unsigned long )ioremap_nocache(start_add,sz);
	if(!p_info_adc[USE_MOD_COUNT]->config_base_add)
		{

			pci_release_regions(pdev);
			return -ENODEV;
		}
	//p_info_adc[USE_MOD_COUNT]->io_base=pci_resource_start(pdev,1);
	start_add=pci_resource_start(pdev,2);
	
	if(!start_add)
	{
		printk(KERN_ERR "pci9030_adc: invalid start Address %d\n", ret);
		pci_release_regions(pdev);
		return -ENODEV;

	}
	else
		printk(KERN_WARNING "pci9030_adc: Sucessfully get start Address of PCI Device %ld\n",start_add);

	p_info_adc[USE_MOD_COUNT]->resource_flag	=	pci_resource_flags(pdev,2);
	
	p_info_adc[USE_MOD_COUNT]->size		=	pci_resource_len(pdev,2);

	if(p_info_adc[USE_MOD_COUNT]->resource_flag & IORESOURCE_MEM)
	{
		p_info_adc[USE_MOD_COUNT]->local_base_add	= 	(unsigned long )ioremap_nocache(start_add,p_info_adc[USE_MOD_COUNT]->size);
		if(!p_info_adc[USE_MOD_COUNT]->local_base_add)
		{
			pci_release_regions(pdev);
			return -ENODEV;

		}
	}
	else
	{
		p_info_adc[USE_MOD_COUNT]->local_base_add	=	start_add;
	
	}
		
	
	printk(KERN_WARNING "pci9030_adc: Sucessfully get start Address of PCI Device config_base=0x%lx local_base=0x%lx and Size=0x%lx\n",p_info_adc[USE_MOD_COUNT]->config_base_add,p_info_adc[USE_MOD_COUNT]->local_base_add,(p_info_adc[USE_MOD_COUNT]->local_base_add+p_info_adc[USE_MOD_COUNT]->size-1));

	
	
	if(PCI_SLOT(pdev->devfn) == 12)
	{
		ADC_COUNT = 1;
	}
	else if(PCI_SLOT(pdev->devfn) == 14)
	{
		ADC_COUNT = 2;
	}
	else
	{
		printk(KERN_INFO"ADC Card Inserted In Wrong Slot...Slot No=%d\n",PCI_SLOT(pdev->devfn));
		pci_release_regions(pdev);
		return -ENODEV;

	}
	
	snprintf(cstr,64,"pci9030_ADC%d",ADC_COUNT);
	p_info_adc[USE_MOD_COUNT]->driver_name=cstr;
	p_info_adc[USE_MOD_COUNT]->BUS_WIDTH=16;
	if (MAJOR_NUM) 
	{
    		dev[USE_MOD_COUNT] = MKDEV(MAJOR_NUM, 0);
    		ret  = register_chrdev_region(dev[USE_MOD_COUNT], 1, p_info_adc[USE_MOD_COUNT]->driver_name);
	} 
	else 
	{
    		ret = alloc_chrdev_region(&dev[USE_MOD_COUNT], 0, 1,p_info_adc[USE_MOD_COUNT]->driver_name);
		MAJOR_NUM = MAJOR(dev[USE_MOD_COUNT]);
		p_info_adc[USE_MOD_COUNT]->mj=MAJOR_NUM;	
	}
	if (ret < 0) 
	{
    		printk(KERN_WARNING "pci9030_adc: can't get major %d\n", MAJOR_NUM);
    		iounmap(&p_info_adc[USE_MOD_COUNT]->local_base_add);
    		return -ENODEV;

	}
	else
		printk(KERN_WARNING "pci9030_adc: get major %d\n", MAJOR_NUM);

	cdev_init(&pci9030_adc_cdev[USE_MOD_COUNT], &pci9030_fops);

	ret = cdev_add(&pci9030_adc_cdev[USE_MOD_COUNT], dev[USE_MOD_COUNT], 1);

	if(ret < 0)
	{
		printk(KERN_WARNING "pci9030_adc: can't get add %d\n", ret);
		unregister_chrdev_region(dev[USE_MOD_COUNT],1);
		return -ENODEV;

	}
	printk(KERN_WARNING "pci9030_adc: Sucessfully Add Char Device\n");
	 //devfs_mk_dir("pci9030_adc");
	device_create(pci9030_adc_class,NULL,dev[USE_MOD_COUNT],NULL,p_info_adc[USE_MOD_COUNT]->driver_name);
	p_info_adc[USE_MOD_COUNT]->pdev=pdev;
	p_info_adc[USE_MOD_COUNT]->MOD_COUNT=USE_MOD_COUNT;
	p_info_adc[USE_MOD_COUNT]->sem=(struct semaphore *)kmalloc(sizeof(struct semaphore),GFP_KERNEL);
	
	sema_init(p_info_adc[USE_MOD_COUNT]->sem,1);
	USE_MOD_COUNT++;
	return 0;

}

static void pci9030_adc_disconnect(struct pci_dev *pdev)
{


	//unregister_chrdev(MAJOR_NUM,"char_pci9030_drv");
	printk( KERN_DEBUG "ADC disconnect\n" );
}



static void Find_device(struct inode *node)
{
	int i=0;
	int majNum=MAJOR(node->i_rdev);
	//printk(KERN_INFO"major Nos = %d & %d\n",major,p_info_adc[i]->mj);
	for(i=0;i<USE_MOD_COUNT;i++)
	{		
			if(p_info_adc[i]->mj == majNum)
			{
				CURR_MOD_COUNT=p_info_adc[i]->MOD_COUNT;
			}
		
	}
	
	//printk(KERN_INFO"Use cout=%d Current Count=%d Mod count= %d\n",USE_MOD_COUNT,CURR_MOD_COUNT,p_info_adc[i]->MOD_COUNT);
		
}
static struct pci_driver pci9030_driver=
{
	.name		=	DRIVER_NAME,
	.probe		=	pci9030_adc_probe,
	.remove		=	pci9030_adc_disconnect,
	.id_table	=	pci9030_table_id,
	//.suspend	=	pci9030_suspend,
	//.resume	=	pci9030_resume,
};

MODULE_DESCRIPTION("PLX 9030 Driver");
MODULE_AUTHOR("root (bvmhatre.tatapowersed.com)");
MODULE_LICENSE("GPL");

static int __init plx9030_init_module(void)
{
	pci9030_adc_class = class_create(THIS_MODULE,"pci9030_adc");
	return pci_register_driver(&pci9030_driver);
}

static void __exit plx9030_exit_module(void)
{
	
	int i=0;
	for(i=0;i<USE_MOD_COUNT;i++)
	{
		
		
	if(p_info_adc[CURR_MOD_COUNT]->resource_flag & IORESOURCE_MEM)
		iounmap(&p_info_adc[i]->local_base_add);

	pci_release_regions(p_info_adc[i]->pdev);

	pci_disable_device(p_info_adc[i]->pdev);

	cdev_del(&pci9030_adc_cdev[i]);

	unregister_chrdev_region(dev[i],1);	

	kfree (p_info_adc[i]);
	
		device_destroy(pci9030_adc_class,dev[i]);
	}
	class_destroy(pci9030_adc_class);
	pci_unregister_driver(&pci9030_driver);
	printk( KERN_DEBUG "Module PLX9030 exit\n" );
}

module_init(plx9030_init_module);
module_exit(plx9030_exit_module);
