#include<stdio.h>
main()
{
int ele,a[10],i,b,c,s,r,l,k;
ele=sizeof a/sizeof a[0];
printf("enter the elements\n");
for(i=0;i<ele;i++)
scanf("%d",&a[i]);
for(i=0;i<ele;i++)
{
b=a[i];
 for(c=0;b!=0;c++)
{ 
b=b/10;
}
b=a[i];
 for(s=0;b!=0;b/=10)
{
  r=b%10;
   for(l=1,k=1;l<=c;l++)
     k=k*r;
  s+=k;
}
if(s==a[i])
{
printf("%d ",s);
}
}
}
