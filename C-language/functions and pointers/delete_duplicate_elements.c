#include<stdio.h>
void del(char *);
main()
{
	char a[100];
	printf("enter the string\n");
	scanf("%s",a);
	del(a);
	printf("%s\n",a);
}
void del(char *p)
{
	int k,i,j;
	for(i=0;p[i];i++)
	{
		for(j=i+1;p[j];j++)
		{
			if(p[i]==p[j])
			{
				for(k=j;p[k];k++)
					p[k]=p[k+1];
				j--;
			}
		}
	}
}
