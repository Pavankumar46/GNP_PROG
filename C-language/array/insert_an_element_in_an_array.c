#include<stdio.h>
main()
{
	char a[10]={'b','c','d','e','f'},ch;
	int i,j,p;
	for(i=0;a[i]!='\0';i++)
		printf("%c ",a[i]);
	printf("\n");
	printf("enter the char and position\n");
	scanf("%c",&ch);
	printf("enter the position\n");
	scanf(" %d",&p);
	for(i=5;i>=0;i--)
	{
	if(i==p)
	{
	for(j=5;j>=i;j--)
	a[j]=a[j-1];
	a[j]=ch;
	break;
	}
	}
	for(i=0;a[i]!='\0';i++)
		printf("%c ",a[i]);
		}
