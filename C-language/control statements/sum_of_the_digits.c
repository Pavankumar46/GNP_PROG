#include<stdio.h>
main()
{
int s,i,n;
printf("enter the number\n");
scanf("%d",&n);
for(s=0;n!=0;n/=10)
{
s=s+n%10;
}
printf("%d is the sum of the digits of the %d\n",s,n);
}
