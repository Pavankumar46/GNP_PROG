#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp,*fd;
	char s[10],ch,c;
	int i;
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	while((ch=fgetc(fp))!=-1)
	{
		if(ch=='<')
		{
			i=0;
			while((c=fgetc(fp))!='>')
			{
				s[i++]=c;
			}
			s[i]='\0';
			printf("%s\n",s);
			fd=fopen(s,"r");
			if(fd==0)
				printf("%s is not present\n",s);
			else
				printf("%s is present\n",s);		
		}
	}
}
