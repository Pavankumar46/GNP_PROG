#include<stdio.h>
main()
{
	int a[10],big,small,ele,index1=0,index2=0,i,j;
	ele=sizeof a/sizeof a[0];
	printf("Enter the numbers\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	big=a[0];
	small=a[0];
	for(i=0;i<ele;i++)
	{
		if(a[i]>big)
		{
			big=a[i];
			index1=i;
		}
		if(a[i]<small)
		{
			small=a[i];
			index2=i;
		}
	}
	printf("big=%d, small=%d, index1=%d, index2=%d\n",big,small,index1,index2);
}
