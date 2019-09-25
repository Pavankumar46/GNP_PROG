#include<stdio.h>
main(int argc,char *argv[])
{
	int a,b,c;
	if(argc<4||argc>5)
		printf("usage\n");
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	c=atoi(argv[3]);
	if(a<0||b<0||c<0)
	{
		printf("enter +ve values in arguments\n");
		return 1;
	}
	if(!(a!=b&&b!=c&&c!=a))
	{
		printf("enter different numbers\n");
		return 1;
	}
	if(a>b&&a>c)
		printf("a is big\n");
	else if(b>c&&b>a)
		printf("b is big\n");
	else
		printf("c is big\n");
}
