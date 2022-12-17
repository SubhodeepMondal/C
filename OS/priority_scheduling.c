#include<stdio.h>
static int a[20][10],n;
void sort(int index)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j][index]>a[j+1][index])
			{
				k=0;
				while(k<4)
				{
					temp=a[j][k];
					a[j][k]=a[j+1][k];
					a[j+1][k]=temp;
					k++;
				}
			}
		}
	printf("P_ID\tA.T.\tB.T.\tPr.");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<4;j++)
		printf("%d\t",a[i][j]);
	}
	printf("\n");
}
int checkPriority(int time,int index)
{
	int i,j,k,temp,dif;
	dif=a[index][1]-time;
	if(dif<0)
		dif=0;
	for(i=index;i<n-1;i++)
	{
		for(j=index;j<n-1;j++)
		{
			if(a[j][1]<=time+dif&&a[j+1][1]<=time+dif)
			{
				if(a[j][3]>a[j+1][3])
				{
					k=0;
					while(k<4)
					{
						temp=a[j][k];
						a[j][k]=a[j+1][k];
						a[j+1][k]=temp;
						k++;
					}
				}
			}
		}
	}
	if(dif>0)
		printf("Cpu was idle for :%dms after process P_ID:%d",dif,index-1);
	return dif;
}
void main()
{
	static int i,j,t;
	float sum;
	char ch;
	FILE *fp;
	fp=fopen("input.txt","r");
	ch=fgetc(fp);
	n=ch-'0';
	fgetc(fp);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			ch=fgetc(fp);
			a[i][j]=ch-'0';
		}
		fgetc(fp);
	}
	printf("Number of processes:%d\n",n);
	sort(1);
	j=0;
	while(j<n)
	{
		t+=checkPriority(t,j);
		a[j][4]=t;
		a[j][5]=a[j][2]+t;
		a[j][6]=a[j][4]-a[j][1];
		sum+=a[j][6];
		t+=a[j][2];
		j++;
	}
	printf("\nP_ID\tA.T.\tB.T.\tPr.\tR.T.\tC.T.\tW.T.");
	for(i=0;i<n;i++)
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);
	printf("\nAverage waiting time for each process:%f",sum/n);
}
