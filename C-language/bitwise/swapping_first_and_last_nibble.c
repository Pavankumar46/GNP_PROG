#include<stdio.h>
main()
{
int i,j,m,k,pos,n;
printf("enter the number\n");
scanf("%d",&n);
for(pos=31;pos>=0;pos--)
printf("%d",n>>pos&1);
printf("\n");
for(i=0,j=28;i<=4||j<=31;i++,j++)
{
  m=n>>i&1;
  k=n>>j&1;
  if(m!=k)
{
  n=n^1<<i;
  n=n^1<<j;
}
}
for(pos=31;pos>=0;pos--)
printf("%d",n>>pos&1);
}
