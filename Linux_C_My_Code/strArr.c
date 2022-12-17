#include <stdio.h>
#include <string.h>

void FindIntersection(char * strArr[],int arrLength)
{
	int flag1 =0,j=0,i=0,k,count1=0,count2=0,count=0;
  	char tar1[10], tar2[10],*table1[10][10],*table2[10][10],table3[20];
  	printf("Output:\n");
  	for (i=0 ; i< strlen(strArr[0]);i++)
  	{
  		k=0;
    	while(strArr[0][i]!=',' && i<strlen(strArr[0]))
    	{
    		tar1[k]=strArr[0][i];
      		i++;
      		k++;
    	}

      	count1++;
    	tar1[k]='\0';
    	printf("%s:%d:%d\n",tar1,i,k);
    	strcpy(table1[j],tar1);
    	i++;
    	j++;
    }

    j=0;
    printf("1:%d\n",strlen(strArr[1]) );
    for(i=0; i< strlen(strArr[1]); i++)
    {
    	k=0;
    	while(strArr[1][i]!=',' && i<strlen(strArr[1]))
    	{
      		tar2[k]=strArr[1][i];
      		k++;
      		i++;
    	}

      	count2++;
    	tar2[k]='\0';
    	strcpy(table2[j],tar2);
    	printf("%s:%s:%d:%d:%d\n",table2[j],tar2,i,j,k);
    	i++;
    	j++;
    }

    for(i=0;i<count1;i++)
    {
    	for(j=0;j<count2;j++)
    	{
	    	if(strcmp(table1[i],table2[j])==0)
	    	{
	     		if(flag1!=0)
	     			printf(",");
	        	printf("%s",table1[i]);
	        	flag1=1;
	        	break;
	    	}
    	}		
    }
    printf("\n");    	
}

int main()
{
	char * A[]={"1, 3, 4, 8, 13", "1, 2, 4, 13, 15"};
	int arrLength = sizeof(A)/sizeof(*A);
	FindIntersection(A,arrLength);
	return 0;
}