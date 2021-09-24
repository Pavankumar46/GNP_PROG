#include"header.h"
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





