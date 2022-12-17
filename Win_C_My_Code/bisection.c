#include<stdio.h>
#include<math.h>
#define fun(x)((1-x)*cos(x)-sin(x))
void bisection (float *x,float a, float b, int *itr)
{
	*x=(a+b)/2;
	++(*itr);
	printf("\nIteration no. %3d X =%7.7f",*itr,*x);
}
int main()
{
	int itr=0,maxmitr;
	float i,x,a,b,allerr,x1;
	printf("\nEnter the values of a, allowed eror and maximum no. of iterations:\n");
	scanf("%f%f%d",&a, &allerr, &maxmitr);
	for(i=a+0.1;i<10;i+=0.1)
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
	printf("The calculated value of b=%f",b);
	bisection(&x,a,b,&itr);
	do
	{
		if(fun(a)*fun(x)<0)
			b=x;
		else
			a=x;
			bisection (&x1, a,b,&itr);
			if(fabs(x1-x)<allerr)
			{
				printf("\nAfter %d iterations, root = %6.7f\n",itr,x1);
				return 0;
			}
			x=x1;
	}while(itr<maxmitr);
	printf("\nThe solution does not converge or the iteration is not sufficient for this level of error allowence.");
	return 1;
}
