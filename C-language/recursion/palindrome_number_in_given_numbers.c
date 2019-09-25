#include<stdio.h>
void pal(int,int);
main()
{
	int num,i=0;
	printf("enter the number\n");
	scanf("%d",&num);
	pal(num,i);
	printf("\n");
}
void pal(int n,int i)
{
	int s,t;
	if(i<n)
	{
		t=i;
		for(s=0;t;t/=10)
			s=s*10+t%10;
		if(s==i)
			printf("%d ",s);
		pal(n,i+1);
	}
}
