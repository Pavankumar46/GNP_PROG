#include<stdio.h>
int divisorsum(int,int );
main()
{
	int num,sum,t=1;
	printf("enter the number\n");
	scanf("%d",&num);
	sum=divisorsum(num,t);
	printf("\nsum of the divisors is %d\n",sum);
	sum=divisorsum(num,t);
	printf("\nsum of the divisors is %d\n",sum);
}
int divisorsum(int n,int t)
{
	if(t<n)
	{
		if(n%t==0)
		{
			printf("%d ",t);
			return t+divisorsum(n,t+1);
		} 
		else
			return divisorsum(n,t+1);
	}
	else
		return 0;
}
