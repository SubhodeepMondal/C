#include<stdio.h>
float a[20][20],c;
void main()
{
	int i,j,k,n;
	printf("Enter how many variable are there:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the co-efficient and constant of no %d equation.\n",i+1);
		for(j=0;j<=n;j++)
		{
			if(j==n)
			printf("Enter the value of constant:");
			else
			printf("Enter the value of x%d:",j+1);
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c=a[j][i]/a[i][i];
			if(i!=j)
			for(k=0;k<=n;k++)
			{
				a[j][k]=a[j][k]-(a[i][k]*c);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\nThe value of x%d=\t%3.2f",i+1,a[i][n]/a[i][i]);
		
	}
}
