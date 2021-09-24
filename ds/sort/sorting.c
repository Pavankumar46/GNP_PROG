#include<stdio.h>
void quicksort(a,lb,up)
{
	if(lb<up)
	{
		loc=position(a,lb,up);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}
void position(a,lb,up)
{
	pivot=a[lb];
	start=lb;
	end=up;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(a[start],a[end]);
		}
	}
	swap(a[lb],a[end]);
	return end;
}

