#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	int i,c;
	char ch,*p;
	if(argc!=2)
	{
		printf("usage:./a.out fname\n");
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
	p=malloc(c);
	rewind(fp);
	while(fscanf(fp,"%s",p)!=-1)
	{
		for(i=0;p[i];i++);
		p[0]=p[0]^32;
		p[i-1]^=32;
		fseek(fp,-i,SEEK_CUR);
		fputs(p,fp);
	}
}
