#include<stdio.h>
main()
{
	int a[]={10,2,4,5,2,1,3,4,6,5,8,9,2},b[10];
	int ele,i,j,k,l=0;
	ele=sizeof a/sizeof a[0];
	for(i=0;i<ele;i++)
	{
		for(j=i+1;j<ele;j++)
		{
			if(a[i]==a[j])
			{
				b[l++]=a[j];
				for(k=j;k<ele;k++)
					a[k]=a[k+1];
				ele--;
			}
		}
	}
for(i=0;i<ele;i++)
printf("%d ",a[i]);
printf("\n");
for(i=0;i<l;i++)
printf("%d ",b[i]);
printf("\n");
}
