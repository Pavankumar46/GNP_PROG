#include<stdio.h>
void lower(char *,char,char);
void upper(char *,char,char);
main()
{
	char s[100];
	printf("enter the string\n");
	scanf("%s",s);
	lower(s,'a','z');
	printf("%s\n",s);
	upper(s,'A','Z');
	printf("%s\n",s);
}
void lower(char *p,char ch,char ch1)
{
	int i;
	while(*p)
	{
		if(*p>=ch&&*p<=ch1)
			*p-=32;
		p++;
	}
}
void upper(char *p,char ch,char ch1)
{
	int i;
	while(*p)
	{
		if(*p>=ch&&*p<=ch1)
			*p+=32;
		p++;
	}
}
