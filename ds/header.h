#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct st
{
	int r;
	char n[10];
	float m;
	struct st *next;
}*new,*head,*tail,*temp;
struct st* get_data();
void insert_end(struct st *);
void insert_beg(struct st *);
void display();
void sort_insert(struct st *);
void read_file();
void rec_display(struct st *);
int count();
void rev_data();
void print_file();


