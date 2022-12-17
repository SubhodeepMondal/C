#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
long *arrPrime;
int isprime(long n)
{
	int flag=0;
	for(int i=2;i<=ceil(sqrt(n)); i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}

void main()
{
	long i, n,count;
	printf("Enter the no to check for prime:");
	scanf("%ld",&n);
//	arrPrime = (long*) malloc((n/4) * sizeof(long));
//	arrPrime[0]=2;
	clock_t begin = clock(),end;
	int flag=isprime(n);
	end = clock();
/*	printf("The prime no in the range:\n");
	for(i=0;i<count;i++)
		printf("%ld\t", arrPrime[i] );
	printf("The no of prime in the range:%ld\n",count);*/
	if(flag==0)
		printf("The no is prime no.\n");
	else
		printf("The no is not a prime no.\n");
	double time_spent=(double)((end-begin))/CLOCKS_PER_SEC ;
	printf("Execution time of the code: %f\n",time_spent);

}