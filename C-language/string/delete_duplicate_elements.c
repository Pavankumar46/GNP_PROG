#include<stdio.h>
main()
{
	int i,c=0,m,j,k,l;
	char b[20],a[]="vecteeovvorr";
	for(l=0;a[l];l++);
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(a[i]==a[j])
			{	
				if(a[i]==a[j+1])
				for(k=j;k<l;k++)
				a[k]=a[k+2];
				else
				for(k=j;k<l;k++)
				a[k]=a[k+1];
			l--;
			}
		}		
	}	
		for(i=0;i<k;i++)
		printf("%c",a[i]);
		printf("\n");
	
}
