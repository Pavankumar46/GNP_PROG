#include<stdio.h>
int fact(int);
main()
{
	int num,r;
	printf("enter the number\n");
	scanf("%d",&num);
	r=fact(num);
	printf("factorial of %d is %d\n",num,r);
}
int fact(int n)
{
	if(n)
	{
		return n*fact(n-1);
	}
	else
		return 1;
}
