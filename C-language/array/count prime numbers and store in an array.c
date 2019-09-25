#include<stdio.h>
main()
{
	int a[10],b[10],k=0,j,i,c=0,ele;
	ele=sizeof a/sizeof a[0];
	printf("Enter the numbers\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	for(j=0;j<ele;j++)
	{
		for(i=2;i<a[j];i++)
		{
			if(a[j]%i==0)
				break;
		}
		if(a[j]==i)
		{
			c++;
			b[k]=a[j]; 
			k++;
		}
  	
	}
	printf("count=%d\n",c);
	for(i=0;i<k;i++)
		printf("%d ",b[i]);
}
