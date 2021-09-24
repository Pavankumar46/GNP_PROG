#include"header.h"
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





