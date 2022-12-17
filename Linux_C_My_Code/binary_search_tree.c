#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* left;
	struct node* right;
	int data;
}node;


//Creating Binary Search Tree
void bst(node **ptr,int item)
{
	node * pt1;

	if(*ptr == NULL)
	{
		pt1 = (node *) malloc(sizeof(node));
		pt1->data = item;
		pt1->left = pt1->right = NULL;
		*ptr = pt1;
		return ;
	}

	else if((*ptr)->data > item)
		bst(&(*ptr)->left,item);
	else
		bst(&(*ptr)->right,item);
}


//
void deletion(node *ptr, node *prev, int item)
{
	if(ptr!= NULL)
	{
		if(ptr-> data == item)
		{
			if(ptr-> left == NULL && ptr -> right == NULL)
			{
				prev = NULL;
				free(ptr);
				return ;
			}
			else if(ptr -> left != NULL && ptr -> right != NULL)
			{
				while(ptr->left != NULL)
					ptr = ptr->left;


			}
		}
		
	}
}

//Preorder traversal of the Binary Search Tree
void preorder(node *ptr)
{
	if(ptr!= NULL)
	{
		printf("%d\n", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}


void inorder(node *ptr)
{
	if(ptr!= NULL)
	{
		inorder(ptr->left);
		printf("%d\n", ptr->data);
		inorder(ptr->right);
	}
}


void main()
{
	int i,data;
	node* head=NULL;


	while(1)
	{
		printf("1. For insertion:\n2. For Printing Pre-order.\n3. For Printing In-order:\n4. Exit:");
		scanf("%d",&i);

		switch(i)
		{
			case 1:
			{
				printf("Enter the data to be inserted:\n");
				scanf("%d",&data);
				bst(&head,data);
				break ;
			}
			
			case 2:
			{
				printf("The data in the list are:\n");
				preorder(head);
				break ;
			}

			case 3:
			{
				printf("The data in the list are:\n");
				inorder(head);
				break ;
			}
			default :
				exit(0);
		}
	}
}