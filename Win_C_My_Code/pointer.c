#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *pt,**ptr,x;
	x=90;
	pt=&x;
	ptr=&pt;
	printf("ptr=%d\n*ptr=%d\n**ptr=%d\n&(*ptr)=%d\n",ptr,*ptr,**ptr,&(*ptr));
	printf("address of x=%d\naddress of pt=%d\naddress of ptr=%d",&x,&pt,&ptr);
}
