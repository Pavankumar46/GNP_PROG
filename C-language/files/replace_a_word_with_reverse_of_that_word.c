#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,s[10],s1[10];
	int l,i,j;
	if(argc!=3)
	{
		printf("usage:./a.out fname string\n");
		return;
	}
	fp=fopen(argv[1],"r+");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	strcpy(s,argv[2]);
	l=strlen(s);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		ch=s[i];
		s[i]=s[j];
		s[j]=ch;
	}
	while((fscanf(fp,"%s",s1))!=-1)
	{
		if(strcmp(argv[2],s1)==0)
		{
			fseek(fp,-l,SEEK_CUR);
			fprintf(fp,"%s",s);
		}
	}
}
