#include<stdio.h>
#include<math.h>
#define f1(x)(x*x*x-8*x-4)
#define f2(x)(3*x*x-8)
void newton(float *x,float a, int *itr)
{
	*x=a-f1(a)/f2(a);
	(*itr)++;
	printf("Iteration no. %3d, x= %7.6f.\n",*itr,*x);
}
int main()
{
	int itr=0,maxitr;
	float a,x1,x2,allerr;
	printf("Enter value of a, allower error, number of iterations.\n");
	scanf("%f%f%d",&a,&allerr,&maxitr);
	newton(&x1,a,&itr);
	do
	{
		a=x1;
		newton(&x2,a,&itr);
		if(fabs(x2-x1)<allerr)
		{
			printf("After %3d iterations, root= %6.5f",itr,x1);
			return 0;
		}
		x1=x2;
	}while(itr<maxitr);
	printf("solution does not converge or iterations not sufficient:\n");
	return 1;
}
