#include<stdio.h>
#include<stdlib.h>
struct node{
	int item;
	struct node *link;
}*start=NULL;
void create()
{
	int i=0,n;
	struct node *new_node, *curr,*ptr;
	curr=start;
	printf("1. Insert in first position\n2. Insert in last pos\n3. Insert in i'th pos:");
	scanf("%d",&n);
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter a new data:");
	scanf("%d",&new_node->item);
	new_node->link=NULL;
	if(start==NULL||n==1)
	{
		new_node->link=start;
		start=new_node;
	}
	if(n==2)
	{
		while(curr->link!=NULL)
		{
			curr=curr->link;
		}
		curr->link=new_node;
	}
	if(n==3)
	{
		printf("\nEnter the position to be inserted:");
		scanf("%d",&i);
		n=1;
		while(n!=i-1)
		{
			curr=curr->link;
			n++;
		}
		ptr=curr->link;
		curr->link=new_node;
		new_node->link=ptr;
	}
	
}
void del()
{
	int n,i=1;
	struct node *ptr1=start,*ptr2=start;
	printf("1. Delete from first position\n2. Delete from last pos\n3. Delete from ith pos:");
	scanf("%d",&n);
	switch(n)
	{
		case(1):
			start=start->link;
			break;
		case(2):
			ptr2=ptr2->link;
			while(ptr2->link!=NULL)
			{
				ptr1=ptr1->link;
				ptr2=ptr2->link;
			}
			ptr1->link=ptr2->link;
			break;
		case(3):
			printf("Enter the position:");
			scanf("%d",&n);
			ptr2=ptr2->link;
			while(i!=n-1)
			{
				ptr1=ptr1->link;
				ptr2=ptr2->link;
				i++;
			}
			ptr1->link=ptr2->link;
			break;
	}
}
void display(){
	struct node *new_node;
	printf("The linked List:\n");
	new_node=start;
	while(new_node!=NULL){
		printf("%d--->", new_node->item);
		new_node=new_node->link; 
	}
	printf("NULL");
}
void search(int itm)
{
	struct node *ptr=start;
	int count=1,flag=0;
	while(ptr->item!=itm)
	{
		if(ptr->link==NULL)
		{
			printf("\nData not found!");
			flag=1;
			break;
		}
		ptr=ptr->link;
		count++;
	}
	if(flag==0)
		printf("\nData found at position %d.",count);
}
void free_up()
{
	start=NULL;
	printf("Freed up!");
}
void main(){
	int i,n=0,itm;
	while(n<6)
	{
		printf("\n1. Add a node\n2. Delete a node\n3. Display the list\n4. Search for value\n5. Free up\n6. Exit:");
		scanf("%d",&n);
		switch(n)
		{
			case (1):
				create();
				break;
			case(2):
				del();
				break;
			case(3):
				display();
				break;
			case(4):
				printf("Enter the value to be searched:");
				scanf("%d",&itm);
				search(itm);
				break;
			case(5):
				free_up();
				break;
		}
	}
}
