#include<stdio.h>
main()
{
	int i,k=1,n,p,q;
	printf("enter the number and power\n");
	scanf("%d %d",&n,&p);
	for(i=1;i<=p;i++)
	{
		k=k*n;
	}
	printf("%d",k);
	printf("\n");
}
