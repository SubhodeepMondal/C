#include<stdio.h>
int a[20],top=-1,n;
int push()
{
	if(top==n)
	{
		printf("The stack is full");
		return 0;
	}
	else
	{
		top++;
		printf("Enter the value:");
		scanf("%d",&a[top]);
	}
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("The stack is empty:");
		return 0;
	}
	else
	{
		item=a[top];	
		top--;
		return (item);
	}
}
void display()
{
	int i;
	for (i=top;i>-1;i--)
	{
		printf("%d\n",a[i]);
	}
}
void main()
{
	int i=0;
	char ch;
	printf("Enter the size of stack(not more than 20):");
	scanf("%d",&n);
	while(i<4)
	{
		printf("\nEnter a choice:\n1. push\n2. pop\n3.display:");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			push();
			break;
		case 2:
			printf("\nYou have poped %d.",pop());
			break;
		case 3:
			display();
			break;
		default:
			printf("\nInvalid input:");
		}	
	}
}
