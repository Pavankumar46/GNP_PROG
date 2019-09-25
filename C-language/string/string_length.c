#include<stdio.h>
main()
{
char s[]="pavan";
char *p=s;
int i;
for(i=0;*p;i++,p++);
printf("%d",i);
}
