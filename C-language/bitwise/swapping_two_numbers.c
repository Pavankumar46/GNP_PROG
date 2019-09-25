#include<stdio.h>
main()
{
int i,j;
printf("enter the values of i and j\n");
scanf("%d %d",&i,&j);
i=i^j;
j=i^j;
i=i^j;
printf("%d %d",i,j);
}
