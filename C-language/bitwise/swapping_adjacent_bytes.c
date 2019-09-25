//method 1
#include<stdio.h>
main()
{
unsigned int x=0x1234;
printf("%x\n",x);
x=((x<<8)&0xff00)|((x>>8)&0x00ff);
printf("%x\n",x);
}

//method 2
/*#include<stdio.h>
main()
{
unsigned char ch=0x34;
printf("%x\n",ch);
ch=(ch<<4)|(ch>>4);
printf("%x\n",ch);
}*/
