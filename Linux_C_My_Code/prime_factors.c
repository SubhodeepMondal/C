#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long *arrPrime;
int count=0;
int isPrime(int n)
{
	int flag =0;
	for(int i=arrPrime[0];i<=ceil(sqrt(n));i++)
	{
		if(n%i == 0)
		{
			flag =1;
			break;

		}
	}
	return flag;
}
void factors(int n)
{
	if()
}
void main()
{
	long n;
	int flag;
	printf("enter the range of number:\n");
	scanf("%ld",&n);
	arrPrime=(long *) malloc(n/4 * sizeof(long));
	arrPrime[0]= 2;
	count++;
	for(int i=3;i<=n;i++)
	{
		flag = isPrime(i);
		if( flag ==0)
		{
			arrPrime[count]=i;
			count++;
		}
	}
	for (int i = 0; i < count; ++i)
	{
		/* code */
		printf("%ld\n", arrPrime[i]);
	}
	printf("%d\n", count );
}
