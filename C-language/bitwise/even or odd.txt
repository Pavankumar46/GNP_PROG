#include<stdio.h>
main()
{
int n;
printf("enter the number\n");
scanf("%d",&n);
n=n&1;
if(n==0)
printf("n is even number\n");
else
printf("n is odd number\n");
}
