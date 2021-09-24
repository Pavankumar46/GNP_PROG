#include"header.h"
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





