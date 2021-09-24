/*#include<stdio.h>
#include<stdlib.h>
struct st
{
	int r;
	char n[10];
	float m;
	struct st *next;
}*head,*tail,*new,*temp;
struct st * get_data();
void insert(struct st *);
int count();
main()
{
	int n,c,i;
	struct st **p,*s;
	do
	{
		s=get_data();
		insert(s);
		printf("enter 1 to continue else 0\n");
		scanf("%d",&n);
	}while(n!=0);
	c=count();
	p=malloc(sizeof(struct st *)*c);
	for(i=0;i<c;i++)
		p[i]=malloc(sizeof(struct st));
	for(i=0,temp=head;temp;temp=temp->next,i++)
		p[i]=temp;
	for(i=c-1;i>=0;i--)
		printf("%d %s %f\n",p[i]->r,p[i]->n,p[i]->m);
}
struct st * get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	printf("enter rollno\n");
	scanf("%d",&s->r);
	printf("enter name\n");
	scanf("%s",s->n);
	printf("enter marks\n");
	scanf("%f",&s->m);
	return s;
}
void insert(struct st *s)
{
	new=malloc(sizeof(struct st));
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
}*/

//using array of structure of pointers
/*#include<stdio.h>
#include<stdlib.h>
struct st
{
	int r;
	struct st *next;
}*head,*tail,*new,*temp;
struct st * get_data();
void insert(struct st *);
int count();
main()
{
	struct st *s,**p;
	int op,c,i;
	do
	{
		printf("enter 1 to continue else 2\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: s=get_data();
				insert(s);
				break;
			case 2: printf("exited\n");
				break;
		}
	}while(op!=2);	
	c=count();
	p=malloc(sizeof(struct st*)*c);
	for(i=0,temp=head;temp;temp=temp->next,i++)
	{
	p[i]=temp;
	}
	for(i=c-1;i>=0;i--)
	printf("%d\n",p[i]->r);
}	
struct st * get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	printf("enter the data\n");
	scanf("%d",&s->r);
	return s;
}
void insert(struct st *s)
{
	new=malloc(sizeof(struct st));
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
int count()
{
int c=0;
temp=head;
if(tail==0)
printf("no data\n");
while(temp)
{
c++;
temp=temp->next;
}
return c;
}
*/

//reversing the links using arrays
/*#include<stdio.h>
#include<stdlib.h>
struct st
{
	int r;
	struct st *next;
}*head,*tail,*new,*temp;
struct st * get_data();
void insert(struct st *);
int count();
main()
{
	struct st *s,**p;
	int op,c,i;
	do
	{
		printf("enter 1 to continue else 2\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: s=get_data();
				insert(s);
				break;
			case 2: printf("exited\n");
				break;
		}
	}while(op!=2);	
	c=count();
	p=malloc(sizeof(struct st*)*c);
	for(i=0,temp=head;temp;temp=temp->next,i++)
	{
	p[i]=temp;
	}
	for(i=1;i<c;i++)
	p[i]->next=p[i-1];
	head=p[i];
	for(i=0;i<c;i++)
	printf("%d\n",p[i]->r);
}	
struct st * get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	printf("enter the data\n");
	scanf("%d",&s->r);
	return s;
}
void insert(struct st *s)
{
	new=malloc(sizeof(struct st));
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
int count()
{
int c=0;
temp=head;
if(tail==0)
printf("no data\n");
while(temp)
{
c++;
temp=temp->next;
}
return c;
}*/



#include<stdio.h>
#include<stdlib.h>
struct st
{
	int r;
	struct st *next;
}*head,*tail,*new,*temp;
struct st * get_data();
void insert(struct st *);
void reverselinks();
void print();
main()
{
	struct st *s,**p;
	int op,c,i;
	do
	{
		printf("enter 1 to continue else 2\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: s=get_data();
				insert(s);
				break;
			case 2: printf("exited\n");
				break;
		}
	}while(op!=2);	
	print();
	printf("\n");
	reverselinks();
	print();
	printf("\n");
}
void print()
{
	temp=head;
	while(temp)
	{
		printf("%d ",temp->r);
		temp=temp->next;
	}
}
void reverselinks()
{
	struct st *p,*q,*r;
	p=head;
	q=0;
	while(p)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	head=q;
}	
struct st * get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	printf("enter the data\n");
	scanf("%d",&s->r);
	return s;
}
void insert(struct st *s)
{
	new=malloc(sizeof(struct st));
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







