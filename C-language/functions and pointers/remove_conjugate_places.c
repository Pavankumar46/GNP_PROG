#include<stdio.h>
void place(char *,char *);
main()
{
	char a[100],b[100];
	printf("enter the string\n");
	scanf("%[^\n]",a);
	place(a,b);
	printf("%s\n",b);
}
void place(char *p,char *q)
{
	int i,j,s,k,m,l;
	for(l=0;p[l];l++);
	for(s=0;p[s]==' ';s++);
	for(k=0,m=s;m<l;k++,m++)
		q[k]=p[m];
	q[k]='\0';
	for(i=0;q[i];i++)
	{
		if(q[i]==' '&&q[i+1]==' ')
		{
			for(j=i+1;q[j];j++)
				q[j]=q[j+1];
			i--;
		}
	}
}
