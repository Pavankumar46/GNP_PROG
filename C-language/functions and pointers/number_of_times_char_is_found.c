#include<stdio.h>
int times(const char *,char);
main()
{
	char s[10],c,ch;
	printf("enter the string\n");
	scanf("%s",s);
	printf("enter the char\n");
	scanf(" %c",&ch);
	c=times(s,ch);
	printf("%d\n",c);
}
int times(const char *p,char ch)
{
	int c=0;
	while(*p++)
		if(*p==ch)
			c++;
	return c;
}
