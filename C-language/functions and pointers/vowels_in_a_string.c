#include<stdio.h>
void vowels(char *);
main()
{
	char s[10];
	printf("enter the string\n");
	scanf("%s",s);
	vowels(s);
	printf("\n");
}
void vowels(char *p)
{
	while(*p++)
		if(*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u'||*p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U')
			printf("%c ",*p);
}
