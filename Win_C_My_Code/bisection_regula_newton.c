#include<stdio.h>
#include<math.h>
#define fun(x)(pow(x,3)-3*x+1.06)
#define f(x)(x*x*x+2*x-2)
#define f1(x)(x*x*x-8*x-4)
#define f2(x)(3*x*x-8)
void bi (float *x,float a, float b, int *itr)
{
	*x=(a+b)/2;
	++(*itr);
	printf("Iteration no. %3d X =%7.5f\n",*itr,*x);
}
int bisection()
{
	int itr=0,maxmitr;
	float  x,a,b,allerr,x1;
	printf("\nEnter the values of a, b, allowed eror and maximum iterations:\n");
	scanf("%f %f %f %d",&a, &b, &allerr, &maxmitr);
	bi(&x,a,b,&itr);
	do
	{
		if(fun(a)*fun(x)<0)
			b=x;
		else
			a=x;
		bi(&x1, a,b,&itr);
		if(fabs(x1-x)<allerr)
		{
			printf("After %d iterations, root = %6.3f\n",itr,x1);
			return 0;
		}
		x=x1;
	}while(itr<maxmitr);
	printf("The solution does not converge or the iteration is not sufficient for this level of error allowence.");
	return 1;
}
void regula( float *x, float a, float b, int *itr)
{
	*x=a-(b-a)*f(a)/(f(b)-f(a));
	(*itr)++;
	printf("Iteration no. %3d x= %7.5f\n",*itr,*x);
}
int regula_falsi()
{
	int itr=0, maxitr;
	float a,b,x2,x3,allerr;
	printf("\n Enter the values of a, b, allowed error and max num of iteration:\n");
	scanf("%f%f%f%d",&a,&b,&allerr,&maxitr);
	regula(&x2,a,b,&itr);
		do
		{
			if(f(a)*f(x2)<0)
			a=x2;
			else
			b=x2;
			regula(&x3,a,b,&itr);
			if(fabs(x3-x2)<allerr)
			{
				printf("After %3d iterations, root =%6.4f",itr,x3);
				return 0;
			}
			x2=x3;
		}while(itr<maxitr);
	printf("solution does not converge or iterations not sufficient:\n");
	return 1;
}
void newton(float *x,float a, int *itr)
{
	*x=a-f1(a)/f2(a);
	(*itr)++;
	printf("Iteration no. %3d, x= %7.6f.\n",*itr,*x);
}
int newton_ralpson()
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
void main()
{
	int n;
	printf("Enter your choice \n1. bisection.\n2. regula falsi.\n3. newton_ralpson.\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		bisection(); break;
		case 2:
			regula_falsi(); break;
		case 3:
			newton_ralpson(); break;
		
	}
}
