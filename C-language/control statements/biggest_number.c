#include<stdio.h>
main()
{
	int a,b,c;
	printf("enter the values of a,b &c\n");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
			printf("%d is big\n",a);
		else
			printf("%d is big\n",c);
	}
	else
		if(b>c)
			printf("%d is big\n",b);
		else
			printf("%d is big\n",c);
}
/*#include<stdio.h>
main()
{
	int a,b,c;
	printf("enter the values of a,b &c\n");
        scanf("%d %d %d",&a,&b,&c);
        a>b?a>c?printf("%d is big\n",a):printf("%d is big\n",c):b>c?printf("%d is big\n",b):printf("%d is big\n",c);
}*/
  
