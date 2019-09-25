#include<stdio.h>
void bubble(int *,int);
main()
{
	int n,i;
	printf("enter the number\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	bubble(a,n);
	printf("after sorting\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void bubble(int *p,int num)
{
	int j,i,t;
	j=num;
	if(j>0)
	{
		for(i=0;i<num-1;i++)
		{
			if(p[i]>p[i+1])
			{
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=t;
			}
		}
		return bubble(p,num-1);
	}
	else
		return;
}
