#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start=NULL,*current=NULL;
void create(int item)
{
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=item;
	new_node->link=NULL;
	if(start== NULL)
	{
		start=new_node;
		current=new_node;
	}
	else
	{
		current->link=new_node;
		current=new_node;
	}
}
void sort()
{
	struct node *pt1,*pt2;
	int temp;
	for(pt1=start;pt1!=NULL;pt1=pt1->link)
	{
		for(pt2=pt1->link;pt2!=NULL;pt2=pt2->link)
		{
			if(pt1->data>pt2->data){
				temp=pt1->data;
				pt1->data=pt2->data;
				pt2->data=temp;
			}
		}
	}
	printf("Linked list is sorted!\n");
}
void display()
{
	struct node *new_node;
	printf("\nThe linked List:\n");
	
	for(new_node=start;new_node!=NULL;new_node=new_node->link)
		printf("(%d)-->",new_node->data);
		printf("NULL");
}	
void main()
{
	int i=0,item,flag=0;
	while(i<4)
	{
		printf("\nEnter a choice:\n");
		printf("1. Insert data\n2. Display data:\n3 Sort Data\n4. Exit:");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				printf("Enter the data to be inserted:");
				scanf("%d",&item);
				create(item);
				flag=0;
				break;
			case 2:
				display();
				break;
			case 3:
				if(flag==0)
				{
					sort();
					flag=1;
				}
				else
					printf("List is already sorted.");
				break;
		}
	}
}
