#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*p;
	int i,c;
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	c=0;
	while((ch=fgetc(fp))!=-1)
		c++;
	rewind(fp);
	p=malloc(c+1);
	i=0;
	while((ch=fgetc(fp))!=-1)
		p[i++]=ch;
	p[i]='\0';
	rewind(fp);
	for(i=0;p[i];i++)
	{
		if(p[i]>='a' && p[i]<='z' || p[i]>='A' && p[i]<='Z')
		{
			if(p[i]>='a' && p[i]<='z')
				p[i]-=32;
			else
				p[i]+=32;
		}
	}
	for(i=0;p[i];i++)
		fputc(p[i],fp);
}

//another methid for l to u & u to l
/*#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*p;
	int i,c;
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	while((ch=fgetc(fp))!=-1)
	{
		if((ch>='a' && ch <='z')||(ch>='A' && ch<='Z'))
		{
			ch^=32;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
	}
}*/
