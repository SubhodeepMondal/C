#include<stdio.h>
#include<stdlib.h>

struct list
{
    int n;
    struct list *next;
};

struct list *add(struct list *h,int num)
{
    struct list *pr,*pr1;
    pr=(struct list*)malloc(sizeof(struct list));
    pr->next=NULL;
    pr->n=num;
    if(h==NULL)

        h=pr;

    else
    {
        for(pr1=h;pr1->next!=NULL;pr1=pr1->next);
        pr1->next=pr;
    }
    return h;
};

void display(struct list *h)
{
    struct list *pr;
    if(h==NULL)
    {
        printf("\n\nLinked List is Empty \n\n");
    }
    else
    {
        printf("\nThe List is: \n\n");
        for(pr=h;pr!=NULL;pr=pr->next)

           printf("%d  ",pr->n);

        printf("\n\n");
    }
}

void reverse_display(struct list *h)
{
	struct list *pr=h;
    if(pr==NULL)

        return;

    else

        reverse_display(pr->next);

    printf("%d ",pr->n);
}

void node_count(struct list *h,int count)
{
	if(h==NULL)
	{
		printf("\nLinked List Does Not Exist \n");
		return;
	}
	printf("\nTotal Number of Nodes is: %d ",count);
}

struct list *insert_any(struct list *h,int num)
{
    int pos,temp=1;
    struct list *pr,*pr1;
    printf("\nEnter a Position to Insert the Number: ");
    scanf("%d",&pos);
    if(pos<=0)
    {
    	printf("\nInvalid Position \n");
    	return;
	}
    pr=(struct list *)malloc(sizeof(struct list));
    pr->next=NULL;
    pr->n=num;
    if(h==NULL)
    {
    	printf("\nAs List Does Not Exist, so the Entered Value is the Initial node of the Singly Linked List \n");
    	h=pr;
    	return h;
	}
	pr1=h;
    while(pr1!=NULL && temp < pos-1)
    {
    	pr1=pr1->next;
    	temp++;
	}
    if(pr1==h)  // Or, if(pos==1)
    {
        pr->next=h;
        h=pr;
    }
    else if(pr1==NULL)
    {
    	printf("\nInvalid Position \n");
    	return;
	}
    else
    {
        pr->next=pr1->next;
        pr1->next=pr;
    }
    return h;
};

struct list *del(struct list *h,int num)
{
   struct list *pr,*pr1;
    for(pr=h;pr->next!=NULL;pr=pr->next)
       {
           if(pr->n==num)
           {
               break;
           }
           else
           {
               pr1=pr;
           }
       }
       if(pr->n!=num)
       {
	        printf("\n\n Wrong Input \n\n");
       }
       else if(pr==h)
       {
           h=h->next;
       }
       else
       {
           pr1->next=pr->next;
           free(pr);
       }
    return h;
};


void main()
{
    struct list *head;
    head=NULL;
    int ch=0,num,count=0;
    while(ch!=7)
    {
        printf("\n\n*****MENU*****\n\n");
        printf("\n1. Create \n2. Display \n3. Reverse Display \n4. Node Count \n5. Insert at Any Position \n6. Delete Any Element \n7. Exit");
        printf("\nEnter a Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:count++;
			printf("\nEnter a Number: ");
            scanf("%d",&num);
            head=add(head,num);
            break;

            case 2:display(head);break;

            case 3:if(head==NULL)
            {
            	printf("\n Linked List is Already Empty : NOTHING TO DISPLAY\n");
            	break;
			}
			printf("\nThe List is: \n\n");
			reverse_display(head);
			printf("\n");
			break;

            case 4:node_count(head,count);break;

            case 5:printf("\nEnter a Number to Insert: ");
            scanf("%d",&num);
            head=insert_any(head,num);
            break;

            case 6:if(head==NULL)
            {
            	printf("\n Linked List is Already Empty \n");
            	break;
			}
			printf("\nEnter a Number to Delete: ");
            scanf("%d",&num);
            head=del(head,num);
            break;
        }
    }
}

