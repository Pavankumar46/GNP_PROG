//method 1
#include<stdio.h>
main()
{
	char a[]={'a','c','b','d','a','b','e','d','b','c'};
	int ele,i,j,k;
	ele=sizeof a/sizeof a[0];
	for(i=0;i<ele;i++)
	{
		for(j=i+1;j<ele;j++)
		{
			if(a[i]==a[j])
			{
				for(k=j;k<ele;k++)
					a[k]=a[k+1];
				ele--;
			}
		}
	}
for(i=0;i<ele;i++)
printf("%c ",a[i]);
printf("\n");
}

//method 2
//removing duplicate eliments
/*#include<stdio.h>
main()
{
	int t,k,i,j,ele,c,b,a[]={0,3,1,0,5,1,2,0,4,5};
	ele=sizeof a/sizeof a[0];
	for(i=0;i<ele;i++)
	{
		c=1;
		for(j=0;j<ele;j++)
		{
			if(a[i]==a[j]);
			{
			continue;
			}
		}
		for(k=i+1;k<ele;k++)
		{
			if(a[i]==a[k])
			c++;	
		}
	if(c==1)
	printf("%d ",a[i]);
	}
}*/
