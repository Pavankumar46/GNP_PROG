#include<stdio.h>
void sort(char *,int);
main()
{
	char a[100];int i;
	printf("enter the string\n");
	scanf("%s",a);
	for(i=0;a[i];i++);
		sort(a,i);
	printf("%s\n",a);
}
void sort(char *p,int l)
{
	int i,j;char t;
	for(i=0;i<l;i++)
	{
		for(j=0;j<l-1-i;j++)
		{
			if(p[j]>p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
