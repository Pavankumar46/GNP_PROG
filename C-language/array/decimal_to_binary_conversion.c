#include<stdio.h>
main()
{
	int num,a[15],i,j;
	printf("enter a decimal nnumber\n");
	scanf("%d",&num);
	i=0;
	while(num>0)
	{
		a[i]=num%2;
		num/=2;
		i++;
	}
	printf("binary number is:\n");
	for(j=i-1;j>=0;j--)
		printf("%d",a[j]);
	printf("\n");
}
