#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	char ch,s[100];int d=0,c=0,c1=0;
	if(argc!=3)
	{
		printf("usage string fname\n");
		return;
	}
	FILE *fp=fopen(argv[2],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	while(fscanf(fp,"%s",s)!=-1)
	{
		
		if(!strcmp(s,argv[1]))
		{
			d++;
		}
	}
	printf("%d\n",d);
}
