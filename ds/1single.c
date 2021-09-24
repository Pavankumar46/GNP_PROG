#include<stdio.h>
#include<stdlib.h>
struct st
{
	int r;
	char n[10];
	float m;
	struct st *next;
}*new,*head,*tail,*temp;
struct st* get_data();
void insert_end(struct st *);
void insert_beg(struct st *);
void display();
void sort_insert(struct st *);
void read_file();
void rec_display(struct st *);
int count();
void print_file();
main()
{
	int op;
	struct st *s;
	do
	{
		printf("enter 0000.file_read 1. insert_beg 2. insert_end 3.display 4.sort_insert 5. file_print 6.rec_display 7.exit\n");		
		scanf("%d",&op);
		switch(op)
		{
			case 0:	read_file();
				break;	
			case 1: s=get_data();
				insert_beg(s);
				break;
			case 2:	s=get_data();
				insert_end(s);
				break;
			case 3:	display();
				break;
			case 4: s=get_data();
				sort_insert(s);
				break;
			case 5: print_file();
				break;
			case 6: temp=head;
				rec_display(temp);
				break;
			case 7: printf("exited\n");
				break;
		}
	}while(op!=6);
}
void rec_display(struct st *temp)
{
	if(temp)
	{
	rec_display(temp->next);
	printf("%d %s %f\n",temp->r,temp->n,temp->m);
	}
}
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
int count()
{
	int c=0;
	temp=head;
	while(temp)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
struct  st* get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	printf("enter the rollno\n");
	scanf("%d",&s->r);
	printf("enter the name\n");
	scanf("%s",s->n);
	printf("enter the marks\n");
	scanf("%f",&s->m);
	return s;
}
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
void display()
{
	int c;
	temp=head;
	while(temp!=0)
	{
		printf("%d %s %f\n",temp->r,temp->n,temp->m);
		temp=temp->next;
	}
	c=count();
	printf("count=%d\n",c);
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
void sort_insert(struct st *s)
{
	new=malloc(sizeof(struct st));
	new=s;
	new->next=0;
	if(head==0 || head->r>new->r)
	{
		new->next=head;
		head=new;
	}
	else
	{
		temp=head;
		while(temp)
		{
			if(temp->next==0 || temp->next->r>new->r)
			{
				new->next=temp->next;
				temp->next=new;
				break;
			}
			temp=temp->next;
		}
	}
}





