#include<stdio.h>
main()
{
int a,b,c,n;
printf("enter the a and b\n");
scanf("%d %d",&a,&b);
printf("1.add, 2.sub, 3.mul, 4.div\n");
scanf("%d",&n);
switch(n)
 {
 case 1: printf("%d+%d=%d\n",a,b,a+b);
	break; 
case 2: printf("%d-%d=%d\n",a,b,a-b);
	break; 
case 3: printf("%d*%d=%d\n",a,b,a*b);
	break;
 case 4: printf("%d% %d=%d\n",a,b,a%b);
 	break;
default : printf("wrong option\n"); 
}
}
