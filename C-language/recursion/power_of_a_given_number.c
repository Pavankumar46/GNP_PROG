#include<stdio.h>
int power(int ,int);
main()
{
	int a,b,r;
	printf("emter a and b\n");
	scanf("%d%d",&a,&b);
	r=power(a,b);
	printf("%d\n",r);
}
int power(int a,int n)
{
	if(n==0)
		return 1;
	else if(n%2==0)
		return power(a*a,n/2);
	else
		return a*power(a*a,(n-1)/2);
}
