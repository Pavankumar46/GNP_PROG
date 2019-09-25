#include<stdio.h>
main()
{
int j,ele,t,i,a[10];
ele=sizeof a/sizeof a[0];
printf("enter the number\n");
for(i=0;i<ele;i++)
scanf("%d",&a[i]);
printf("\n");
for(i=0;i<ele;i++)
printf("%d ",a[i]);
printf("\n");
for(i=0,j=ele-1;i<j;i++,j--)
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
for(i=0;i<ele;i++)
printf("%d ",a[i]);
printf("\n");
}
