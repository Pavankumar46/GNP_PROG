#include<stdio.h>
main()
{
	int i,j,k,l=0;
	char c[20],a[10],b[10];
	printf("enter the strings\n");
	scanf("%s%s",a,b);
	for(i=0;a[i];i++);
	for(j=0;b[j];j++);
	k=i+j;	
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
	}c[l]='\0';
	printf("%s\n",c);
}
