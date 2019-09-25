#include<stdio.h>
void arrreverse(int *,int,int);
main()
{
	int a[5],i,k=0,ele;
	ele=sizeof a/sizeof a[0];
	printf("enter the elements\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");
	arrreverse(a,ele-1,k);
	printf("after reversing\n");
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void arrreverse(int *p,int j,int i)
{
	int k,t;
	if(i<j)
	{
		t=p[i];
		p[i]=p[j];
		p[j]=t;
		arrreverse(p,j-1,i+1);
	}
}
