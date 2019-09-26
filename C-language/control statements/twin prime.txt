#include<stdio.h>
main()
{
	int i,j,n,c=0,d=1;
	printf("enter the count\n");
	scanf("%d",&n);
	for(i=0;c<n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			break;
		}
		if(i==j)
		{
			if(j-d==2)
			{
			printf("(%d,%d) ",d,j);
			c++;
			}
			d=j;
		}
	}
}