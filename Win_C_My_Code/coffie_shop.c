#include<stdio.h>
void main()
{
	int a[50],b[50],n,q,i,j,x,y,dis[20];
	printf("Enter the size of the city:");
	scanf("%d%d",&x,&y);
	printf("Number of coffie shopes are there:");
	scanf("%d",&n);
	printf("Number of quaries:");
	scanf("%d",&q);
	printf("Enter co_ordinates for coffie shopes:");
	for(i=0;i<n;i++)
	{
		printf("Enter value for (x,y)of no %d coffie shop:",i+1);
		scanf("&d&d",&a[i],&b[i]);
	}
	printf("Enter distance value for %d queries:");
	for(i=0;i<q;i++)
	{
		scanf("%d",&dis[i]);
	}
	
}
