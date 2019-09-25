#include<stdio.h>
void prime(int,int);
main()
{
	int count,i;
	printf("enter the count\n");
	scanf("%d",&count);
	printf("enter the starting number\n");
	scanf("%d",&i);
	prime(count,i);
	printf("\n");
	prime(count,i);
	printf("\n");
}
void prime(int c,int n)
{
	int i;
	if(c)
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)
				break;
		}
		if(n==i)
		{
			printf("%d ",n);
			prime(c-1,n+1);
		}
		else
			prime(c,n+1);
	}
}
