#include<stdio.h>
void reverse(char *);
main()
{
	char s[10];
	printf("enter the string\n");
	scanf("%s",s);
	reverse(s);
	printf("%s",s);
	printf("\n");
}
void reverse(char *p)
{
	char *q=p,ch;
	while(*q)
		q++;
	q--;
	while(p<q)
	{
		ch=*p;
		*p=*q;
		*q=ch;
		p++;q--;
	}
}
