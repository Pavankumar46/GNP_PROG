#include<stdio.h>
int reverse(int,int);
main()
{
	int r,num,s=0;
	printf("enter the number\n");
	scanf("%d",&num);
	r=reverse(num,s);
	printf("reverse of %d is %d\n",num,r);
	r=reverse(num,s);
	printf("reverse of %d is %d\n",num,r);
}
int reverse(int n,int s)
{
	int r;
	if(n)
	{
		r=n%10;
		s=s*10+r;
		return reverse(n/10,s);
	}
	else
		return s;

}
