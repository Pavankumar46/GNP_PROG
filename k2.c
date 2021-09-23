#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/stat.h>

void func(void);

/*allocating data at compile time */
static int val=0;  

module_param(val,int,S_IRUGO);//read only
//module_param(val,int,S_IRUGO|S_TWUSR);//read and write
MODULE_PARM_DESC(val,"INITIALISE ME AT INSERTION TIME");
EXPORT_SYMBOL(func);
void func()
{
	printk("func invoked\n");
	printk("val = %d\n",val);
}

int init_mod(void)
{
	printk("module inserted\n");
	return 0;
}

void cleanup_mod(void)
{
	printk("modules removed\n");
}

module_init(init_mod);
module_exit(cleanup_mod);

/*kernal module comments*/
MODULE_AUTHOR("PAVAN");
MODULE_DESCRIPTION("INSERT & REMOVE MODULE");
MODULE_LICENSE("GPL");

