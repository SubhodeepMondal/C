#include<stdio.h>
int fibo(int x,int y,int n)
{
	if(n==0)
	{
		return 0;
	}
	printf(" %d",x);
	fibo(y,x+y,n-1);
}
void main()
{
	int n;
	printf("How many numbers you want to enter:");
	scanf("%d",&n);
	printf("Your fibonacci serise is :");
	fibo(0,1,n);
}
