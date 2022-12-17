#include<stdio.h>
#include<stdlib.h>
struct node{
	int item;
	struct node *link;
}*start=NULL;
void create(){
	char c;
	do{
		struct node *new_node, *current;
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter a new data:");
		scanf("%d",&new_node->item);
		new_node->link=NULL;
		if(start==NULL)
		{
			start=new_node;
			current=new_node;
		}
		else
		{
			current->link=new_node;
			current=new_node;
		}
		printf("\nDo you want to create another :\n");
		c=getche();
	}
	while(c!='n');
	
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
void reverse(struct node *ptr)
{
	struct node *curr;
	curr=ptr;
	if(ptr->link==NULL)
	{
		start=ptr;
		return (ptr);
	}
	ptr=ptr->link;
	reverse(ptr);
	curr->link->link=curr;
	curr->link=NULL;
}
void reverse_display(struct node *ptr)
{
	struct node *curr;
	curr=ptr;
	if(ptr->link==NULL)
	{
		printf("%d-->",ptr->item);
		return (ptr);
	}
	ptr=ptr->link;
	reverse(ptr);
	printf("%d-->",ptr->item);
}
void main(){
	create();
	display();
	reverse_display(start);
}
