
#include<stdio.h>
void main()
{
	char a[20],temp;
	int n,i,j;
	printf("How many string are there:");
	scanf("%d",&n);
	printf("\nEnter %d strings one by one(Single case letters only):",n);
	for(i=0;i<n;i++)
	{
		
		scanf("%s",&a[i]);
		for(j=i;j>0;j-- )
		{
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
	printf("\nThe sorted list is:");
	for(i=0;i<n;i++)
		printf("%c %d ",a[i],a[i]);
}
