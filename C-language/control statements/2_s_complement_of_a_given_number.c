#include<stdio.h>
  main()
  {
  int n,pos;
  printf("enter the given number");
  scanf("%d",&n);
  for(pos=31;pos>=0;pos--)
  {
  printf("%d",n>>pos&1);
  }
  printf("\n");
  n=~n+1;
  for(pos=31;pos>=0;pos--)
  {
  printf("%d",n>>pos&1);
  }
  printf("\n");
  }
