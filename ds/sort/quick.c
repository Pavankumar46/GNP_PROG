#include<stdio.h>
int partion(int *,int ,int );
void quick(int *,int ,int );
void swap(int *,int *);
main()
{
	int a[]={5,3,6,4,9};
	int ele,i;
	ele=sizeof a/sizeof a[0];
	quick(a,0,ele-1);
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void quick(int *a,int start,int end)
{
	if(start<end)
	{
		int p=partion(a,start,end);
		quick(a,start,p-1);
		quick(a,p+1,end);
	}
}
int partion(int *a,int lb,int ub)
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(a[start]<=pivot && start<end)
		{
			start+=1;
		}
		while(a[end]>pivot)
		{
			end-=1;
		}
		if(start<end)
			swap(&a[start],&a[end]);
	}
	a[lb]=a[end];
	a[end]=pivot;
	return end;
}
void swap(int *p,int *q)
{
	int ch;
	ch=*p;
	*p=*q;
	*q=ch;
}

