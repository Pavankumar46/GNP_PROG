#include<stdio.h>
#include<stdlib.h>
struct st
{
	int roll;
	char name[10];
	float marks;
};
main(int argc,char **argv)
{
	struct st **p;
	int i,n;
	FILE *fp;
	if(argc!=3)
	{
		printf("usage:./a.out filename members\n");
		return;
	}
	n=atoi(argv[2]);
	fp=fopen(argv[1],"w");
	p=malloc(sizeof(struct st *)*n);
	for(i=0;i<n;i++)
		p[i]=malloc(sizeof(struct st));
	for(i=0;i<n;i++)
	{
		printf("enter the roll[%d]\n",i+1);
		scanf("%d",&p[i]->roll);
		printf("enter the name[%d]\n",i+1);
		scanf("%s",p[i]->name);
		printf("enter the marks[%d]\n",i+1);
		scanf("%f",&p[i]->marks);
	}
	for(i=0;i<n;i++)
		fprintf(fp,"%d %s %f\n",p[i]->roll,p[i]->name,p[i]->marks);
}

