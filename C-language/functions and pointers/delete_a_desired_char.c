#include<stdio.h>
int words(char *,char );
main()
{
	char s[10],ch;int i;
	printf("enter the string\n");
	scanf("%s",s);
	printf("enter the char\n");
	scanf(" %c",&ch);
	for(i=0;s[i];i++);
	words(s,ch);
	printf("%s\n",s);
}
int words(char *p,char ch)
{
	int i,j;
	for(i=0;p[i];i++)
	{
		if(p[i]==ch)
		{
			for(j=i;p[j];j++)
				p[j]=p[j+1];
			i--;
		}

	}
}
