#include<stdio.h>
void main()
{
	int i=0,j=1,l=2,n=0,sum=0,m;
	printf("Enter the value of max:\n");
	scanf("%d",&m);
//	sum+=j;
	while(l<=m)
	{
		printf("%d,%d\n",j,l );
		if(l%2==0)
			sum+=l;
		n=j+l;
		j=l;
		l=n;		
	}
	printf("%d\n",sum );

}