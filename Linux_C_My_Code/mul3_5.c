#include<stdio.h>
void main()
{
	int count=0,i=1,n1=0,n=0,m;
	float rem;
	printf("Enter the upper range:");
	scanf("%d",&m);
	while(n<m)
	{
		n=i*15;
		if(n<m)
		{
			count+=n;
		}
		i++;
	}
	i=1;
	n=0;
	while(n<m)
	{
		n=i*3;
		if(n<m && n%15!=0)
			count+=n;
		i++;
	}
	printf("%d\n", count );
	i=1;
	n=0;
	rem=n%15;
	while(n<m)
	{
		n=i*5;
		if(n<m && n%15!=0)
		{
			printf("%d\n",n);
			count+=n;
		}
			
		i++;
	}
	printf("%d\n",count);

}