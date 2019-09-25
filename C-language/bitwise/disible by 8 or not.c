#include<stdio.h>
main()
{
int n;
printf("enter the number\n");
scanf("%d",&n);
if(((n>>3)<<3)==n)
printf("%d is divisible by 8\n",n);
else
printf("%d is not divisible by 8\n",n);
}
