#include<stdio.h>
int perfect(int);
main()
{
	int r,num;
	printf("enter the number\n");
	scanf("%d",&num);
	r=perfect(num);
	if(r==1)
		printf("perfect number\n");
	else
		printf("not perfect\n");
	r=perfect(num);
	if(r==1)
		printf("perfect number\n");
	else
		printf("not perfect\n");
}
int perfect(int n)
{
	static int i=1,s=0;
	if(i<n)
	{
		if(n%i==0)
		{
			s=s+i;
		}
			i++;
	perfect(n);
	}
	if(n==s)
		return 1;
	else
		return 0;
}
