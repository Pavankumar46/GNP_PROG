#include<stdio.h>
  main()
  {
  int a[10],i,s=0,p=1,ele;
  ele=sizeof a/sizeof a[0];
  printf("Enter the numbers\n");
  for(i=0;i<ele;i++)
  scanf("%d",&a[i]);
  for(i=0;i<ele;i++)
  {
  if(i%2==0)
  s+=i;
  else
  p*=i;
  }
  printf("add even=%d, product odd=%d\n",s,p);
  }
