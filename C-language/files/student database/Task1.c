#include<stdio.h>
#include<stdlib.h>
struct st
{
	int roll;
	char name[10];
	float marks;
};
void r(struct st **,int );
void na(struct st **,int );
void m(struct st **,int );
void c(struct st **,int );
main(int argc,char **argv)
{
	struct st **p;
	int i,n,op;
	char ch;
	FILE *fp;
	if(argc!=3)
	{
		printf("usage:./a.out prev-filename members\n");
		return;
	}
	n=atoi(argv[2]);
	fp=fopen(argv[1],"r");
	p=malloc(sizeof(struct st *)*n);
	for(i=0;i<n;i++)
	{
		p[i]=malloc(sizeof(struct st));
	}
	for(i=0;i<n;i++)
	{	
		fscanf(fp,"%d%s%f",&p[i]->roll,p[i]->name,&p[i]->marks);
	}
	printf("enter the option for\n 1. roll\n 2.name\n 3.marks\n");
	scanf("%d",&op);
	if(op==1)
	{
		r(p,n);
		c(p,n);
	}
	else if(op==2)
	{
		na(p,n);
		c(p,n);
	}
	else if(op==3)
	{
		m(p,n);
		c(p,n);
	}
	else
	{
		printf("wrong option\n");
		return;
	}
}
void r(struct st **p,int n)
{
	struct st *t;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]->roll>p[j+1]->roll)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
void na(struct st **p,int n)
{
	struct st *t;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(p[j]->name,p[j+1]->name))
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
void m(struct st **p,int n)
{
	struct st *t;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j]->marks>p[j+1]->marks)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
}
void c(struct st **p,int n)
{
	struct st;
	FILE *fp;
	int i;
	fp=fopen("data1","w");
	for(i=0;i<n;i++)
		fprintf(fp,"%d %s %f\n",p[i]->roll,p[i]->name,p[i]->marks);
}

