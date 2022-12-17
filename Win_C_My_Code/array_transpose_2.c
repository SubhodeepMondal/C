#include<stdio.h>
void main()
{
	int a[20][20],c[20][20],n,m,i,j;
	printf("Enter the size of row and collum:");
	scanf("%d%d",&n,&m);
	printf("\nEnter the array row wise:");
	for( i=0;i<n;i++){
		for( j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c[j][i]=a[i][j];
		}
	}
	printf("\n");
	for (i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}

}

