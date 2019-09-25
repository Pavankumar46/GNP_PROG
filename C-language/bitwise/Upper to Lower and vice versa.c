#include<stdio.h>
main()
{
	char ch;
	printf("enter the char\n");
	scanf("%c",&ch);
	if(ch>='a'&&ch<='b')
	{
		ch=ch&~32;
		printf("%c",ch);
	}else
	{
		ch=ch|32;
		printf("%c",ch);
	}
}
