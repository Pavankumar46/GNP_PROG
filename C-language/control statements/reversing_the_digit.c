#include<stdio.h>
main()
{
int i,n,s;
printf("enter the number\n");
scanf("%d",&n);
for(s=0;n!=0;n/=10)
{
s=s*10+n%10;
}
printf("%d\n",s);
}
