#include<stdio.h>
int main(void)
{
	int mat1[10][10],mat2[10][10],mat3[10][10],ROW1,ROW2,COL1,COL2;
	int i,j,k;
	printf("Enter matrix mat1row-wise :\n");
	scanf("%d %d",&ROW1,&COL1);
	for(i=0; i<ROW1; i++)
		for(j=0; j<COL1; j++)
			scanf("%d",&mat1[i][j]);
	printf("Enter matrix mat2row-wise :\n");
	scanf("%d %d",&ROW2,&COL2);
	for(i=0; i<ROW2; i++)
		for(j=0; j<COL2; j++)
			scanf("%d",&mat2[i][j] );
	/*Multiplication*/
	for(i=0; i<ROW1; i++)
		for(j=0; j<COL2; j++)
		{
			mat3[i][j] = 0;
			for(k=0; k<COL1; k++)
				mat3[i][j] += mat1[i][k] * mat2[k][j];
		}
	printf("The Resultant matrix mat3 is :\n");
	for(i=0; i<ROW1; i++)
	{
		for(j=0; j<COL2; j++)
			printf("%5d",mat3[i][j]);
		printf("\n");
	}
}
