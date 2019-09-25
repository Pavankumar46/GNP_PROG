#include<stdio.h>
int min(int a[],int ,int);
main()
{
	int i,r,a[5],ele;
	ele=sizeof a/sizeof a[0];
	printf("enter the elements\n");
	for(i=0;i<ele;i++)
	{
		scanf("%d",&a[i]);
	}
	r=min(a,ele,a[0]);
	printf("min number is %d\n",r);
}
int min(int *p,int n,int m)
{
	if(n>0)
	{
		if(*p<m)
			m=*p;
		return min(p+1,n-1,m);
	}
	else
		return m;
}
