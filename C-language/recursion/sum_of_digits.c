#include<stdio.h>
int sumofdigits(int);
main()
{
	int r,num;
	printf("enter the number\n");
	scanf("%d",&num);
	r=sumofdigits(num);
	printf("sum of digits of %d is %d\n",num,r);
}
int sumofdigits(int n)
{
	if(n)
	{
		return n%10+sumofdigits(n/10);
	}
	else
		return 0;
}
