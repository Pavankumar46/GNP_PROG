#include<stdio.h>
main()
{
float num;
char *c=&num;
int i,j;
printf("enter the number\n");
scanf("%f",&num);
c=c+3;
for(i=1;i<=4;i++)
{
 for(j=7;j>=0;j--)
 {
 printf("%d",(*c)>>j&1);
}
printf(" ");
c--;
}
printf("\n");
}
