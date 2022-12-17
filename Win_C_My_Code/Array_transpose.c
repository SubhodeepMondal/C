#include<stdio.h>
struct arra {
	int arr[20][20],n,m;
}a,b,c;
void transpose()
{
	int i,j;
	for(i=0;i<a.n;i++){
		for(j=0;j<a.m;j++){
			c.arr[j][i]=a.arr[i][j];
		}
	}
}
void display()
{
	int i,j;
	for (i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int i,j;
	printf("Enter the size of row and collum:");
	scanf("%d%d",&a.n,&a.m);
	printf("\nEnter the array row wise:");
	for( i=0;i<a.n;i++){
		for( j=0;j<a.m;j++){
			scanf("%d",&a.arr[i][j]);
		}
	}
	
	transpose();
	display();
	
}
