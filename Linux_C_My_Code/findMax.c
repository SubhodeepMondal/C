
// Sample code to perform I/O:
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num,count;
	struct node * next;
}node;

void countNum(node **head,int item)
{

	node *ptr=*head;
	int flag =0;
//	printf("%d ",item);

	if (*head == NULL)
	{
		ptr= (node *)malloc(sizeof(node));
		*head= ptr;
		ptr->num = item;
		ptr->count = 1;
		ptr->next = NULL;
//		printf("%d,%d\n",ptr->num,ptr->count);
	}
	else
	{

		while(ptr)
		{
//			printf("%d,%d,%d\n",ptr->num,ptr->count,item);
			if(ptr->num ==item)
			{
				flag =1;
				break;
			}
			else if(ptr->next != NULL)
				ptr = ptr->next;
			else
				break;

		}
//		printf("\n");


		if(flag == 1)
			ptr->count+=1;
		else
		{
//			printf("In the else\n");
			node *ptrNew= (node *)malloc(sizeof(node));
			ptr->next= ptrNew;
			ptrNew->num=item;
			ptrNew->count=1;
			ptrNew->next=NULL;	
		}
//		printf("%d,%d\n",ptr->num,ptr->count);
	}
		
}

void print(node *ptr)
{
	while(ptr)
	{
		printf("%d,%d\n",ptr->num,ptr->count);
		ptr= ptr->next;
	}
}

int findMax(node *ptr)
{
	int max,item;
	item=ptr->num;
	max=ptr->count;
	ptr=ptr->next;

	while(ptr)
	{
		if(ptr->count>max)
		{
			printf("%d, %d\n",ptr->num, ptr->count );
			item=ptr->num;
			max=ptr->count;
		}
		ptr=ptr->next;
	}
	return item;
}

int main(){
	int n,i;
	scanf("%d", &n);
	int *a = (int *) malloc(n*sizeof(int));
	for(i = 0; i< n; i++)
		scanf("%d",a+i);

	node *head=NULL;
	
	for(int i=0; i<n;i++)
		countNum(&head,a[i]);


	print(head);
	
	int max=findMax(head);
		printf("%d\n",max);
}

