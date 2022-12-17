#include<stdio.h>
int a[20];
int bubble(int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	printf("The sorted array by using bubble sort is:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
void selection(int n)
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	
	printf("The sorted array by using selection sort is:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
void main()
{
	int i,n,k;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter % d numbers one by one:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("In which method you want to sort the array\n1. for bubble sort.\n2. for selection sort:\n");
	scanf("%d",&k);
	switch(k)
	{
		case 1:
			bubble(n);
			break;
		case 2:
			selection(n);
			break;
	}
}
