#ifndef _CDEV_DYNAMIC_H_
#define _CDEV_DYNAMIC_H_

#include<asm/ioctl.h>

#define VEDA_MAGIC 'L'
#define VEDA_FILL_ZERO		_IO(VEDA_MAGIC,1)
#define VEDA_FILL_CHAR		_IOW(VEDA_MAGIC,2,char)
#define VEDA_SET_SIZE		_IOW(VEDA_MAGIC,3,uint)
#define VEDA_GET_SIZE		_IOR(VEDA_MAGIC,4,uint)

#define VEDA_MAX_CMDS		4

#endif
