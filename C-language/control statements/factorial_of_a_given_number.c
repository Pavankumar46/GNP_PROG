#include<stdio.h>
main()
{
int i,r=1,n;
printf("enter the number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 r=r*i;
}
printf("%d is the factorial of %d\n",r,n);
}
