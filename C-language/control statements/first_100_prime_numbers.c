#include<stdio.h>
main()
{
int n,i,j,c=0;
printf("enter how many prime numbers needed\n");
scanf("%d",&n);
for(j=1;c<=n;j++)
{
for(i=2;i<j;i++)
{
if(j%i==0)
break;
}
if(j==i)
{
printf("%d ",j);
c++;
}
}
}
