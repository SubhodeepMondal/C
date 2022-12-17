#include<stdio.h>
void main()
{
	int a,b,sum=0;
	printf("Enter first number:");
	scanf("%d",&a);
	printf("Enter second number:");
	scanf("%d",&b);
	while(a/2!=0)
	{
		sum=sum+b*2;
		a/=2;
	}
	printf("Result is:",sum);
}
