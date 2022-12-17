#include<stdio.h>
int a[20][3],n,b[20][5];
void sort()
{
	int j,i,k,temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j][1]>a[j+1][1])
			{
				k=0;
				while(k<3)
				{	
					temp=a[j+1][k];
					a[j+1][k]=a[j][k];
					a[j][k]=temp;
					k++;
				}
			}
		}
}
void main() //main() starts here!!!
{
	int i=0,j;
	float v,sum=0;
	printf("How many processes are there:");
	scanf("%d",&n);
	while(i!=n)
	{
		printf("Enter the process id:");
		scanf("%d",&a[i][0]);
		printf("Enter the arrival time:");
		scanf("%d",&a[i][1]);
		printf("Enter the execution time:");
		scanf("%d",&a[i][2]);
		i++;
	}
	sort();
	i=0;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			b[i][0]=a[i][2];
		else
			b[i][0]=b[i-1][0]+a[i][2];
		if(i==0)
			b[i][1]=0;
		else
			b[i][1]=b[i-1][0];
		if(i==0)
			b[i][2]=0;
		else
			b[i][2]=b[i][1]-a[i][1];
	}		
	i=0;		
	
	while(i!=n)
	{	
		printf("\nCompletion time &response time & wating time of process %d:%d,%d,%d",a[i][0],b[i][0],b[i][1],b[i][2]);
		sum+=b[i][2];
		i++;
	}
	v=sum/n;
	printf("\nThe average waiting time is %f",v);
}

	
