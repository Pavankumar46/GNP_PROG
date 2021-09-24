#include"header.h"
main()
{
	int op;
	struct st *s;
	do
	{
		printf("enter 1.file_read 2. insert_beg 3. insert_end 4.display 5.sort_insert 6. file_print 7.rec_display 8.revdata 9.exit\n");		
		scanf("%d",&op);
		switch(op)
		{
			case 1:	read_file();
				break;	
			case 2: s=get_data();
				insert_beg(s);
				break;
			case 3:	s=get_data();
				insert_end(s);
				break;
			case 4:	display();
				break;
			case 5: s=get_data();
				sort_insert(s);
				break;
			case 6: print_file();
				break;
			case 7: temp=head;
				rec_display(temp);
				break;
			case 8: rev_data();
				break;
			case 9: printf("exit\n");
				break;
		}
	}while(op!=9);
}


