#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct st
{
	int r;
	char n[10];
	float m;
};
void print(struct st **,int );
void roll(struct st **,int );
void name(struct st **,int );
void marks(struct st **,int );
main()
{
	struct st **p;int i,op,n;
	printf("enter the n value\n");
	scanf("%d",&n);
	p=malloc(sizeof(struct st *)*n);
	for(i=0;i<n;i++)
		p[i]=malloc(sizeof(struct st));
	for(i=0;i<n;i++)
	{
		printf("enter the roll s[%d]\n",i);
		scanf("%d",&p[i]->r);
		printf("enter the name s[%d]\n",i);
		scanf("%s",p[i]->n);
		printf("enter the marks s[%d]\n",i);
		scanf("%f",&p[i]->m);
	}
	printf("enter the option\n1. roll\n2. name\n3. marks\n");
	scanf("%d",&op);
	if(op==1)
	{
		roll(p,n);
		print(p,n);
	}
	else if(op==2)
	{
		name(p,n);
		print(p,n);
	}
	else if(op==3)
	{
		marks(p,n);
		print(p,n);
	}
	else
		printf("wrong option\n");
}
void print(struct st **p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",p[i]->r);
		printf("%s\t",p[i]->n);
		printf("%f\n",p[i]->m);
	}
}
void roll(struct st **p,int n)
{
	int i,j;
	struct st *t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(p[j]->r>p[j+1]->r)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
}
void name(struct st **p,int n)
{
	int i,j;
	struct st *t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(strcmp(p[j]->n,p[j+1]->n)==1)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
}
void marks(struct st **p,int n)
{
	int i,j;
	struct st *t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(p[j]->m>p[j+1]->m)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
}
