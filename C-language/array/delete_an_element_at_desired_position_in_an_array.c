#include<stdio.h>
main()
{
	int a[8],i,ele,n,p;
	ele=sizeof a/sizeof a[0];
	printf("enter the element\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	printf("enter the position\n");
	scanf("%d",&p);
	printf("leaving an empty space\n");
	for(i=0;i<ele;i++)
	{
		if(i==p-1)
		{
			printf("\n"); 
			i++;
		} 
		printf("%d\n",a[i]);
	}
	printf("array after deletion\n");
	for(i=0;i<ele;i++)
	{
		if(i>=p-1)
			a[i]=a[i+1];
	}
	for(i=0;i<ele;i++)
	{
		if(i>=ele-1)
			printf("\n");
		else
			printf("%d\n",a[i]);
	}
}
