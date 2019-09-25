#include<stdio.h>
void ono(char *,char *,char *,int );
main()
{
	char a[10],b[10],c[20];int i,m,d;
	printf("enter first strings\n");
	scanf("%s%s",a,b);
	printf("%s\n",a);
	printf("%s\n",b);
	for(i=0;a[i];i++);
	for(m=0;b[m];m++);
	d=i+m;
	ono(a,b,c,d);
}
void ono(char *a,char *b,char *c,int k)
{int l=0,i,j;
	
	for(i=0,j=0;k>0;i++,j++)
	{
		if(a[i]!='\0')
		{
			c[l]=a[i];
			l++;
			k--;
		}
		if(b[j]!='\0')
		{
			c[l]=b[j];
			l++;
			k--;
		}
		c[l]='\0';
	}
	printf("%s\n",c);
}
