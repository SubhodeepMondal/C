#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *left,*right;
}*start=NULL;
void create(struct node ** ptr,int item)
{
	struct node *temp;
	if(*ptr==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->left=temp->right=NULL;
		temp->value=item;
		*ptr=temp;
		return ;
	}
	else if(item<(*ptr)->value)
		create(&(*ptr)->left,item);
	else
		create(&(*ptr)->right,item);
}
void inorder(struct node *ptr)
{
	if(ptr)
	{
		
		inorder(ptr->left);
		printf("%d\n",ptr->value);
		inorder(ptr->right);
	}
}
void preorder(struct node *ptr)
{
	
	if(ptr)	
	{
		printf("%d\n",ptr->value);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void postorder(struct node *ptr)
{
	if(ptr)
	{
		
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\n",ptr->value);
	}
}
void del(struct node **ptr,struct node *pre,int item)
{
	if(*ptr==NULL)
	return;
	if(*ptr->value!=item)
		*ptr->left=del(&ptr,pre,item);
	else if(*ptr->value!=item)
		*ptr->right=del(&ptr,pre,item);
	else()
}
void main()
{
	int n=0,item;
	while(n<5)
	{
		printf("Enter the choice:\n1 for insert.\n2 for inorder traverse.\n3 for preorder traverse.\n4 for post order traverse:\n5. delete.");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the data:");
				scanf("%d",&item);
				create(&start,item);
				break;
			case 2:
				inorder(start);
				break;
			case 3:
				preorder(start);
				break;
			case 4:
				postorder(start);
				break;
			case 5:
					printf("Enter the number to delete:");
					scanf("%d",&item);
					del(&start,NULL,item);
					break;
		}
	}
}
