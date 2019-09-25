#include<stdio.h>
main()
{
	int ele,a[5],i,s,j;
	ele=sizeof a/sizeof a[0];
	printf("enter the elements\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	for(i=0;i<ele;i++)
	{
		s=0;
		for(j=1;j<a[i];j++)
		{
			if(a[i]%j==0)
				s=s+j;
		}	
		if(s==a[i])
			printf("%d ",s);
	}
}
