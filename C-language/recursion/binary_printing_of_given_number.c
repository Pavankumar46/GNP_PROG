#include<stdio.h>
void binary(int);
main()
{
	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	binary(num);
	printf("\n");
	binary(num);
	printf("\n");
}
void binary(int n)
{
	static pos=31;
	if(pos>=0)
	{
		printf("%d",n>>pos&1);
		pos--;
		return binary(n);
	}
	else
		pos=31;
}
