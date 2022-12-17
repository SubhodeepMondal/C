#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
	char ch[25];
	struct string *next;
}string;

void findSubString(char *ch,string **ptr)
{
	int i,j,k;
	string *strCurr, *strPrev;
	for(i=0;i<strlen(ch);i++)
	{
//		printf("In first for loop\n");
		strCurr= (string *)malloc(sizeof(string));
		if(*ptr==NULL)
		{
			*ptr = strCurr;
			strPrev=strCurr;
			strCurr->next=NULL;
		}
		else
		{
			strPrev->next=strCurr;
			strPrev=strCurr;
			strCurr->next=NULL;
		}

		k=0;

		for(j=i;j<strlen(ch);j++)
		{
			if(i==j)
			{
				strCurr->ch[k]=ch[j];
			}
			else if( strCurr->ch[k-1]-ch[j] == -1 )
			{
				strCurr->ch[k]=ch[j];
			}
			else
				break;
			k++;
		}
		i=j-1;
	}
}
void sortList(string **ptr)
{
	string *ptrNext, *temp, *ptrCurr, *ptrPrev, *ptrEx;
	ptrEx =	(*ptr);
	while(ptrEx)
	{
		ptrCurr = (*ptr);
		ptrPrev = ptrCurr;
		ptrNext = ptrCurr->next;
		if(ptrCurr->ch[0] > ptrNext->ch[0])
		{
			(*ptr) = ptrNext;
			ptrEx = (*ptr);
			ptrCurr->next = ptrNext->next;
			ptrNext->next = ptrCurr;
			ptrPrev = ptrNext;
			ptrNext = ptrCurr->next;
		}
		else
		{
			ptrCurr = ptrCurr->next;
			ptrNext = ptrNext->next;
		}
		while(ptrNext)
		{
			if(ptrCurr->ch[0] > ptrNext->ch[0])
			{
				ptrPrev->next = ptrNext;
				ptrCurr->next = ptrNext->next;
				ptrNext->next = ptrCurr;
				ptrPrev = ptrNext;
				ptrNext = ptrCurr->next;
			}
			else
			{
				ptrPrev = ptrPrev->next;
				ptrCurr = ptrCurr->next;
				ptrNext = ptrNext->next;
			}
		}
		ptrEx = ptrEx->next;

	}
}

void print(string *ptr)
{
	while(ptr)
	{
		printf("%s\n",ptr->ch );
		ptr = ptr -> next;
	}
}

void main()
{
	int i,j,k;
	char ch[100];
	scanf("%s",ch);

	string *head=NULL;

	findSubString(ch,&head);
	print(head);
	printf("After sort listing is:\n");
	sortList(&head);
	print(head);

}