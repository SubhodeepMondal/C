#include<stdio.h>
void main()
{
	int i,j,min,temp,n,a[20];
	printf("Enter the size of the array:\n");
	scanf("%d", &n);
	printf("Enter %d numbers:\n",n);
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	
	for(i=0;i<(n-1);i++)
	{
		min=i;
		printf("%d ",min);
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
			
		}
		printf("%d\n",min);
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	
	printf("The sorted array is:");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
