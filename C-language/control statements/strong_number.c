#include<stdio.h>
main()
{
int n1,n,j,s,k,r=1;
printf("enter the number\n");
scanf("%d",&n1);
n=n1;
for(s=0;n>0;n/=10)
{
 r=n%10;
  for(j=r-1;j>0;j--)
  r=r*j;
s+=r;
}
if(s==n1)
printf("%d is strong number\n",n1);
else
printf("%d is not strong number\n",n1);
}
