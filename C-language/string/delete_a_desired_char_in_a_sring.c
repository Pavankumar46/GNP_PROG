#include<stdio.h>
main()
{
	char a[10],ch;
	int i,j;
	printf("enter the string\n");
	scanf("%s",a);
	printf("enter the char\n");
	scanf(" %c",&ch);
	for(i=0;a[i];i++)
	{
		if(a[i]==ch)
		{
			for(j=i;a[j];j++)
			{ 
				a[j]=a[j+1]; 
			}
			i--;
		}
	}
	printf("%s\n",a);
}
