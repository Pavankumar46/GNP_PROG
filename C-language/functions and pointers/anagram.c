#include<stdio.h>
int anag(char *,char *);
void upper(char *);
main()
{
	char a[50],b[50];int r,s;
	printf("enter the stiring\n");
	scanf("%[^\n]",a);
	printf("%s\n",a);
	printf("enter the stiring\n");
	scanf(" %[^\n]",b);
	printf("%s\n",b);
	upper(a);
	upper(b);
	r=anag(a,b);
	s=anag(b,a);
	if(r==s)
		printf("anagram\n");
	else
		printf("not anagram\n");
}
void upper(char *p)
{
	int i;
	for(i=0;p[i];i++)
		if(p[i]>='a'&&p[i]<='z')
			p[i]-=32;
}
int anag(char *p,char *q)
{
	int c,i,j,r;
	for(i=0;p[i];i++)
	{
		if(p[i]>='A'&&p[i]<='Z')
		{
			c=0;
			r=p[i];		
			for(j=0;p[j];j++)
				if(p[j]==r)
					c++;
			for(j=0;q[j];j++)
				if(q[j]==r)
					c--;
			if(c!=0)
			{
			return 0;
			break;
			}
		}
	}
if(c==0)
return 1;
}
