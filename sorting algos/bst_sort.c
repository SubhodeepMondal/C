#include<stdio.h>
#include<stdlib.h>
long int count=0;
 struct node
 {
 	int data;
 	struct node *left,*right;
 }*start=NULL;
 void create(struct node **ptr,int val)
 {
 	count++;
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
 void main()
 {
 	long int data,n,i,temp;
 	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("BST.txt","r+");
		if(fp1==NULL)
			fp1=fopen("BST.txt","w");
	fp2=fopen("input.txt","r");
	ch=fgetc(fp2);
	while(ch!=EOF)
	{
		if(ch==',')
		{
			create(&start,temp);
			temp=0;
			i++;
			n++;
		}
		else
			temp=temp*10+(ch-'0');
		ch=fgetc(fp2);
	}
	n++;
	ch=fgetc(fp1);
	while(ch!=EOF)
		ch=fgetc(fp1);
 	
	 fprintf(fp1,"\n%ld\n%ld\n",n,count);
 }
