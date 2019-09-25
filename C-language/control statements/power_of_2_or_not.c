#include<stdio.h>
main()
{
	int n,r;
	printf("enter the number\n");
	scanf("%d",&n);
	r=n&n-1;
	if(r==0)
		printf("%d is the power of 2\n",n);
	else
		printf("%d is not the power of 2 \n",n);
}
