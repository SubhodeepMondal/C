#include<stdio.h>
int a[20];
int sorting(int low, int high)
{
	int i=low-1,j=low,temp,pivot=a[high];
	for(;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	j=i+1;
	temp=a[high];
	a[high]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int low,int high)
{
	if(low<high)
	{
		int pi=sorting(low,high);
		quicksort(low,pi-1);
		quicksort(pi+1,high);
	}
}
void bubbleSort(int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
}
void insertionSort(int n)
{
	int i,j,key;
	for(i=0;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]> key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}	
}
void main()
{
	int i,n,ch;
	printf("Enter how many value you want to sort:");
	scanf("%d",&n);
	printf("Enter %d numbers:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Which way you want to sort\n1. Bubble sort\n2. Insertion sort \n3. Quick sort:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			bubbleSort(n);
			break;
		case 2:
			insertionSort(n);
			break;
		case 3:
			quicksort(0,n-1);
			break;
	}
	printf("After sorting we get the serise:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
