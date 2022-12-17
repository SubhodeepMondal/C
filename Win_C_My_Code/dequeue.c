#include<stdio.h>
#define maxsize 5

int front,rear,a[maxsize];

void pushback()
{
    if(rear>=maxsize)
    {
        printf("\nQueue Overflow \n");
        return;
    }
    else
    {
        printf("\nEnter a Number: ");
        scanf("%d",&a[rear++]);
    }
}

void popfront()
{
    if(front==rear)
    {
        printf("\nQueue Underflow \n");
        return;
    }
    else
    {
        printf("\nDeleted Item is: %d \n",a[front]);
        front++;
    }
}

void popback()
{
    if(front==rear)
    {
        printf("\nQueue Underflow \n");
        return;
    }
    else
    {
        printf("\nDeleted item is: %d \n",a[rear]);
        rear--;
    }
}

void pushfront()
{
    int i;
    if(rear>=maxsize)
    {
        printf("\nQueue Overflow ");
        return;
    }
    else if(front>0)
    {
        printf("\nEnter a Value: ");
        front--;
        scanf("%d",&a[front]);
    }
    else if(front==0 && rear<maxsize)
    {
        a[rear+1]=a[rear];
        for(i=rear;i<front;i--)
            a[i]=a[i-1];
        rear++;
        printf("\nEnter a Value: ");
        scanf("%d",&a[0]);
    }
}

void display()
{
    int i;
    if(front==rear)
    {
        printf("\nQueue is empty \n");
        return;
    }
    else
    {
        printf("\nThe queue is: ");
        for(i=front;i<rear;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
}
void input_restricted()
{
    int choice=0;
    while(choice!=5)
    {
        printf("\n1. Push \n2. Pop From Front \n3. Pop From Back \n4. Display \n5. Exit ");
        printf("\nEnter a Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:pushback();break;
            case 2:popfront();break;
            case 3:popback();break;
            case 4:display();break;
        }
    }
}

void output_restricted()
{
    int choice=0;
    while(choice!=5)
    {
        printf("\n1. Push in Front \n2. Push in Back \n3. Pop \n4. Display \n5. Exit ");
        printf("\nEnter a Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:pushfront();break;
            case 2:pushback();break;
            case 3:popfront();break;
            case 4:display();break;
        }
    }
}

void main()
{
    int choice=0;
    rear=front=0;
    while(choice!=3)
    {
        printf("\n1. Input Restricted \n2. Output Restricted \n3. Exit ");
        printf("\nEnter a Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:input_restricted();break;
            case 2:output_restricted();break;
        }
    }
}

