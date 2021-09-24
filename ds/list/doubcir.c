#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*new,*head,*tail,*temp;
struct node get_data();
void insert(struct node );
void insertbeg(struct node );
void mid(struct node );
void print();
main()
{
	int op;
	struct node s;
	do
	{
		printf("enter the option 1.inset 2.insertbeg 3.mid 4.print 5.exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("insert data");
				s=get_data();
				insert(s);
				break;
			case 2:	s=get_data();
				insertbeg(s);
				break;
			case 3:	s=get_data();
				mid(s);
				break;
			case 4: print();
				break;
			case 5: printf("exited\n");
				break;
		}
	}while(op!=4);
}
struct node get_data()
{
	struct node s;
	printf("enter the data\n");
	scanf("%d",&s.data);
	return s;
}
void insertbeg(struct node s)
{
	new=malloc(sizeof(struct node ));
	new->data=s.data;
	new->left=0;
	new->right=0;
	if(head==0)
	{
		head=tail=new;
		head->right=head;
		head->left=head;
	}
	else
	{
		head->left=new;
		new->right=head;
		head=new;
		tail->right=head;
		head->left=tail;
	}
}
void mid(struct node s)
{
	int p,i;
	new=malloc(sizeof(struct node ));
	new->data=s.data;
	new->left=0;
	new->right=0;
	printf("enter the position\n");
	scanf("%d",&p);
	temp=head;
	for(i=0;i<p;i++)
	temp=temp->right;
	if(tail==0)
	{
		head=tail=new;
		head->right=head;
		head->left=head;
	}
	else
	{	
		new->left =temp;
		new->right=temp->right;
		temp->right->left=new;
		temp->right=new;
	}		
}
void insert(struct node s)
{
	new=malloc(sizeof(struct node ));
	new->data=s.data;
	new->left=0;
	new->right=0;
	if(head==0)
	{
		head=tail=new;
		head->right=head;
		head->left=head;
	}
	else
	{
		tail->right=new;
		new->left=tail;
		new->right=head;
		head->left=new;
		tail=new;
	}
}
void print()
{
	temp=head;
	while(temp!=tail)
	{
	printf("%d ",temp->data);
	temp=temp->right;
	}
	printf("%d\n",temp->data);
}










