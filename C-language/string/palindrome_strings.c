#include<stdio.h>
main()
{
	char s[10],b[10],ch;
	int i,j;
	printf("enter the string\n");
	scanf("%s",s);
	for(i=0;s[i];i++)
		b[i]=s[i];
		b[i]=s[i];
	for(j=0;b[j];j++);
	for(i=0,j=j-1;i<j;i++,j--)
	{
		ch=b[i];
		b[i]=b[j];
		b[j]=ch;
	}
	printf("%s\n",b);
	for(i=0;s[i];i++)
	{
		if(s[i]!=b[i])
			break;
	} 
	if(s[i]==b[i])
		printf("palindrome\n");
	else
		printf("not palindrome\n");
}
