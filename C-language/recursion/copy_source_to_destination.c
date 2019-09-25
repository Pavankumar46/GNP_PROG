#include<stdio.h>
void copy(char *,char *);
main()
{
	char s[100],d[100];
	printf("enter the s\n");
	scanf("%s",s);
	copy(s,d);
	printf("%s",d);
	printf("\n");
}
void copy(char *p,char *q)
{
	if(*p)
	{
		*q=*p;
		copy(p+1,q+1);
	}
	else
		*q='\0';
}
