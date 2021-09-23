#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>

#include"cdev_dynamic.h"

int main()
{
	int fd,i;
	char my_buf[4000];
	
	unsigned int size;
	char c;
	
	for(i=0;i<4000;i++)
	{
		my_buf[i]='*';
	}
	printf("[%d]- opening device gnp\n",getpid());
	fd=open("/dev/gnp",O_RDWR);
	if(fd<0)
	{
		printf("\n\nDEvice could not be opened\n\n");
		return 1;
	}
	printf("device opened with ID [%d]\n",fd);
	write(fd,my_buf,4000);
	
	bzero(my_buf,4000);
	read(fd,my_buf,70);
	printf("I read this from the device \n%s \n",my_buf);
	bzero(my_buf,4000);
	write(fd,"gnp_pavan_akhil",16);
	read(fd,my_buf,70);
	printf("I read this from the device \n%s\n",my_buf);
	ioctl(fd,VEDA_GET_SIZE,&size);
	printf("present size of the buffer is %d\n",size);
	size = 4096;
	printf("new size of the buffer is %d\n",my_buf);
	bzero(my_buf,4000);
	read(fd,my_buf,70);
	print("current contents\n%s\nfilling=%s\n",my_buf);
	c='=';
	ioctl(fd,VEDA_FILL_CHAR,&c);
	bzero(my_buf,4000);
	read(fd,my_buf,70);
	printf("new contents\n%s\n",my_buf);
	
	close(fd);
}
	
	
	
	
	
	
	
	
