#include<stdio.h>
main()
{
char s[100],p[100];
int i,k=0;
printf("enter the string\n");
scanf("%[^\n]",s);
for(i=0;s[i];i++)
 {
  if(!(s[i]==' '&&s[i+1]==' '))
  {
	p[k]=s[i];
  	k++;
  }
}
p[k]='\0';
printf("%s",p);
}
