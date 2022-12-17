#include "E:\Subho\headers\div.c"
#include "E:\Subho\headers\mul.c"
#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter value for a and b one by one:");
	scanf("%d%d",&a,&b);
	c=multi(a,b);
	printf("C=%d",c);
	c=div(a,b);
	printf("\nC=%d",c);
	
}
