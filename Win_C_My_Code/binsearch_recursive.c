#include<stdio.h>
int item,arr[100];

void binsearch(int first,int last,int middle)
{
	if(last<first)
	{
		printf("The data is not found.");
		return ;	
	}
	else if(arr[middle]==item)
	{
		printf("%d is found at location %d.",item,middle+1);
		return ;
	}
	else if(item>arr[middle])
	first=middle+1;
	else if(item<arr[middle])
	last=middle-1;
	binsearch(first,last,(first+last)/2);
}
void main()
{
	int i,n,first,last,middle;
	printf("How many number you want to insert:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	first=0;
	last=n-1;
	middle=(first+last)/2;
	printf("Enter the value to search:");
	scanf("%d",&item);
	binsearch(first,last,middle);
}
