#include<stdio.h>
main(int argc,char **argv)
{
	FILE *fp,*fd;
	char ch;
	int i,r;
	if(argc<3)
	{
		printf("usage:./a.out sf d1 d2 d3\n");
		return;
	}
	fp=fopen(argv[1],"r");
	if(fp==0)
	{
		printf("file not present\n");
		return;
	}
	for(i=2;i<argc;i++)
	{
		fd=fopen(argv[i],"r");
		if(fd!=0)
		{
			printf("file- is there, to truncate it enter 0 else non zero value\n");
			scanf("%d",&r);
			if(r==0)
			{
l1:
				fd=fopen(argv[i],"w");
				while((ch=fgetc(fp))!=-1)
					fputc(ch,fd);
			}
			else
				continue;
		}
		else
		{
			printf("file is not there, to copy enter 0 else non zero value\n");
			scanf("%d",&r);
			if(r==0)
				goto l1;
			else
				continue;
		}
	fp=fopen(argv[1],"r");	
	}
}
