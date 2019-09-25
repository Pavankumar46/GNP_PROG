#include<stdio.h>
main(int argc,char *argv[])
{
	int i,n;
	if(argc!=2)
		printf("enter one number\n");
	else
	{
		n=atoi(argv[1]);
			for(i=2;i<n;i++)
			{
				if(n%i==0)
					break;
			}
	if(i==n)
		printf("prime number\n");
	else
		printf("not prime\n");
	}
}
