#include<stdio.h>
#include<string.h>
main(int argc,char **argv)
{
	char ch,s[100];
	int c=0,c1=0;
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
	while((ch=fgetc(fp))!=-1)
	{
		c++;
		if(ch=='\n')
		{
			if(c>c1)
				c1=c;
			c=0;
		}
	}
	fp=fopen(argv[2],"r");
	while(fgets(s,c1,fp))
	{
		
		if(strstr(s,argv[1]))
		{
			printf("%s\n",s);
		}
	}
}
