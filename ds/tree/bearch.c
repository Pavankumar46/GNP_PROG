#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	struct st *left,*right;
	int data;
}tree;
void deleteinorder(struct st *root,int num)
{
tree *temp=root;
	if(temp->left->data==n)
	{
	temp->left->right=temp->left->left;
	
		







}
void reverse(tree *hp)
{
	if(hp)
	{
		reverse(hp->right);
		printf("%d  ",hp->data);
		reverse(hp->left);
	}
}
void inorder(tree *hp)
{
	if(hp)
	{
		inorder(hp->left);
		printf("%d  ",hp->data);
		inorder(hp->right);
	}
}
void insert(tree **ptr,int n)
{
	if(*ptr==0)
	{
		*ptr=malloc(sizeof(tree));
		(*ptr)->data=n;
		(*ptr)->left=0;
		(*ptr)->right=0;
	}
	else if((*ptr)->data>n)
		insert(&(*ptr)->left,n);
	else if((*ptr)->data<n)
		insert(&(*ptr)->right,n);
}
main()
{
	tree *hp;int n,ch;
	do
	{
		printf("enter n\n");
		scanf("%d",&n);
		insert(&hp,n);
		printf("enter 1 to continue\n");
		scanf("%d",&ch);
	}while(ch==1);
	inorder(hp);
	printf("\n");
//	deleteinorder(hp,5);
	reverse(hp);
	printf("\n");
}


