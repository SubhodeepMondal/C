#include<stdio.h>
int fibo( int n, int m ){
	if( n == 0 )
		return 1;
	else
		m = n * fibo(n-1,m);
		return m;
}

void main(){
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	printf("\nFactorial of the number is: %d\n", fibo(n,1));
}
