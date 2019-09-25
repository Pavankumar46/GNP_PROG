#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
	FILE *fp;
	char ch,*p;
	p=malloc(10);
	p=argv[1];
	int l=0,w=0,b=0,c=0,c1=0;
	if(argc!=2)
	{
		printf("usage:./a.out fname\n");
		return;
	}
	fp=fopen(argv[1],"r");
	while((ch=fgetc(fp))!=-1)
	{
		b++;
		if(ch==' ')
		{
			w++;
		};
		if(ch=='\n')
		{
			w++;
			l++;
		}
	}
	printf(" %d %d %d %s\n",l,w-1,b,p);
}
