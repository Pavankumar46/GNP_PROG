#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*p;
	int c=0,i,j;
	if(argc!=2)
	{
		printf("usage:./a.out fname\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	while((ch=fgetc(fp))!=-1)
		c++;
	rewind(fp);
	p=malloc(c+1);
	i=0;
	while((ch=fgetc(fp))!=-1)
	{
		p[i++]=ch;
	}
	fp=fopen(argv[1],"w");
	for(i=0,j=c-2;i<j;i++,j--)
	{
		ch=p[i];
		p[i]=p[j];
		p[j]=ch;
	}
	for(i=0;i<c;i++)
		fputc(p[i],fp);
}


//reverse the contents of the given file
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char **p,*q,ch;
	int i,j,c=0,c1=0,k=0;
	if(argc!=2)
	{
		printf("usage:./a.out fname\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	while((ch=fgetc(fp))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			k++;
			if(c>c1)
				c1=c;
			c=0;
		}
	}
	q=malloc(c1+1);
	p=malloc(sizeof(char *)*k);
	for(i=0;i<k;i++)
		p[i]=malloc(c1+1);
	rewind(fp);
	for(i=0;i<k;i++)
		fgets(p[i],c1+1,fp);
	for(i=0,j=k-1;i<j;i++,j--)
	{
		q=p[i];
		p[i]=p[j];
		p[j]=q;
	}
	fp=fopen(argv[1],"w");
	for(i=0;i<k;i++)
		fputs(p[i],fp);
}*/
