#include<stdio.h>
#include<string.h>
void replace(char [],char [],char []);
main()
{
	char a[50],b[50],c[50];
	printf("enter the string\n");
	gets(a);
	printf("enter the sub\n");
	gets(b);
	printf("enter the new\n");
	gets(c);
	replace(a,b,c);
	printf("after replacing\n");
	puts(a);
	printf("\n");
	}
void replace(char str[],char sub[],char new[])
{
	int i,j,k,start,end,flag=0,strl,subl,newl;
	strl=strlen(str);
	subl=strlen(sub);
	newl=strlen(new);
	for(i=0;i<strl;i++)
	{
		flag=0;
		start=i;
		for(j=0;str[i]==sub[j];j++,i++)
			if(j==subl-1)
				flag=1;
		end=i;
		if(flag==0)
			i=i-j;
		else
		{
			for(j=start;j<end;j++)
			{
				for(k=start;k<strl;k++)
					str[k]=str[k+1];
				strl--;
				i--;
			}
			for(j=start;j<start+newl;j++)
			{
				for(k=strl;k>=j;k--)
					str[k+1]=str[k];
				str[j]=new[j-start];
				strl++;
				i++;
			}
		}
	}
}
