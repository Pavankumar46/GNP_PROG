#include<stdio.h>
main()
{
	int i,j,n,c=0,d=0;
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
			c++;
			d++;
			if(d==2||d==3)
			{
				printf("%d ",i);
				if(d==3)
				d=0;
			}
		}
	}
}