#include<stdio.h>
  main()
  {
  int n,i,r,s=0;
  printf("enter the number\n");
  scanf("%d",&n);
  int a[n];
  for(i=1;i<=n;i++)
  { 
  r=i*i;
  s+=r;
  a[i-1]=r;
  }
  printf("s=%d\n",s);
  for(i=0;i<n;i++)
  printf("%d ",a[i]);
  }
