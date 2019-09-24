#include<stdio.h>
main()
{
int i,n;
printf("enter the number\n");
scanf("%d",&n);
i=n>>31&1;
if(i==1)
printf("negative number\n");
else
printf("positive number\n");
}
