#include<stdio.h>
#include<conio.h>
void main()
{
	int a[20],b[20],c[20],n,m,sum=0,i,j=0,s,k,l=0,max,min,carry=0;
	printf("Enter the size of a,b:");
	scanf("%d%d",&n,&m);
	printf("Enter the first number:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the first number:");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	if(n>m)
	{
		max=n;
		min=m;
	}
	else
	{
		max=m;
		min=n;
	}
	for(i=0;i<min;i++)
	{
		 while(j<max)
		 {
		 	k=i;
		 	s=j;
		 	sum=0;
		 	while(s>=i)
		 	{
		 		printf("\na:%d b:%d s:%d k:%d",a[s],b[k],s,k);
		 		sum=sum+a[s]*b[k];
		 		k++;
		 		s--;
		 		if(k==min)
		 			break;
			 }
			 sum=sum+carry;
			 printf("\nsum=%d ",sum);
			 printf("i=%d j=%d",i,j);
			 carry=sum/10;
			 c[l]=sum%10;
			 c[l+1]=carry;
			 l++;
			 j++;
		 }
		 j--;
	}
	printf("\n");
	for(i=0;i<2*max;i++)
	printf("%d",c[i]);
}
