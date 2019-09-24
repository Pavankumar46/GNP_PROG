#include<stdio.h>
void arrreverse(char *,int,int);
main()
{
	char a[10];int i,k=0,ele;
	printf("enter the string\n");
	scanf("%s",a);
	printf("%s",a);
	printf("\n");
	for(ele=0;a[ele];ele++);
	arrreverse(a,ele-1,k);
	printf("after reversing\n");
	printf("%s",a);
	printf("\n");
}
void arrreverse(char *p,int j,int i)
{
	int k,t;
	if(i<j)
	{
		t=p[i];
		p[i]=p[j];
		p[j]=t;
		arrreverse(p,j-1,i+1);
	}
		
}
