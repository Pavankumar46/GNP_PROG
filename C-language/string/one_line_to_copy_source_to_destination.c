#include<stdio.h>
main()
{
char b[5],a[]="pavan";
char *p,*q;
q=a;
p=b;
while(*p++=*q++);
printf("%s",b);
}
