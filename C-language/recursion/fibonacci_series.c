#include<stdio.h>
int fib(int);
main()
{
	int n=0,c,count;
	printf("enter the n\n");
	scanf("%d",&count);
	for(c=0;c<count;c++)
	{
		printf("%d ",fib(n));
		n++;
	}
	printf("\n");
}
int fib(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else 
		return (fib(n-1)+fib(n-2));
}
