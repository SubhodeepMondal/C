#include<stdio.h>
#include<math.h>
#define f(x)(3*x-cos(x)-1)
void regula( float *x, float a, float b, int *itr)
{
	*x=a-(b-a)*f(a)/(f(b)-f(a));
	(*itr)++;
	printf("\nIteration no. %3d x= %7.5f\n",*itr,*x);
}
int main()
{
	int itr=0, i;
	float a,b,x2,x3,allerr;
	printf("\n Enter the values of a, and allowed error:\n");
	scanf("%f%f",&a,&allerr);
	for(i=a+1;i<10;i++)
	{
		if(f(a)*f(i)<0)
		
		{
			b=i;
			break;
		}
		else if(f(a)*f(-i)<0)
		{
			b=-i;
			break ;
		}
	}
	printf("The calculated b is :%f\n",b);
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
				printf("\nAfter %d iterations, root = %6.4f\n",itr,x3);
				return 0;
			}
			x2=x3;
		}while(itr<20);
	printf("\nSolution does not converge:\n");
	return 1;
}
