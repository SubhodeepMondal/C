#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start=NULL;
void create()
{
	char c;
	do{
		struct node *new_node, *current;
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the data:");
		scanf("%d",&new_node->data);
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
		printf("\nEnter the choice:\n");
		c=getche();
	}
	while(c!='n');
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
}
void display()
{
	struct node *new_node;
	printf("\nThe linked List:\n");
	
	for(new_node=start;new_node!=NULL;new_node=new_node->link){
		printf("(%d)-->%d",new_node->link,new_node->data);
	}
}
void deletenode()
{
	struct node *temp,*new_node;
	int item;
	printf("\nEnter the node data want to delete:");
	scanf("%d",&item);
	temp=new_node=start;
	if(new_node->data==item)
	{
		start=new_node->link;
	}
	new_node=new_node->link;
	while(new_node!=NULL)
	{
		if(new_node->data==item)
		{
			if(new_node->link==NULL)
			temp->link=NULL;
			else
			temp->link=new_node->link;
		}
		new_node=new_node->link;
		temp=temp->link;
	}
	
}
void main()
{
	create();
	sort();
	display();
	deletenode();
	display();
}
