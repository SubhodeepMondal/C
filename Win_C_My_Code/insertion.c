#include<stdio.h>
void main()
{
	int i,j,temp,n,a[20];
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	printf("Enter %d numbers one by one.\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		j=i;
		while(j>0&&a[j]<a[j-1])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			j--;
		}
	}
	printf("Sorted list in ascending order:\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
