#include<stdio.h>
main()
{
	int a[10][10],r,c,i,b[10][10],j;
	printf("enter the elements\n");
	scanf("%d %d",&r,&c);
	printf("first matrix\n");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	printf("second matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&b[i][j]);
	
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",a[i][j]+b[i][j]);
		printf("\n");
	}

}
