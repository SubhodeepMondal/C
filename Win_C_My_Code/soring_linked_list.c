#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start=NULL,*head1=NULL,*head2=NULL;
void create(struct node **ptr)
{
	if(*ptr==NULL)
	{
		struct node *temp;
	int item;
	printf("Enter the data:");
	scanf("%d",&item);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=NULL;
	*ptr=temp;
	return ;
	}
	else
	create(&(*ptr)->link);
}
void display()
{
	struct node *ptr=start;
	if(ptr==NULL)
	{
		printf("The linked list is empty.");
		return ;
	}
	else
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->data);
		ptr=ptr->link;
	}
}
void seperate()
{
	struct node *temp,*prev1,*prev2,*ptr=start;
	float def;
		while(ptr!=NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			def=ptr->data%2;
			printf("%2.1f ",def);
			if(def==0)
			{
				temp->data=ptr->data;
				temp->link=NULL;
				if(head1==NULL)
				{
					head1=temp;
					prev1=temp;
				}
				else
				{
					prev1->link=temp;
					temp=prev1;
				}
			}
			else
			{
				temp->data=ptr->data;
				temp->link=NULL;
				if(head2==NULL)
				{
					head2=temp;
					prev2=temp;
				}
				else
				{
					prev2->link=temp;
					temp=prev2;
				}
			}
			ptr=ptr->link;
		}
	
	
}
void main()
{
	int n=0,i;
	struct node *ptr;
	while(n<4)
	{
		printf("Enter a choice\n1. insert.\n2.display.\n3. Seperate.");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				create(&start); break;
			case 2:
				printf("Which one you want to display:");
				scanf("%d",&i);
				if(i==1)
					ptr=start;
				else if(i==2)
					ptr=head1;
				else
					ptr=head2;
				display(ptr); 
				printf("NULL\n"); break;
			case 3:
				seperate(); break;
		}
	}
}
