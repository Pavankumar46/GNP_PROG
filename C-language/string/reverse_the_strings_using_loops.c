#include<stdio.h>
main()
{
char temp,a[]="pavan";
int i,j;
for(j=0;a[j];j++);
for(i=0,j=j-1;i<j;i++,j--)
{
 temp=a[i];
 a[i]=a[j];
 a[j]=temp;
}
printf("%s\n",a);
}
