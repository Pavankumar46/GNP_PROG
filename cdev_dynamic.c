 #include<linux/module.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/sched.h>
#include<linux/errno.h>
#include<asm/current.h>
#include<linux/device.h>

#include"cdev_dynamic.h"
//#include<asm/ioctl.h>

//#define VEDA_MAGIC 'L'
//#define VEDA_FILL_ZERO		_IO(VEDA_MAGIC,1)
//#define VEDA_FILL_CHAR		_IOW(VEDA_MAGIC,2,char)
//#define VEDA_SET_SIZE		_IOW(VEDA_MAGIC,3,uint)
//#define VEDA_GET_SIZE		_IOR(VEDA_MAGIC,4,uint)

//#define VEDA_MAX_CMDS		4


//#define MAJORNO 200
//#define MINORNO  0
#define CHAR_DEV_NAME "gnp"
#define MAX_LENGTH length
#define SUCCESS 0

static char *char_device_buf;
struct cdev *gnp_cdev;
static unsigned int length =4000;
dev_t mydev;
int count=1,inuse=0;
static struct class *gnp_class;

static int char_dev_open(struct inode *node,struct file *file)
{
	if(inuse)
	{
		printk(KERN_INFO"\n Device busy %s\n",CHAR_DEV_NAME);
		return -EBUSY;
	}
	inuse=1;
	return SUCCESS;
}

static int char_dev_release(struct inode *inode, struct file *file)
{
	inuse=0;
	return SUCCESS;
}

static ssize_t char_dev_read(struct file *file,char *buf,size_t lbuf,loff_t *ppos)
{
	int nbytes = lbuf - copy_to_user (buf,char_device_buf+*ppos,lbuf);
	*ppos += nbytes;
	printk(KERN_INFO"\n READING nbytes=%d, pos=%d\n", nbytes,(int)*ppos);
	return nbytes;
}

static ssize_t char_dev_write(struct file *file,const char *buf, size_t lbuf,loff_t *ppos)
{
	int nbytes = lbuf - copy_from_user(char_device_buf + *ppos,buf,lbuf);
	*ppos +=nbytes;
	printk(KERN_INFO"\n WRITING function,nbytes=%d, pos=%d\n", nbytes,(int)*ppos);
	
	return nbytes;
}


static long int char_dev_ioctl(struct file *filp,unsigned int cmd, unsigned long arg)
{
	unsigned int i,size;
	char *new_buf;
	char c;
	int retbytes;
	if(_IOC_TYPE(cmd) != VEDA_MAGIC ) return -ENOTTY;
	if(_IOC_NR(cmd) > VEDA_MAX_CMDS ) return -ENOTTY;
	if(_IOC_DIR(cmd) & _IOC_READ)
		if( !access_ok((void *)arg, _IOC_SIZE(cmd)))
		return -EFAULT;
	if(_IOC_DIR(cmd) & _IOC_WRITE)
		if( !access_ok((void *)arg, _IOC_SIZE(cmd)))
		return -EFAULT;
	switch(cmd)
	{
	case VEDA_FILL_ZERO:
		for(i=0;i<MAX_LENGTH;i++)
		{
			char_device_buf[i]=0;
		}
		break;
	case VEDA_FILL_CHAR:
	retbytes=copy_from_user(&c,(char *)arg,sizeof(char));
	for(i=0 ;i<MAX_LENGTH;i++)
	{
		char_device_buf[i]=c;
	}
	break;
	case VEDA_SET_SIZE:
	retbytes=copy_from_user(&size,(unsigned int*)arg,sizeof(unsigned int));
	new_buf = (char *)kmalloc(size*sizeof(char),GFP_KERNEL);
	if(!new_buf)
	return -ENOSPC;
	kfree(char_device_buf);
	char_device_buf=(char*)new_buf;
	MAX_LENGTH=size;
	for(i=0;i<MAX_LENGTH ;i++)
	char_device_buf[i]=0;
	filp->f_pos=0;
	break;
	case VEDA_GET_SIZE:
	size=MAX_LENGTH;
	retbytes=copy_to_user((unsigned int*)arg,&size,sizeof(unsigned int));
	break;
	}
	return SUCCESS;
}
	
	
static struct file_operations char_dev_fops =
{
	.owner = THIS_MODULE,
	.unlocked_ioctl = char_dev_ioctl,
	.read  = char_dev_read,
	.write = char_dev_write,
	.open  = char_dev_open,
	.release = char_dev_release,
};	
	

static int __init char_dev_init(void)
{
	int ret;
	//mydev = MKDEV(MAJORNO,MINORNO);
	//register_chrdev_region(mydev,count,CHAR_DEV_NAME);
	
	if(alloc_chrdev_region(&mydev, 0, count, CHAR_DEV_NAME)<0)
	{
		printk(KERN_ERR"failed to reserve major/minor range\n");
		return -1;
	}
	
	
	
	if(!(gnp_cdev=cdev_alloc()))
	{
	printk(KERN_ERR"cdev_alloc() failed\n");
	unregister_chrdev_region(mydev,count);
	return -1;
	}
	cdev_init(gnp_cdev,&char_dev_fops);
	
	ret=cdev_add(gnp_cdev,mydev,count);
	if(ret<0)
	{
		printk("Error registering device drivers\n");
		cdev_del(gnp_cdev);
		unregister_chrdev_region(mydev, count);
		return ret;
	}
	gnp_class = class_create(THIS_MODULE, "VIRTUAL");
	device_create(gnp_class,NULL,mydev,NULL,"%s","gnp");
	
	printk(KERN_INFO"\n Device Registered %s\n",CHAR_DEV_NAME);
	printk(KERN_INFO"Major number =%d, Minor number = %d\n",MAJOR (mydev), MINOR (mydev));
	
	char_device_buf=(char*)kmalloc(MAX_LENGTH,GFP_KERNEL);
	
	return 0;
}

static void __exit char_dev_exit(void)
{
	device_destroy (gnp_class, mydev);
	class_destroy(gnp_class);
	cdev_del(gnp_cdev);
	unregister_chrdev_region(mydev,1);
	kfree(char_device_buf);
	printk(KERN_INFO"\n Driver Unregistered\n");
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("GNP");
MODULE_DESCRIPTION("Dynamic node and major number is given");
MODULE_LICENSE("GPL");		
