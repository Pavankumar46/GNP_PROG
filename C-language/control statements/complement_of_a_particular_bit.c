#include<stdio.h>
main()
{
	int pos,n,k;
	printf("enter the number\n");
	scanf("%d %d",&n,&k);
	for(pos=31;pos>=0;pos--)
	{
		printf("%d",n>>pos&1);
	}
	printf("\n");
	for(pos=31;pos>=0;pos--)
	{
		if(pos==k)
		{
			n=n^(1<<pos);
		}
		printf("%d",n>>pos&1);
	}
}
