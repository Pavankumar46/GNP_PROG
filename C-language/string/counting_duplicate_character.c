#include<stdio.h>
main()
{
	int l,i,j,k=0,c;
	char a[]="hrithik roshan",ch,b;
	for(l=0;a[l];l++);
	for(i=0;i<l;i++)
	{
		c=1;
		for(j=i+1;j<l;j++)
		{
			if(a[i]==a[j])
			{
			c++;
			for(k=j;k<l;k++)
			a[k]=a[k+1];
			l--;
			}
		}
		if(c>1)
		printf("%c %d\n",a[i],c);
	}
}
