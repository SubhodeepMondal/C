#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
long *arrPrime;
void isprime(long n, long *count)
{
	*count=1;
//	printf("%ld,%ld\n",n, *count );
	int flag,k=1,m;

	for(long i=3;i<=n;i++)
	{
//		printf("%d,%d\n",i, *count );
		flag =0;
//		printf("%d,%d\n",n, *count );
//		printf("%d,%d\n",m, *count );
		if(*count>0)
		{
//			printf("%d,%d\n",n, *count );
			
			for(long j=0; j<*count && arrPrime[j]<=ceil(sqrt(i)) ;j++)
			{
//				printf("%ld\n",arrPrime[j]);
				if(i%arrPrime[j] == 0 )
				{
					flag =1;
					break;
				}
			}
		}
/*		else
		{
			for(int j=arrPrime[*count]; j<= i/2;j++)
			{
				printf("%d,%d\n",j, *count );
				if(i%j == 0)
				{
					flag =1;
					break;
				}
			}
		}*/
		

		if(flag==0)
		{
			arrPrime[k]=i;
			*count+=1;
//			printf("The no of prime in the range:%ld\t",arrPrime[k]);
//			printf("%ld,%f\n",arrPrime[k],ceil(sqrt(i)));

			k++;
		}
	}
}

void main()
{
	long i, n,count;
	printf("Enter the upper range to find prime no in:");
	scanf("%ld",&n);
	arrPrime = (long*) malloc((n/4) * sizeof(long));
	arrPrime[0]=2;
	clock_t begin = clock(),end;
	isprime(n,&count);
	end = clock();
//	printf("The prime no in the range:\n");
	for(i=0;i<count;i++)
		printf("%ld\t", arrPrime[i] );
	printf("The no of prime in the range:%ld\n",count);
	double time_spent=(double)((end-begin))/CLOCKS_PER_SEC ;
	printf("Execution time of the code: %f\n",time_spent);

}