#include<stdio.h>
main()
{
int k,s,i,j,n;
printf("enter the number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
k=i;
for(s=0,j=k;k!=0;k/=10)
{
s=s*10+k%10;
}
if(s==i)
printf("%d ",s);
}
printf("\n");
}
