#include<stdio.h>
int power(int x,int y)
{
	int sum;
	if(y==0)
	return 1;
	sum=x*power(x,y-1);
	return (sum);
}
void main()
{
	int x,y;
	printf("Enter the number and power:");
	scanf("%d%d",&x,&y);
	
	printf("The power of the product is:%d",power(x,y));
}
