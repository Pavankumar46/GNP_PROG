#include<stdio.h>
main()
{
int i,j,n,n1;
printf("enter starting and ending table number\n");
scanf("%d %d",&n,&n1);
for(i=n;i<=n1;i++)
{
 for(j=1;j<=10;j++)
  {
   printf("%d*%d=%d \n",i,j,i*j);
  }
printf("\n");
}
printf("\n");
}
