#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fp;
	char **p,*q,ch;
	int k=0,c=0,c1=0,r,i,d=0;
	if(argc!=3)
	{
		printf("usage ./a.out fname lnumber\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	r=atoi(argv[2]);
	r=r-1;
	while((ch=fgetc(fp))!=-1)
	{
		c++;
		d++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
			k++;
		}
	}
	rewind(fp);
	p=malloc(sizeof(char *)*k);
	for(i=0;i<k;i++)
		p[i]=malloc(c1+1);
	for(i=0;i<k;i++)
		fgets(p[i],c1+1,fp);
	q=malloc(d);
	printf("enter the string to replace\n");
	gets(q);
	fp=fopen(argv[1],"w");
	for(i=0;i<k;i++)
	{
		if(i==r)
			fprintf(fp,"%s\n",q);
		else
			fputs(p[i],fp);
	}
}
