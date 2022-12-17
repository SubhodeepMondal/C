#include<stdio.h>
int a[20][8],n;
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
	int i=0,j=0,k=0;
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
		a[i][7]=a[i][2];
		i++;
	}
	sort();
	i=0;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		sum+=a[i][2];
	}
	i=0;
	while(i<n)
	{
		for(j=0;j<3;j++)
		{	
			if(a[i][2]==0)
				break ;
			else
			{
				if(a[i][6]==0)
				{
					a[i][4]=k;
					a[i][6]=1;
				}
				a[i][2]--;
				k++;
				if(a[i][2]==0)
				{
					a[i][3]=k;
					break ;
				}
			}
		}
		if(k>=sum)
			break;
		i=(i+1)%n;
	}	
	i=0;		
	sum=0;
	while(i!=n)
	{	
		a[i][5]=a[i][3]-a[i][1]-a[i][7];
		printf("\nCompletion time &response time & wating time of process %d:%d,%d,%d",a[i][0],a[i][3],a[i][4],a[i][5]);
		sum+=a[i][5];
		i++;
	}
	v=sum/n;
	printf("\nThe average waiting time is %f",v);
}

	
