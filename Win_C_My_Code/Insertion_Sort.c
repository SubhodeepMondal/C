#include<stdio.h>
int main(){
	int i,j,n,temp,a[10],p[10];
	printf("How many number are there:");
	scanf("%d",&n);
	printf("Enter %d number one by one",n);
	for(i=0;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		p[i]=a[i];
		for(j=i;j>=0;j--){
			if(i==0) goto l1;
			if(p[j-1]>p[j]){
				temp=p[j];
				p[j]=p[j-1];
				p[j-1]=temp;
			}
		}
		l1:		
	}
	for(i=0;i<n;i++)
	printf("%d ",p[i]);
	return 0;
}
