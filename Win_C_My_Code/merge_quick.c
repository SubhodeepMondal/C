#include<stdio.h>
int a[20],b[20];
void merging(int low, int mid, int high) 
{
   int l1, l2, i;
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   while(l1 <= mid)    
      b[i++] = a[l1++];
   while(l2 <= high)   
      b[i++] = a[l2++];
   for(i = low; i <= high; i++)
      a[i] = b[i];
}
void sort(int low, int high) 
{
   int mid;
   if(low < high) 
   {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } 
   else 
   { 
      return;
   }   
}
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
	int i,k,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter %d numbers one by one:\n",n);
	for(i=0;i<n;i++)
	scanf("%d", &a[i]);
	printf("Which method you want to use to sort the array.(1 for merge. 2 for quick sort):");
	scanf("%d",&k);
	switch(k)
	{
		case 1:
			sort (0,n);
			printf("\nList after sorting using merge sort\n");
   			for(i = 1; i <= n; i++)
      		printf("%d ", a[i]);
			break;
		case 2:
			quicksort(0,n-1);
			printf("\nAfter sorting we get the serise using quicksort:\n");
			for(i=0;i<n;i++)
			printf("%d ",a[i]);
			break;
	}
}
