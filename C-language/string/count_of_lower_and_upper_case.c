#include<stdio.h>
main()
{
char a[100];
int i,s=0,l=0,u=0,n=0;
printf("enter the string\n");
scanf("%s",a);
for(i=0;a[i];i++)
{ 
if(a[i]>='a'&&a[i]<='z')
 l++;
 else if(a[i]>='A'&&a[i]<='Z')
 u++;
 else if(a[i]>='1'&&a[i]<='9')
 n++;
 else
 s++;
}
printf("lowercase count=%d, uppercase count=%d, special count=%d number count=%d\n",l,u,s,n);
}
