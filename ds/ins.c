#include"header.h"
void insert_end(struct st *s)
{
	new=(struct st*)malloc(sizeof(struct st));
	new=s;
	new->next=0;
	if(tail==0)
		head=tail=new;
	else
	{
		tail->next=new;
		tail=new;
	}
}
void insert_beg(struct st *s)
{
	new=(struct st*)malloc(sizeof(struct st));
	new=s;
	new->next=0;
	if(tail==0)
		head=tail=new;
	else
	{
		new->next=head;
		head=new;
	}
}




