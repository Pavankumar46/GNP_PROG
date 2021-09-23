#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/stat.h>


extern void func(void);

int init_mod(void)
{
	printk("module inserted\n");
	func();
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

