#include<stdio.h>
int pal(char *);
main()
{
	char r,s[10];
	printf("enter the umber\n");
	scanf("%s",s);
	r=pal(s);
	if(r==1)
		printf("pal\n");
	else
		printf("not pal\n");
}
int pal(char *p)
{
	char *q;
	q=p;
	while(*q)
		q++;
	q--;
	while(p<q)
		if(*p++==*q--)
			break;
	if(*p==*q)
		return 1;
	else
		return 0;
}
