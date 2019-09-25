#include<stdio.h>
main()
{
	int a[10],i,ele,j,l,sl,s,ss;
	ele=sizeof a/sizeof a[0];
	printf("enter the number\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	if(a[0]>a[1])
	{
		l=a[0];
		sl=a[1];
	}
	else
	{
		l=a[1];
		sl=a[0];
	}
	if(a[0]<a[1])
	{
		s=a[0];
		ss=a[1];
	}
	else
	{	
		s=a[1];
		ss=a[0];
	}
	for(i=2;i<ele;i++)
	{	
		if(a[i]>l)
		{
			sl=l;
			l=a[i];
		}
		else if(a[i]>sl)
			sl=a[i];
		if(a[i]<s)
		{
			ss=s;
			s=a[i];
		}
		else if(a[i]<ss)
			ss=a[i];
	}
	printf("l=%d, sl=%d, s=%d, ss=%d\n",l,sl,s,ss);
}
