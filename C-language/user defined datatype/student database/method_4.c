#include<stdio.h>
#include<string.h>
struct st
{
	int r;
	char n[10];
	float m;
};
void print(struct st *,int );
void roll(struct st *,int );
void name(struct st *,int );
void marks(struct st *,int );
main()
{
struct st s[3];int i,op;
	for(i=0;i<3;i++)
	{
		printf("enter the roll s[%d]\n",i);
		scanf("%d",&s[i].r);
		printf("enter the name s[%d]\n",i);
		scanf("%s",s[i].n);
		printf("enter the marks s[%d]\n",i);
		scanf("%f",&s[i].m);
	}
	printf("enter the option\n1.roll\n2.name\n3.marks\n");
	scanf("%d",&op);
	if(op==1)
	{
	roll(s,3);
	print(s,3);
	}
	else if(op==2)
	{
	name(s,3);
	print(s,3);
	}
	else if(op==3)
	{
	marks(s,3);
	print(s,3);
	}
	else
	printf("unknown option\n");
}
void print(struct st *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",p[i].r);
		printf("%s\t",p[i].n);
		printf("%f\n",p[i].m);
	}
}
void roll(struct st *p,int n)
{
	int i,j;
	struct st t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(p[j].r>p[j+1].r)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
}
void name(struct st *p,int n)
{
	int i,j;
	struct st t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(strcmp(p[j].n,p[j+1].n)==1)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
}
void marks(struct st *p,int n)
{
	int i,j;
	struct st t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(p[j].m>p[j+1].m)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
}
