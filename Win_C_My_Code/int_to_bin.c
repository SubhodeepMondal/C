#include<stdio.h>
void main()
{
	int n,a[20],i=0,j,flag=0;
	printf("Enter a decimal number:");
	scanf("%d",&n);
	while(n!=0)
	{
		a[i]=n%2;
		n=n/2;
		i++;
	}
	printf("The binary number of the digit is:");
	n=j=i--;
	for(i--;i>=0;i--)
	printf("%d",a[i]);
	for(i=0;i<=n/2;i++)
	{
		if(a[i]!=a[j])
		{
			flag++;
			break;
		}
		j--;
	}
	if(flag==1)
	printf("\nThe binary string is not palindrome.");
	else
	printf("\nThe binary string is palendrome.");
}
