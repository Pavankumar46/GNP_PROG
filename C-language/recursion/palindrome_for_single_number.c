#include<stdio.h>
int pal(int,int);
main()
{
	int num,b=0;
	printf("enter the number\n");
	scanf("%d",&num);
	if(num==pal(num,b))
		printf("palindrome nuber\n");
	else
		printf("not palindrome\n");
	printf("\n");
	if(num==pal(num,b))
		printf("palindrome nuber\n");
	else
		printf("not palindrome\n");
	printf("\n");
}
int pal(int n,int b)
{
	int a=0;
	if(n)
	{	a=n%10;
		b=b*10+a;		
		pal(n/10,b);
	}
	else
		return b;
}
