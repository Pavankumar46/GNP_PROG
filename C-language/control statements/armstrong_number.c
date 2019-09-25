#include<stdio.h>
main()
{
	int c,r,i,p,l,n,k,s;
	printf("enter upto which number\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=i;
		for(c=0;p!=0;c++)
		{
			p=p/10;
		}
		p=i;
		for(s=0;p!=0;p/=10)
		{
			r=p%10;
			for(l=1,k=1;l<=c;l++)
			{
				k=k*r;
			}
			s=s+k;
		}
		if(s==i)
			printf("%d\t",s);
	}
} 
