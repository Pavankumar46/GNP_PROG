#include<stdio.h>
main()
{
char ch,s[10];
int i;
printf("enter the string\n");
scanf("%s",s);
for(i=0;s[i];i++)
{
if(s[i]>='a'&&s[i]<='z')
s[i]-=32;
else if(s[i]>='A'&&s[i]<='Z')
s[i]+=32;
}
printf("%s",s);
}
