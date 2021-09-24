#include"header.h"
void read_file()
{
	struct st *s,v;
	FILE *fp=fopen("data","r");
	while((fscanf(fp,"%d %s %f",&v.r,v.n,&v.m))!=-1)
	{
		s=malloc(sizeof(struct st));
		*s=v;
		sort_insert(s);
	}
}
void print_file()
{
	FILE *fp=fopen("data","w");
	temp=head;
	while(temp!=0)
	{
		fprintf(fp,"%d %s %f\n",temp->r,temp->n,temp->m);
		temp=temp->next;
	}
}


