#include<stdio.h>
#include<stdlib.h>
struct node
{
	float co;
	int x,y;
	struct node *link;
}*start1=NULL,*start2=NULL,*start3=NULL;
struct node *findpow(int ,int );
void create(struct node **ptr)
{
	struct node *temp,*curr;
	char ch;
	do
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the co-efficient:");
		scanf("%f",&temp->co);
		printf("\nEnter the power value of x and y:");
		scanf("%d%d",&temp->x,&temp->y);
		temp->link=NULL;
		if(*ptr==NULL)
		{
			*ptr=temp;
			curr=temp;
		}
		else
		{
			curr->link=temp;
			curr=temp;
		}
		printf("Do you want to add another node:");
		fflush(stdin);
		ch=getche();
	}while(ch=='y');
}
void addpoly()
{
	struct node *ptr1=start1,*ptr2,*ptr3,*curr;
	int a,b;
	while(ptr1)
	{
		ptr3=(struct node*)malloc(sizeof(struct node));
		a=ptr1->x;
		b=ptr1->y;
		ptr2=findpow(a,b);
		if(ptr2)
			ptr3->co=ptr1->co-ptr2->co;
		else
			ptr3->co=ptr1->co;
		ptr3->x=ptr1->x;
		ptr3->y=ptr1->y;
		ptr3->link=NULL;
		if(start3==NULL)
		{
			start3=ptr3;
			curr=ptr3;
		}
		else
		{
			curr->link=ptr3;
			curr=ptr3;
		}
		ptr1=ptr1->link;
	}
	ptr2=start2;
	while(ptr2)
	{
		ptr3=(struct node*)malloc(sizeof(struct node));
		ptr3->co=-ptr2->co;
		ptr3->x=ptr2->x;
		ptr3->y=ptr2->y;
		ptr3->link=NULL;
		if(start3==NULL)
		{
			start3=ptr3;
			curr=ptr3;
		}
		else
		{
			curr->link=ptr3;
			curr=ptr3;
		}
		ptr2=ptr2->link;
	}
}
struct node *findpow(int a, int b)
{
	struct node *ptr1,*ptr2;
	ptr1=ptr2=start2;
	if(ptr1->x==a)
	if(ptr1->y==b)
	{
		start2=start2->link;
		return(ptr1);
	}
	ptr1=ptr1->link;
	while(ptr1)
	{
		if(ptr1->x==a)
		if(ptr1->y==b)
		{
			ptr2->link=ptr1->link;
			return (ptr1);
		}
		ptr1=ptr1->link;
		ptr2=ptr2->link;
	}
	return (NULL);
}
void print(struct node *ptr)
{
	while(ptr)
	{
		printf("%f[x^%d][y^%d]-->",ptr->co,ptr->x,ptr->y);
		ptr=ptr->link;
	}
}
void main()
{
	printf("Enter the values of first polynomial:");
	create(&start1);
	print(start1);
	printf("NULL");
	printf("\nEnter the values of second polynomial:");
	create(&start2);
	print(start2);
	printf("NULL");
	addpoly();
	printf("\nThe resultant polynomial is:");
	print(start3);
	printf("NULL");
	getch();
}
