 #include<stdio.h>
main()
{
	int n,d,r,pos;
	printf("enter the number and times \n");
	scanf("%d %d",&n,&d);
	for(pos=31;pos>=0;pos--)
		printf("%d",n>>pos&1);
	printf("\n");
	r=(n>>d)|(n<<(32-d));
	for(pos=31;pos>=0;pos--)
		printf("%d",r>>pos&1);
printf("\n");
}
