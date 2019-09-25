#include<stdio.h>
int gcdfind(int ,int);
main()
{
	int a,b,gcd,lcm;
	printf("enter the numbers\n");
	scanf("%d%d",&a,&b);
	gcd=gcdfind(a,b);
	printf("gcd of %d & %d is %d\n",a,b,gcd);
	lcm=a*b/gcd;
	printf("lcm of %d & %d is %d\n",a,b,lcm);
}
int gcdfind(int n1,int n2)
{
	if(n2!=0)
		return gcdfind(n2,n1%n2);
	else
		return n1;
}
