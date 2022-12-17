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
void main()
{
	int i,n;
	printf("Enter how many value you want to sort:");
	scanf("%d",&n);
	printf("Enter %d numbers:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	quicksort(0,n-1);
	printf("After sorting we get the serise:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
