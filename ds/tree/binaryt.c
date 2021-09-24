#include<stdio.h>
#include<stdlib.h>
struct st
{
	int data;
	struct st *left,*right;
};
struct st * create();
void inorder(struct st *);
void main()
{
	struct st *root;
	root=create();
	inorder(root);
	printf("\n");
}
struct st * create()
{
	int x,n;
	struct st *new;
	new=malloc(sizeof(struct st));
	printf("enter the data\n");
	scanf("%d",&n);
	if(n==-1)
	{
		return 0;
	}
	new->data=n;
	printf("enter left child\n");
	new->left=create();
	printf("enter right child\n");
	new->right=create();
	return new;
}

void inorder(struct st *root)
{
	if(root==0)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}




