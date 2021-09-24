#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>

int main()
{
	int fd,i;
	ssize_t ret;
	char my_buf[4000];
	for(i=0;i<4000;i++)
	{
		my_buf[i] = '*';
	}
	printf("[%d] -> opening device gnp_dev\n",getpid());
	fd =open("/dev/gnp",O_RDWR);
	if(fd == -1)
	{
		printf("open failed\n");
	}

	printf("PID [%d]\n",getpid());
	//getchar();
	printf("gnp\n");
	ret = write(fd,my_buf,4000);
	if(ret == -1)
	{
		printf("gnp1\n");
	}
	else
	{
		printf("else\n");
	}
	close(fd);
}


