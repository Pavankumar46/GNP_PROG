#include<stdio.h>
void str_rev1(char *,char *);
void decrypt(char *,int);
main()
{
	char a[100];int n;
	printf("enter the string\n");
	scanf("%[^\n]",a);
	printf("enter the number\n");
	scanf(" %d",&n);
	decrypt(a,n);
	printf("%s\n",a);
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
void decrypt(char *s,int ele)
{
int i,j;
	for(i=0;s[i];i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			j++;
		if(j%ele==0)
		{
			if(*(s+i+1)=='\0')
			goto L1;
			else if(*(s+i)==' ')
			str_rev1(s+i,s+i);
			else if(*(s+i+1)==' ')
			str_rev1(s+i,s+i+1+1);
			else
			str_rev1(s+i,s+i+1);
			L1:;
		}
	}
}
