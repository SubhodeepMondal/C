#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start=NULL;
void push(int item)
{
	struct node *ptr,*next_node;
	next_node=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{	
		next_node->data=item;
		next_node->link=NULL;
		start=next_node;
	}
	else
	{
		next_node->data=item;
		ptr=start;
		start=next_node;
		next_node->link=ptr;
	}
}
int pop()
{
	if(start==NULL)
	{
		printf("\nThe stack is empty.\n");
		return ;
	}
	else
	{
		printf("You have popped:%d",start->data);
		start=start->link;
		return ;
	}
	
}
void display()
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\nThe stack is empty.\n");
		return ;
	}
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
		return ;
	}
}
void main()
{
	char ch;
	int i=0,item;
	while(i<=3)
	{
		printf("\nEnter a choice:\n(1 for push, 2 for pop, 3 for display):");
	  	scanf("%d",&i);
		switch(i)
		{
			case(1):
				printf("Enter a value:");
				scanf("%d",&item);
				push(item);
				break;
			case(2):
				 pop();
				break;
			case(3):
				display();
				break ;
			default:
				printf("Wrong input:");
		}
	}		
}
