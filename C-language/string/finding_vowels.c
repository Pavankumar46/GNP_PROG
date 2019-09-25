#include<stdio.h>
main()
{
char s[5];
int i;
printf("enter the string\n");
scanf("%s",s);
for(i=0;s[i];i++)
{
if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
printf("%c ",s[i]);
}
printf("\n");
}
