#include<stdio.h>
#include<stdlib.h>
#define que struct queue
struct queue{
int info;
struct queue *link;
};
 que *front=NULL,*rear=NULL;
int count=0;
void push(int n)
{
que *newnode;
newnode=(struct queue*)malloc(sizeof(struct queue));
newnode->info=n;
newnode->link=NULL;
if(count==0)
front=newnode;
else
        rear->link=newnode;
    rear=newnode;
    rear->link=front;
count++;
}
int pop(void)
{
int n;
que *temp;
if(count==0)
return (-1);
count--;
    if(front==rear)
    {
        n=front->info;
        free(front);
        front=NULL;
        rear=NULL;
    }else
    {
            temp= front ;
            n = temp-> info ;
            front = front -> link ;
            rear -> link = front ;
            free ( temp ) ;
    }
return n;
}
void display(void)
{
que *temp;
int i;
if(count==0)
printf("Empty");
else
{
temp=front;
for(i=0;i<count;i++)
{
printf("%d ",temp->info);
temp=temp->link;
}
}
printf("\n");
}
int main()
{
int n,ch=10;
while(ch!=0)
{
printf("\n       Enter choice\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("0.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("What no. do you want to push in queue\n");
scanf("%d",&n);
push(n);
break;
}
case 2:
{
n=pop();
if(n==-1)
printf("Queue is empty\n");
else
printf("Number poped from queue is %d\n",n);
break;
}
case 3:
{
printf("Queue is -->> ");
display();
}
case 0:
break;
default:
printf("Wrong Choice\n");
break;
}
}
}
