#include<stdio.h>
main()
{
	int t,i,j,ele,c,b,a[]={0,3,1,0,5,1,2,0,4,5};
	ele=sizeof a/sizeof a[0];
	for(i=0;i<ele-1;i++)
	{
		for(j=0;j<ele-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<ele;i=j)
	{
		c=1;
		for(j=i+1;j<ele;j++)
		{
			if(a[i]==a[j])
			{
				b=a[i];
				c++;
			}
			else
				break;	
		}
		if(c>1)
			printf("%d %d\n",b,c);
	}
}
