#include<stdio.h>
main()
{
int t,ele,a[10],i,j;
ele=sizeof a/sizeof a[0];
printf("enter the elements\n");
for(i=0;i<ele;i++)
scanf("%d",&a[i]);
for(i=0,j=1;i<ele-1 && j<ele;i+=2,j+=2)
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
for(i=0;i<ele;i++)
printf("%d ",a[i]);
printf("\n");
}
