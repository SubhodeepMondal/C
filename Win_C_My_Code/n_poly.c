#include<stdio.h>
#include<math.h>
#define pi 3.142857142
void main()
{
	double area=0,pari=0,a[20];
	int n,i;
	printf("Enter the number of segments:");
	scanf("%d",&n);
	printf("Enter length of each segment:");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
		pari=a[i]+pari;
	}
	for(i=0;i<n;i++)
	{
		area=area+((a[i]/2)*(a[i]/2)*(1/tan(pi*a[i]/pari)));
	}
	printf("\nMax area that can be covered by given segments is: %lf sq. unit",area);
}
