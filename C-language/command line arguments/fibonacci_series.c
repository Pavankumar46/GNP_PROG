#include<stdio.h>
main(int argc,char *argv[])
{
	int i,n,c,a=0,b=1;
	if(argc!=2)
		printf("enter the count only\n");
	else
	{
		n=atoi(argv[1]);
		printf("%d %d ",a,b);
		for(i=0;i<n-2;i++)
		{
			c=a+b;
			a=b;
			b=c;
			printf("%d ",c);
		}
	
	}
	printf("\n");
}
