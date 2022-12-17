#include<stdio.h>
void main()
{
	int a,b,evl=0;
	printf("Enter first & second number:");
	scanf("%d%d",&a,&b);
	while(a!=0)
	{
		printf("\na:%d\tb:%d\tcal:%d",a,b,evl);
		if(b==0)
			break;
		if(a%2!=0)
			evl+=b;
		else 
			printf("\tx");
		b*=2;
		a/=2;
		
	}
	printf("\nResult is:%d",evl);
}
