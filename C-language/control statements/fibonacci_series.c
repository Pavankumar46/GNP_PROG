#include<stdio.h>
main()
{
	int n,i,a=0,b=1,c;
	printf("enter the number\n");
	scanf("%d",&n);
	printf("%d %d ",a,b);
	for(i=1;i;i++)
	{
		c=a+b;
		a=b;
		b=c;
		if(c<=n)
			printf("%d ",c);
		else
			break;
	}
	printf("\n");
}
