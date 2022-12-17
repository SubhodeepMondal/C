#include<stdio.h>
#include<stdlib.h>
 struct node
 {
 	int data;
 	struct node *left,*right;
 }*start=NULL;
 void create(struct node **ptr,int val)
 {
 	struct node *temp;
 	if(*ptr==NULL)
 	{
 		temp=(struct node*)malloc(sizeof(struct node));
 		temp->left=temp->right=NULL;
 		temp->data=val;
 		*ptr=temp;
 		return;
	}
	else if(val>(*ptr)->data)
		create(&(*ptr)->right,val);
	else
		create(&(*ptr)->left,val);
 }
 void inorder(struct node *ptr)
 {
 	if(ptr)
 	{
 		inorder(ptr->left);
 		printf("%d ",ptr->data);
 		inorder(ptr->right);
	 }
 }
 void main()
 {
 	int data,n,i;
 	printf("Enter the number of data to be inserted:");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		printf("Enter the data value:");
 		scanf("%d",&data);
 		create(&start,data);
	 }
	 printf("\n");
	 inorder(start);
 }
