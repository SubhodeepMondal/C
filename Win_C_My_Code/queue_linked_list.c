#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
}*start=NULL,*end=NULL;
void insert()
{
	int item;
	struct node *temp;
	printf("Enter the data:");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=NULL;
	if(start==NULL)
	start=end=temp;
	else
	{
		end->link=temp;
		end=temp;	
	}
}
void del()
{
	if(start==NULL)
	printf("The queue is empty.");
	else
	{
		printf("You have extracted %d",start->data);
		start=start->link;
		return ;
	}
}
void display()
{
	struct  node *ptr=start;
	if(start==NULL)
	printf("The queue is empty.");
	else
	{
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	}
}
void main()
{
	int n=0;
	while(n<4)
	{
		printf("\nEnter the choice\n1. insert\n2. delete\n3.display:");
		scanf("%d",&n);
		switch(n)
		{		
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
		}
	}
}
