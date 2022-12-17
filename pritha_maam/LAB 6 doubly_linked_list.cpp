#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
}*head=NULL;
void insert(int d)
{
	struct node* temp,*flag;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=d;
		head->left=NULL;
		head->right=NULL;
	}
	else
	{
		temp=head;
		while(temp->right!=NULL)
			temp=temp->right;
		
		flag=(struct node*)malloc(sizeof(struct node));
		flag->data=d;
		flag->right=NULL;
		flag->left=temp;
		temp->right=flag;
	}
}
void display()
{
	if(head==NULL)
		printf("List is empty\n");
	else
	{

		struct node *temp;
		temp=head;
		do
		{
			printf("%d-->",temp->data);
			temp=temp->right;
		}while(temp!=NULL);
		printf("\n");
	}
}
void del_last()
{
	struct node* prev,*curr;
	curr=head;
	prev=NULL;
	while(curr->right!=NULL)
	{
		prev=curr;
		curr=curr->right;
	}
	prev->right=NULL;
	free(curr);
}
void free_list()
{
	struct node* temp;

   while (head != NULL)
    {
       temp = head;
       head = head->right;
       free(temp);
    }

}

int main()
{
	int ch,n;
	while(1)
	{
		printf("1.Insert element\n2.Display list\n3.Delete the last element\n4.Free the list\nEnter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter element to insert\n");
					scanf("%d",&n);
					insert(n);
					break;
			case 2: display();
					break;
			case 3: del_last();
					break;
			case 4: free_list();
					break;
			default: printf("Wrong choice");
		}
	}
}
