#include<stdio.h>
char *str_chr(char *,char);
void str_rev1(char *,char *);
void str_rev(char *);
main()
{
	char a[50],*p,*q;
	printf("enter the string\n");
	scanf("%[^\n]",a);
	p=a;
	str_rev(p);
	while(q=str_chr(p,' '))
	{
		str_rev1(p,q-1);
		p=q+1;
	}
	str_rev(p);
	printf("%s\n",a);
}
char *str_chr(char *p,char q)
{
	while(*p)
	{
		if(*p==q)
			return p;
		p++;
	}
	return 0;
}
void str_rev1(char *p,char *q)
{
	char ch;
	while(p<q)
	{
		ch=*p;
		*p=*q;
		*q=ch;
		p++;
		q--;
	}
}
void str_rev(char *p)
{
	char *q,ch;
	q=p;
	while(*q)
		q++;
	q--;
	while(p<q)
	{
		ch=*p;
		*p=*q;
		*q=ch;
		p++;
		q--;
	}
}
