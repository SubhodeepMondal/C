#include<stdio.h>
void main()
{
	int a[30][30],b[20][20],c[20][20],i,j,k,sum=0,m,n,p,q;
	printf("Enter the size of the array:");
	scanf("%d%d",&m,&n);
	printf("Enter the array row-wise:");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the size of second array:");
	scanf("%d%d",&p,&q);
	printf("Enter the second array row-wise:");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&b[i][j]);
		}
	}
	if(n!=p){
		printf("You have entered wrong size for array.");
	}
	else{
		for(i=0;i<m;i++){
			for(j=0;j<q;j++){
				for(k=0;k<n;k++){
					sum=sum+a[i][k]*b[k][j];
				}
				c[i][j]=sum;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<q;j++){
		printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
