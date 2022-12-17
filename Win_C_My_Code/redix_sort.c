#include<stdio.h>
#include<math.h>
int a[30],n;
void sort(int p)
{
	int i,j,k,temp,one,two;
	for(i=1;i<=p;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				one=pow(10,i);
				two=pow(10,i);
				if(a[j]%one>a[k]%two)
				{
					temp=a[j];
					a[j]=a[k];
					a[k]=temp;
				}
			}
		}
	}
}
void main()
{
	int p,i;
	printf("How many number you want to work with &  enter the size of large number:");
	scanf("%d%d",&n,&p);
	printf("Enter the numbers:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(p);
	for (i=0;i<n;i++)
	printf("%d  ",a[i]);
}
