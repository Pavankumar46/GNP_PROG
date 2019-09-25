#include<stdio.h>
main()
{
char a[10],b[10];
int i;
printf("enter the strings\n");
scanf("%s%s",a,b);
printf("%s %s\n",a,b);
for(i=0;a[i];i++)
if(a[i]!=b[i])
break;
if(a[i]==b[i])
printf("same\n");
else
printf("diff\n");
}
