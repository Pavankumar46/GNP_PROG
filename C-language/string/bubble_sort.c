#include<stdio.h>
main()
{
char a[100],ch;
int i,j,n;
printf("enter the string\n");
scanf("%s",a);
for(n=0;a[n];n++);
for(i=0;i<n;i++)
{
 for(j=i+1;j<n;j++)
  if(a[i]>a[j])
  {
        ch=a[i];
	a[i]=a[j];
	a[j]=ch;
  }
}
printf("%s\n",a);
}
