#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*p,sub[50],new[50];
	int c=0,i,j,k,stringl,subl,newl,flag=0,start,end;
	if(argc!=4)
	{
		printf("usage:./a.out fname\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not found\n");
		return;
	}
	strcpy(sub,argv[2]);
	strcpy(new,argv[3]);
	while((ch=fgetc(fp))!=-1)
		c++;
	c=c+1;
	rewind(fp);
	p=malloc(c);
	i=0;
	while((ch=fgetc(fp))!=-1)
		p[i++]=ch;
	rewind(fp);
	subl=strlen(argv[2]);
	newl=strlen(argv[3]);
	for(i=0;i<c;i++)
	{
		flag=0;
		start=i;
		for(j=0;p[i]==sub[j];j++,i++)
			if(j==subl-1)
				flag=1;
		end=i;
		if(flag==0)
			i=i-j;
		else
		{
			for(j=start;j<end;j++)
			{
				for(k=start;k<c;k++)
					p[k]=p[k+1];
				c--;
				i--;
			}
			for(j=start;j<start+newl;j++)
			{
				for(k=c;k>=j;k--)
					p[k+1]=p[k];
				p[j]=new[j-start];
				c++;
				i++;
			}
		}
	}
	fp=fopen(argv[1],"w");
	for(i=0;p[i];i++)
		fprintf(fp,"%c",p[i]);
}
