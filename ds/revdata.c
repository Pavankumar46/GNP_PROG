#include"header.h"
void rev_data()
{
	int n;
	char s[10];
	float f;
	struct st *temp1;
	int c,i,j; 
	c=count();
	temp=head;
	for(i=0;i<c/2;i++)
	{
		temp1=head;
		for(j=0;j<c-1-i;j++)
			temp1=temp1->next;
		n=temp->r;
		temp->r=temp1->r;
		temp1->r=n;
		strcpy(s,temp->n);
		strcpy(temp->n,temp1->n);
		strcpy(temp1->n,s);
		f=temp->m;
		temp->m=temp1->m;
		temp1->m=f;
		temp=temp->next;
	}
}
