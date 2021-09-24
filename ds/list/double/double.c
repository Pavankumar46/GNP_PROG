#include<stdio.h>
#include<stdlib.h>
struct st 
{
	int data;
	struct st *prev;
	struct st *next;
}*temp,*head,*tail,*new;
struct st* get_data();
void insert(struct st *s);
void print();
void beg(struct st *s);
void mid(struct st *s);
main()
{
	int r;
	struct st *s;
	do
	{
		s=get_data();
		insert(s);
		printf("enter 1 for continue else 0\n");
		scanf("%d",&r);
	}while(r==1);
	s=get_data();
	beg(s);
	s=get_data();
	beg(s);
	print();
	s=get_data();
	mid(s);
	s=get_data();
	mid(s);
	print();
}
void mid(struct st *s)
{
	new=malloc(sizeof(struct st));
	new=s;
	int p,i;
	temp=head;
	printf("enter the pos\n");
	scanf("%d",&p);
	for(i=0;i<p-1;i++)
		temp=temp->next;
			new->prev=temp;
			new->next=temp->next;
			temp->next->prev=new;
			temp->next=new;
}
struct st* get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	s->prev=s->next=0;
	printf("enter the data\n");
	scanf("%d",&s->data);
	return s;
}
void insert(struct st *s)
{
	new=malloc(sizeof(struct st));
	new=s;
	new->next=new->prev=0;
	if(tail==0)
		head=tail=new;
	else
	{
		tail->next=new;
		new->prev=tail;
		tail=new;
	}
}
void print()
{
	temp=head;
	while(temp->next!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
/*	while(temp->prev!=0)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("%d\n",temp->data);
*/	printf("\n");
}
void beg(struct st *s)
{
	new=malloc(sizeof(struct st));
	new=s;
	if(tail==0)
		head=tail=new;
	else
	{
		
		head->prev=new;
		new->next=head;
		head=new;
	}
}






