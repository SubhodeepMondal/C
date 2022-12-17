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
//			printf("%c,%c\n", strCurr->ch[k], ch[j] );
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
	string *ptrNext,*temp, *ptrCurr,*ptrPrev;
	ptrNext=(*ptr)->next;
	ptrCurr=(*ptr)->next;
	while(ptrCurr)
	{
		printf("In 1st While\n");
		
		while(ptrNext)
		{
			printf("In 2nd While\n");
			if((*ptr)->ch[0]>ptrNext->ch[0])
			{
				printf("In  1st if\n");
				temp = *ptr;
				(*ptr)->next = ptrNext->next;
				*ptr = ptrNext;
				ptrNext->next = temp;
				ptrPrev=(*ptr)->next;
				ptrNext =ptrNext->next;
				ptrCurr= (*ptr)->next;
			}

			if(ptrNext->ch[0]<ptrCurr->ch[0])
			{
				printf("In  1st if\n");
				printf("%c %c\n",ptrCurr->ch[0],ptrNext->ch[0]);
				temp = ptrCurr;
				ptrCurr->next = ptrNext->next;
				ptrCurr=ptrPrev;
				ptrNext->next = temp;
				ptrPrev=ptrNext;
			}
			ptrNext = ptrNext->next;
		}
		ptrCurr = ptrCurr->next;
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
	sortList(&head);
	print(head);

}