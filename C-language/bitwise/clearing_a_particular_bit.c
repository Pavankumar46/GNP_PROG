#include<stdio.h>
main()
{
	int pos,l,n,k;
	printf("enter the number and position");
	scanf("%d %d",&n,&k);
	for(pos=31;pos>=0;pos--)
		printf("%d",n>>pos&1);
	printf("\n");
	for(pos=31;pos>=0;pos--)
	{
		if(pos==k)
{
		l=n&~(1<<pos);
			printf("%d",l>>pos&1);
}		else
			printf("%d",n>>pos&1);
	}
	printf("\n");
}
