#include<stdio.h>
int compare(char *,char *);
main()
{
	char a[10],b[10];int r;
	printf("enter the first string");
	scanf("%s",a);
	printf("enter the second string");
	scanf("%s",b);
	printf("%s\n",a);
	printf("%s\n",b);
	printf("-----------------------------\n");
	r=compare(a,b);
	if(r==1)
		printf("same\n");
	else
		printf("diff\n");
}
int compare(char *p,char *q)
{
	int i;
	for(i=0;p[i];i++)
		if(p[i]!=q[i])
			break;
	if(p[i]==q[i])
		return 1;
	else
		return 0;
}
