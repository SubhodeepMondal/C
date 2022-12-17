#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co,pw,flag;
	struct node *link;
}*start1=NULL,*start2=NULL,*start3=NULL;
typedef struct node poly;

void create_poly(poly *start)
{
	char ch;
	poly *ptr1,*ptr2;
	do
	{
		ptr1=(poly*)malloc(sizeof(poly));
		printf("enter the co-efficient:");
		scanf("%d",&ptr1->co);
		printf("Enter the power:");
		scanf("%d",&ptr1->pw);
		ptr1->link=NULL;
		if(start==NULL)
		{
			start=ptr1;
			ptr2=ptr1;
		}
		else
		{
			ptr2->link=ptr1;
			ptr2=ptr1;
		}
		printf("Do you want to continue(press 'n' to exit):");
		ch=getche();
	}while(ch!='n');
}
poly add_poly()
{
	poly *pt1=start1,*pt2,*pt3,*curr;
	do
	{
		pt3=(poly*)malloc(sizeof(poly));
		pt2=(poly*)malloc(sizeof(poly));
		pt2=find_power(pt1);
		if(pt2==NULL)
		{
			pt3->co=pt1->co;
			pt3->pw=pt1->pw;
		}
		else
		{
			pt3->co=pt1->co+pt2->co;
			pt3->pw=pt1->pw;
			pt3->link=NULL;
		}
		if(start3=NULL)
		{
			start3=pt3;
			curr=pt3;
		}
		else
		{
			curr->link=pt3;
			curr=pt3;
		}
		pt1->flag=1;
		pt1=pt1->link;
	}while(pt1!=NULL);
	pt2=start2;
	while(pt2->link!=NULL)
	{
		if(pt2->flag==0)
		{
			pt3=(poly*)malloc(sizeof(poly));
			pt3->co=pt2->co;
			pt3->pw=pt2->pw;
			if(start3=NULL)
		{
			start3=pt3;
			curr=pt3;
		}
		else
		{
			curr->link=pt3;
			curr=pt3;
		}
		pt2=pt2->link;
		}
	}
}
poly* find_power(poly *ptr)
{
	poly *pt2=start2;
	while(pt2->link!=NULL)
	{
		if(pt2->pw=ptr->pw)
		{
			pt2->flag=1;
			return (&pt2);
		}
		else
		pt2=pt2->link;
	}
	return (NULL);
}
void display(poly *start)
{
	poly *pt=start;
	while(pt->link!=NULL)
	{
		printf("%d[x^%d]+",pt->co,pt->pw);
	}
}
void main()
{
	printf("Enter the first polynomial:");
	create_poly(start1);
	printf("Enter the first polynomial:");
	create_poly(start2);
	add_poly();
	display(start1);
	display(start2);
	display(start3);
}

