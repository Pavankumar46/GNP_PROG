#include<stdio.h>
main()
{
char a[100],b[100];
printf("enter the string\n");
scanf("%s",a);
printf("enter the substring\n");
scanf("%s",b);
int i,j,count,count1=0,l1,l2;
for(l1=0;a[l1];l1++);
for(l2=0;b[l2];l2++);
for(i=0;i<l1;)
{
 j=0;
 count=0;
  while(a[i]==b[j])
  {
   count++;
   j++;
   i++;
  }

  if(count==l2)
  {
   count1++;
   count=0;
  }
  else
   i++;
}
printf("%d\n",count1);
}
