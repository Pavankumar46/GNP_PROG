#include<stdio.h>
#include<string.h>
struct st
{
	int r;
	char n[10];
	float m;
};
main()
{
	struct st s[3],p;
	int i,j,k,op;float q;char ch[10];
	for(i=0;i<3;i++)
	{
		printf("enter the roll s[%d]\n",i);
		scanf("%d",&s[i].r);
		printf("enter the name s[%d]\n",i);
		scanf("%s",s[i].n);
		printf("enter the marks s[%d]\n",i);
		scanf("%f",&s[i].m);
	}
	printf("-------------------------------\n");
	printf("enter the option\n1. Roll\n2. Name\n3. Marks\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: for(i=0;i<3-1;i++)
				for(j=0;j<3-1-i;j++)
					if(s[j].r>s[j+1].r)
					{
						p=s[j];
						s[j]=s[j+1];
						s[j+1]=p;
					}
			break;
		case 2: for(i=0;i<3-1;i++)
				for(j=0;j<3-1-i;j++)
					if(strcmp(s[j].n,s[j+1].n)==1)
					{
						p=s[j];
						s[j]=s[j+1];
						s[j+1]=p;
					}
			break;
		case 3: for(i=0;i<3-1;i++)
				for(j=0;j<3-1-i;j++)
					if(s[j].m>s[j+1].m)
					{
						p=s[j];
						s[j]=s[j+1];
						s[j+1]=p;
					}
			break;
	}

			for(i=0;i<3;i++)
			{
				printf("%d\t",s[i].r);
				printf("%s\t",s[i].n);
				printf("%f\n",s[i].m);
			}
	
}
