#include<stdio.h>
void copy(char *,char *);
main()
{
	char a[10],b[10];
	printf("enter the string\n");
	scanf("%s",a);
	copy(a,b);
	printf("%s\n",b);
}
void copy(char *p,char *q)
{
	int i;
	while(*q++=*p++);
}
