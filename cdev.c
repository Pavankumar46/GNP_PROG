#include<linux/module.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/slab.h>

#define MAJORNO 200
#define MINORNO  0
#define CHAR_DEV_NAME "gnp"
#define MAX_LENGTH 4000
#define SUCCESS 0

static char char_device_buf[MAX_LENGTH];
struct cdev *gnp_cdev;
dev_t mydev;
int count=1,inuse=0;

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

static struct file_operations char_dev_fops =
{
	.owner = THIS_MODULE,
	.read  = char_dev_read,
	.write = char_dev_write,
	.open  = char_dev_open,
	.release = char_dev_release,
};

static int __init char_dev_init(void)
{
	int ret;
	mydev = MKDEV(MAJORNO,MINORNO);
	register_chrdev_region(mydev,count,CHAR_DEV_NAME);
	
	gnp_cdev=cdev_alloc();
	cdev_init(gnp_cdev,&char_dev_fops);
	
	ret=cdev_add(gnp_cdev,mydev,count);
	if(ret<0)
	{
		printk("Error registering device drivers\n");
		return ret;
	}
	printk(KERN_INFO"\n Device Registered %s\n",CHAR_DEV_NAME);
	memset(char_device_buf,'\0',MAX_LENGTH);
	return 0;
}

static void __exit char_dev_exit(void)
{
	cdev_del(gnp_cdev);
	unregister_chrdev_region(mydev,1);
	printk(KERN_INFO"\n Driver Unregistered\n");
}

module_init(char_dev_init);
module_exit(char_dev_exit);
MODULE_LICENSE("GPL");		
