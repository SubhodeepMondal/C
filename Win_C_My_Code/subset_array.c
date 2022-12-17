#include<stdio.h>
void main()
{
	int i,a[20],r,n,b[20],c[20],k=0,l=0;
	printf("How many numbers are there:");
	scanf("%d",&n);
	printf("Enter %d numbers:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	r=a[0];
	b[k++]=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<r)
			b[k++]=a[i];
		if(a[i]>r)
			c[l++]=a[i];
	}
	printf("The first subset:");
	for(i=0;i<k;i++)
		printf("%d ",b[i]);
	printf("\nThe second subset:");
	for(i=0;i<l;i++)
		printf("%d ",c[i]);
	getch();
}
