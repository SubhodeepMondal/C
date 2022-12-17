#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *pre,*aft;
}*start=NULL,*end=NULL;
void create()
{
	int n=0;
	struct node *ptr1,*ptr2;
	while(n!=1)
	{
		ptr1=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&ptr1->data);
		end=ptr1;
		ptr1->aft=NULL;
		ptr1->pre=NULL;
		if(start==NULL)
		{
			start=ptr1;
			ptr2=ptr1;
		}
		else
		{
			ptr2->aft=ptr1;
			ptr1->pre=ptr2;
			ptr2=ptr1;
		}
		printf("Do you want to extend the list(press 1 to exit):");
		scanf("%d",&n);
	}
}
void display(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->aft;
	}
}
void reverse_display(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->pre;
	}
}
void main()
{
	int n=1;
	while(n>0&&n<=3)
	{
		printf("\n1 for create list:\n2 for display the list.\n3 for reverse display the list:");
		printf("Enter a choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				create();
				break;
			case 2:
				display(start);
				break;
			case 3:
				reverse_display(end);
				break;
		}
	}
}
