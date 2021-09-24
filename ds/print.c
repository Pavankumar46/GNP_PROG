#include"header.h"
void rec_display(struct st *temp)
{
	if(temp)
	{
	rec_display(temp->next);
	printf("%d %s %f\n",temp->r,temp->n,temp->m);
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





