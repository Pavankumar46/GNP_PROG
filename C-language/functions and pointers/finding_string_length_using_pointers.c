#include<stdio.h>
int length(char *);
main()
{
	char s[10];int l;
	printf("enter the num\n");
	scanf("%s",s);
	l=length(s);
	printf("%d\n",l);
}
int length(char *p)
{
	int c=0;
	while(*p++)
		c++;
	return c;
}
