#include<stdio.h>
main()
{
	int r,n,pos,op,c=0;
	printf("enter the number\n");
	scanf("%d",&n);
L1:
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos>=0 && pos<=31)
	{
		printf("enter 1.set, 2.clear, 3.toggle\n");
		scanf("%d",&op);
		if(op==1){
			printf("%d\n",n|1<<pos);
	r=n|1<<pos;	
for(pos=31;pos>=0;pos--)
                        printf("%d",r>>pos&1);
}		else if(op==2)
			printf("%d\n",n&~(1<<pos));
		else if(op==3)        
			printf("%d\n",n^1<<pos);
		else       
			printf("wrong option");
	}
	else
	{
		c++;
		printf("wrong position number\n");
		if(c<=3)
			goto L1;
	}
}

