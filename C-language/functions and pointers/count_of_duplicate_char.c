#include<stdio.h>
void coudup(char *);
main()
{
	char a[100];
	printf("enter the string\n");
	scanf("%[^\n]",a);
	coudup(a);
}
void coudup(char *p)
{
	int i,j,k,c;
	for(i=0;p[i];i++)
	{
		c=1;
		for(j=i+1;p[j];j++)
		{
			if(p[i]==p[j])
			{
				c++;
				for(k=j;p[k];k++)
					p[k]=p[k+1];
				j--;
			}
		}
	if(c>1)
	printf("%c--%d\n",p[i],c);
}
}
