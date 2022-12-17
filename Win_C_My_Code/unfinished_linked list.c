#include<stdio.h>
#include<stdlib.h>

	struct node{
		int data;
		struct node *next;
	}*start=NULL;
void create(){
	char ch;
	do{
		struct node *next_node,*current;
		next_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter a data:");
		scanf("%d",&next_node->data);
		next_node->next=NULL;
		if(start==NULL){
			start=next_node;
			current=next_node;}
		else{
			current->next=next_node;
			current=next_node;
		}
		printf("Do you want to add any more data(press y for yes & n for no.):\n");
		ch=getch();
	}
	while(ch!='n');
}
void display(){
	struct node *next_node;
	next_node=start;
	while(next_node!=NULL){
		printf("%d-->",next_node->data);
		next_node=next_node->next;
	}
}
void main(){
	create();
	display();
}
