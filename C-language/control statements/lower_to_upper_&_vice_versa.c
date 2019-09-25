#include<stdio.h>
main()
{
char i,ch;
printf("enter the character\n");
scanf("%c",&ch);
if(ch>=97 && ch<=122)
ch=ch-32;
else
ch=ch+32;

printf("%c",ch);
}
