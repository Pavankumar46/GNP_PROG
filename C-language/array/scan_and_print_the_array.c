#include<stdio.h>
main()
{
int ele,i,a[5];
ele=sizeof (a)/sizeof a[0];
for(i=0;i<ele;i++)
printf("%p\n",&a[i]);
printf("enter the elements\n");
for(i=0;i<ele;i++)
scanf("%d",&a[i]);
printf("\n");
for(i=0;i<ele;i++)
printf("%d ",a[i]);
printf("\n");
}
