#include<stdio.h>
void sub(char *,char *,int,int);
main()
{
	char a[100],b[50];int i,j;
	printf("enter the string\n");
	scanf("%[^\n]",a);
	for(i=0;a[i];i++);
	printf("enter the sub string\n");
	scanf("%s",b);
	for(j=0;b[j];j++);
	sub(a,b,i,j);
}
void sub(char *p,char *q,int i,int j)
{
	int k=0,l;
	int count,count1=0;
	for(k=0;k<i;)
	{
		l=0;
		count=0;
		while(p[k]==q[l])
		{
			count++;
			k++;
			l++;
		}
		if(count==j)
		{
			count1++;
			count=0;
		}
		else
			k++;
	}
	printf("%d\n",count1);
}
