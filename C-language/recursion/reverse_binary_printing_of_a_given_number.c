#include<stdio.h>
void binary(int);
int reverse(int,int,int);
void reverseprint(int,int);
main()
{
	int num,r,i=0,j=31,pos=31;
	printf("enter the number\n");
	scanf("%d",&num);
	binary(num);
	printf("\n");
	r=reverse(num,i,j);
	printf("\n");
	reverseprint(pos,r);
	printf("\n");
//	binary(num);
//	printf("\n");
//	r=reverse(num,i,j);
//	printf("\n");
//	reverseprint(pos,r);
//	printf("\n");
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
int reverse(int n,int i,int j)
{
	int m,k;
	if(i<j)
	{
		m=n>>i&1;
		k=n>>j&1;
		if(m!=k)
		{
			n=n^1<<i;
			n=n^1<<j;
		}
		reverse(n,i+1,j-1);
	}
	else
		return n;
}
void reverseprint(int pos,int n)
{
	if(pos>=0)
	{
		printf("%d",n>>pos&1);
		reverseprint(pos-1,n);
	}
	else
	pos=31;
}
