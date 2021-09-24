//queue using linked list
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*rear,*front,*temp,*new;
void enqueue(int x)
{	
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=x;
	new->next=NULL;
	if(rear==NULL)
	{
		front=new;
		rear=new;
	}
	else
	{
		rear->next=new;
		rear=new;
	}
}
void dequeue()
{
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		temp=front;
		front=front->next;
		printf("%d\n",temp->data);
		temp->next=NULL;
		free(temp);
	}
}
void display()
{
	if(front==NULL)
		printf("queue is empty\n");
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
main()
{
	int op,n;
	do
	{
	printf("enter option for 1. enqueue, 2. dequeue, 3. display, 4. exit\n");
	scanf("%d",&op);
		switch(op)
		{
			case 1:	printf("enqueue enter the data\n");
				scanf("%d",&n);
				enqueue(n);
				break;
			case 2:	printf("dequeue\n");
				dequeue();
				break;
			case 3:	printf("display\n");
				display();
				break;
			case 4:	printf("exited\n");
				break;
		}
	}while(op!=4);
}*/

//queue using array
/*#include<stdio.h>
#define size 5
int Queue[size],front=-1,rear=-1;
void enqueue()
{	int n;
	if(rear==size-1)
		printf("queue is full\n");
	else
	{
		printf("enter the data\n");
		scanf("%d",&n);
		if(front==-1)
			front=0;
			rear=rear+1;
			Queue[rear]=n;
	}
}
void dequeue()
{	int n;
	if(rear==-1)
		printf("queue is empty\n");
	else
	{
		n=Queue[front];
		printf("%d\n",n);
		Queue[front]=0;
		front=front+1;
	}
}
void print()
{
	int i;
	if(rear==-1)
		printf("queue is empty\n");
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d ",Queue[i]);
		printf("\n");
	}
}
main()
{
	int op;
	do
	{
		printf("enter option for 1. enqueue, 2. dequeue, 3. display, 4. exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:	enqueue();
				break;
			case 2:	dequeue();
				break;
			case 3:	print();
				break;
			case 4:	printf("exited\n");
				break;
		}
	}while(op!=4);
}*/

//circular queue using array
/*#include<stdio.h>
#define size 5
int queue[size];
int front=-1;
int rear=-1;
void enqueue()
{
	int n;
	printf("enter data\n");
	scanf("%d",&n);
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=n;
	}
	else if((rear+1)%size==front)
		printf("queue if full\n");
	else
	{
		rear=(rear+1)%size;
		queue[rear]=n;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
		printf("queue is empty\n");
	else if(front ==rear)
	{
		printf("%d\n",queue[front]);
		front=rear=-1;
	}
	else
	{
		printf("%d\n",queue[front]);
		front=(front+1)%size;
	}
}
void print()
{
	int i=front;
	if(front==-1 && rear==-1)
		printf("queue is empty\n");
	else
	{
		while(i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%size;
		}
		printf("%d",queue[rear]);
	}
}
main()
{	
	int op;
	do
	{
		printf("enter option for 1. enqueue, 2. dequeue, 3. display, 4. exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:	enqueue();
				break;
			case 2:	dequeue();
				break;
			case 3:	print();
				break;
			case 4:	printf("exited\n");
				break;
		}
	}while(op!=4);
}*/

//circular queue using linked list
/*#include<stdio.h>
#include<stdlib.h>
struct st
{
	int data;
	struct st *next;
}*front,*rear,*temp,*new;
void enqueue(struct st *s)
{
	new=malloc(sizeof(struct st));
	new=s;
	new->next=0;
	if(front==0 && rear==0)
	{
		front=rear=new;
		rear->next=front;
	}
	else
	{
		rear->next=new;
		rear=new;
		rear->next=front;
	}
}
void dequeue()
{
	temp=front;
	if(front==0 &&rear==0)
		printf("underfloe\n");
	else if(front==rear)
	{
		front=rear=0;
		free(temp);
	}
	else
	{
		front=front->next;
		rear->next=front;
		free(temp);
	}
}
void display()
{
	if(front==0 && rear ==0)
		printf("queue is empty\n");
	else
	{
		temp=front;
		while(temp!=rear)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}
struct st* get_data()
{
	struct st *s;
	s=malloc(sizeof(struct st));
	printf("enter data\n");
	scanf("%d",&s->data);
	return s;
}
main()
{	
	int op;
	struct st *s;
	do
	{
		printf("enter option for 1. enqueue, 2. dequeue, 3. display, 4. exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:	s=get_data();
				enqueue(s);
				break;
			case 2:	dequeue();
				break;
			case 3:	display();
				break;
			case 4:	printf("exited\n");
				break;
		}
	}while(op!=4);
}*/

//implementation of queue using string
/*#include<stdio.h>
#define n 5
int s1[n],s2[n];
int top1=-1,top2=-1;
int count=0;
void enqueue(int );
void push1(int );
void push2(int );
int pop1();
int pop2();
void dequeue();
void display();
main()
{
	int op,x;
	do
	{
		printf("enter option for 1. enqueue, 2. dequeue, 3. display, 4. exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:	printf("enter data\n");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2:	dequeue();
				break;
			case 3:	display();
				break;
			case 4:	printf("exited\n");
				break;
		}
	}while(op!=4);
}
void enqueue(int x)
{
	push1(x);
	count++;
}
void dequeue()
{
	int i,a,b;
	if(top1<=-1 && top2<=-1)
		printf("empty\n");
	else
	{
		for(i=0;i<count;i++)
		{
			a=pop1();
			printf("%d ",a);
			push2(a);
		}
		b=pop2();
		printf("%d\n",b);
		count--;
		for(i=0;i<count;i++)
		{
			a=pop2();
			push1(a);
		}
	}
}
void push1(int x)
{
	if(top1>=n-1)
		printf("full\n");
	else
	{
		top1++;
		s1[top1]=x;
	}
}
void push2(int x)
{
	if(top2>=n-1)
		printf("full\n");
	else
	{	
		top2++;
		s1[top2]=x;
	}
}
int pop1()
{
	return s1[top1];
}
int pop2()
{
	return s2[top2--];
}
void display()
{
	int i;
	for(i=0;i<=top1;i++)
		printf("%d ",s1[i]);
}
*/











