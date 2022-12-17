#include<stdio.h>
#include<math.h>
#define fun(x) (3*x-cos(x-1))
void method(float a,float b, float *x,int *k)
{
	*x=a+abs(fun(a))*((b-a)/(abs(fun(a))+abs(fun(b))));
	(*k)++;
	printf("Iteration no. %3d x=%7.5f\n",*k,*x);
}
void main()
{
	float a,b,n,x,x1,allerr;
	int i,maxitr,k=0;
	printf("Enter a and b and number of iteration and allowed error:");
	scanf("%f%d%f",&a, &maxitr, &allerr);
	for(i=a+1;i<10;i++)
	{
		if(fun(a)*fun(i)<0)
		
		{
			b=i;
			break;
		}
		else if(fun(a)*fun(-i)<0)
		{
			b=-i;
			break ;
		}
	}
	method(a,b,&x,&k);
	do
	{
		if(fun(x)<0)
			a=x;
		else
			b=x;
		method(a,b,&x1,&k);
		if(fabs(x1-x)<allerr)
		{
			printf("After %d iteration the root is :%6.5f\n",k,x1);
		}
		
		x=x1;
	}while(k<maxitr);
}
