#include<stdio.h>
int length(const char *,int);
main()
{
	char s[]="gnpavan";int c=0,l;
	l=length(s,c);
	printf("lenght of %s is %d\n",s,l);
	l=length(s,c);
	printf("lenght of %s is %d\n",s,l);
}
int length(const char *p,int c)
{
	if(*p)
	{
		//		c++;
		//		return length(p+1,c);
		//			(or)
		return c+1+length(p+1,c);
	}
	else 
		//		return c;
		//		(or)
		return 0;
}
