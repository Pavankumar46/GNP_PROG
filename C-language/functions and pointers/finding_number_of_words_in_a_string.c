#include<stdio.h>
int find(char *,char);
main()
{
	char s[100];int r;
	printf("enter the string\n");
	scanf("%[^\n]",s);
	r=find(s,' ');
	printf("%d\n",r);
}
int find(char *p,char ch)
{
	int c=0;
	while(*p)
	{
		if(*p==ch)
			c++;
		p++;
	}
	return c+1;
}
