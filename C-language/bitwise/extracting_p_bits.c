#include<stdio.h>
main()
{
	int p,b,n,k;
	printf("enter the number\n");
	scanf("%d",&n);
	for(p=31;p>=0;p--)
		printf("%d",n>>p&1);
	printf("\n");
	printf("enter the position and bits\n");
	scanf("%d %d",&p,&b);
	k=(((1<<b)-1)&(n>>(p-1)));
	printf("%d\n",k);
	for(p=31;p>=0;p--)
		printf("%d",k>>p&1);
	printf("\n");
}
