#include<stdio.h>
int sumeven(int *,int);
main()
{
	int ele,sum,a[]={8,7,6,4,1,2};
	ele=sizeof a/sizeof a[0];
	sum=sumeven(a,ele-1);
	printf("%d\n",sum);
	sum=sumeven(a,ele-1);
	printf("%d\n",sum);
}
int sumeven(int *p,int n)
{
	if(n>=0)
	{
		if(p[n]%2==0)

			return p[n]+sumeven(p,n-1);

		else
			return sumeven(p,n-1);
	}

	else
		return 0;
}
