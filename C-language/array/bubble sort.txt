bubble sort using arrays
#include<stdio.h>
main()
{
	char s[5],i,j,temp;
	int l;
	printf("enter the string\n");
	scanf("%s",s);
	for(l=0;s[l];l++);
	for(i=0;i<l-1;i++)
		for(j=0;j<l-1-i;j++)
			if(s[j]>s[j+1])
			{ 
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
	/*for(i=0;s[i];i++)
		printf("%c",s[i]);
	printf("\n");*/
	printf("%s\n",s);
}



