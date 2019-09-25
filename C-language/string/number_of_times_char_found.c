#include<stdio.h>
main()
{
int i,n,c=0;char ch;
printf("enter the no of char");
scanf("%d",&n);
char a[n];
printf("enter the string\n");
scanf("%s",a);
printf("enter the char\n");
scanf(" %c",&ch);
for(i=0;i<n;i++)
{
if(a[i]==ch)
 c++;
}
printf("%d",c);
}
