#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,**p;
	int i,c=0,c1=0,r,n=0,k=0;
	if(argc!=3)
	{
		printf("usage:./a.out f.c char\n");
		return;
	}
	fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		printf("file not find\n");
		return;
	}
	while((ch=fgetc(fp))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
			k++;
		}
	}
	rewind(fp);
	r=atoi(argv[2]);
	r=r-1;	
	p=malloc(sizeof(char*)*k);
	for(i=0;i<k;i++)
		p[i]=malloc(c1+1);
	for(i=0;i<k;i++)
	{
		fgets(p[i],c1+1,fp);
	}
	fp=fopen(argv[1],"w");
	for(i=0;i<k;i++)
	{
		if(r!=i)
			fputs(p[i],fp);
	}
}
