#include<stdio.h>
main()
{
int n,q,s,i,j;
printf("enter the number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
q=i;
s=0;
 for(j=1;j<q;j++)
 {
  if(q%j==0)
  s+=j;
 }
if(s==i)
 printf("%d ",s);
}
printf("\n");
}
