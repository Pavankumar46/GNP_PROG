#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fa,*fb,*fc;
	char ch,**p,**q;
	int i,j,k1=0,k2=0,c=0,c1=0,c2=0;
	if(argc!=4)
	{
		printf("usage:./a.out sf df\n");
		return;
	}
	fa=fopen(argv[1],"r");
	fb=fopen(argv[2],"r");
	if(fa==0)
	{
		printf("fa file not present\n");
		return;
	}
	if(fb==0)
	{
		printf("fb file not present\n");
		return;
	}
	while((ch=fgetc(fa))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
			k1++;
		}
	}
	c=0;
	while((ch=fgetc(fb))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c2)
				c2=c;
			c=0;
			k2++;
		}
	}
	rewind(fa);
	rewind(fb);
	p=malloc(sizeof(char*)*k1);
	q=malloc(sizeof(char*)*k2);
	for(i=0;i<k1;i++)
		p[i]=malloc(c1+1);
	for(i=0;i<k2;i++)
		q[i]=malloc(c2+1);
	for(i=0;i<k1;i++)
		fgets(p[i],c1,fa);
	for(i=0;i<k2;i++)
		fgets(q[i],c2,fb);
	fc=fopen(argv[3],"w");
	for(i=0,j=0;i<k1 && j<k2;i++,j++)
	{
		fputs(p[i],fc);
		fputs(q[j],fc);
	}
	if(i<k1)
	{
		for(;i<k1;i++)
			fputs(p[i],fc);
	}
	else if(j<k2)
	{
		for(;j<k2;j++)
			fputs(q[j],fc);
	}	
}

// second method for merging
/*#include<stdio.h>
#include<stdlib.h>
main(int argc,char **argv)
{
	FILE *fa,*fb,*fc;
	char ch,**p,**q;
	int i,j,k1=0,k2=0,c=0,c1=0,c2=0;
	if(argc!=4)
	{
		printf("usage:./a.out sf df\n");
		return;
	}
	fa=fopen(argv[1],"r");
	fb=fopen(argv[2],"r");
	if(fa==0)
	{
		printf("fa file not present\n");
		return;
	}
	if(fb==0)
	{
		printf("fb file not present\n");
		return;
	}
	while((ch=fgetc(fa))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
			k1++;
		}
	}
	c=0;
	while((ch=fgetc(fb))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c2)
				c2=c;
			c=0;
			k2++;
		}
	}
	rewind(fa);
	rewind(fb);
	p=malloc(sizeof(char*)*(k1+k2));
	for(i=0;i<k1;i++)
		p[i]=malloc(c1+1);
	for(;i<=k1+k2;i++)
		p[i]=malloc(c2+1);
	for(i=0;i<k1;i++)
		fgets(p[i],c1,fa);
	for(;i<=k2+k1;i++)
		fgets(p[i],c2,fb);
	fc=fopen(argv[3],"w");
	for(i=0;i<=k1+k2;i++)
		fputs(p[i],fc);
}*/
