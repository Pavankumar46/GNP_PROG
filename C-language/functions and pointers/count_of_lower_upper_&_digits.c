#include<stdio.h>
void count(char *);
main()
{
	char a[100];
	printf("enter the string\n");
	scanf("%s",a);
	count(a);
}
void count(char *p)
{
	int i,j,k,c=0,q=0,r=0,s=0;
	for(i=0;p[i];i++)
	{
		if(p[i]>='A'&&p[i]<='Z')
			c++;
		else if(p[i]>='a'&&p[i]<='z')
			q++;
		else if(p[i]>='0'&&p[i]<='9')
			r++;
		else
			s++;
	}
	printf("upper=%d, lower=%d, digits=%d, char=%d\n",c,q,r,s);
}
