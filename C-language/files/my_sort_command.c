#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char **p,ch,*t;
	int i,j,c=0,c1=0,k=0;
	if(argc!=2)
	{
		printf("usage:./a.out fname\n");
		return;
	}
	fp=fopen(argv[1],"r");
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
	t=malloc(c1+1);
	p=malloc(sizeof(char *)*k);
	for(i=0;i<k;i++)
		p[i]=malloc(c1+1);
	rewind(fp);
	for(i=0;i<k;i++)
		fgets(p[i],c1+1,fp);
	for(i=0;i<k-1;i++)
	{
		for(j=0;j<k-1-i;j++)
		{
			if(strcmp(p[j],p[j+1])==1)
			{
				strcpy(t,p[j]);
				strcpy(p[j],p[j+1]);
				strcpy(p[j+1],t);
			}
		}
	}
	fp=fopen(argv[1],"w");
	for(i=0;i<k;i++)
		fputs(p[i],fp);
}
