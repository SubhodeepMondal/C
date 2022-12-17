#include <stdio.h>
#include "add.c"
#include "sub.c"
#include "E:\Subho\headers\div.c"
#include "E:\Subho\headers\mul.c"
void main()
{
	int a,b,c;
	printf("Enter first and second no. one by one:");
	scanf("%d %d",&a,&b);
	c=add(a,b);
	printf("C=%d",c);
	c=sub(a,b);
	printf("\nC=%d",c);
	c=multi(a,b);
	printf("\nC=%d",c);
	c=div(a,b);
	printf("\nC=%d",c);
}
