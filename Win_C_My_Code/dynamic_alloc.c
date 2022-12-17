#include<stdio.h>
#include<stdlib.h>
void main(){
		int i,n,sum, *ptr;
		printf("How many number you want to insert:");
		scanf("%d",&n);
		ptr=(int*)malloc(n* sizeof(int));
		for(i=0;i<n;i++){
			printf("Enter the %d data one by one:",n);
			scanf("%d",ptr+i);
		}
		printf("You entered the following numbers:");
		for(i=0;i<n;i++){
			printf("%d ",*(ptr+i));
		}
	
}
