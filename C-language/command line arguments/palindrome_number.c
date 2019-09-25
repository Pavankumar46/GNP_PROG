#include<stdio.h>
main(int argc,char *argv[])
{
	int r,s,n;
	if(argc!=2)
		printf("enter one number\n");
	else
	{
		r=atoi(argv[1]);
		n=r;
		for(s=0;n;n/=10)
			s=s*10+n%10;
		if(s==r)
			printf("pal\n");
		else
			printf("not pal\n");
	}
}
