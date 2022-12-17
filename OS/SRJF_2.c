#include<stdio.h>
static int a[20][10],n,p;
int swap(int time)						//to sort queue;
{
	int i,j,temp,dif;
	for(i=0;i<p-1;i++)
	{
		if((a[i+1][1]<=time&&a[i][3]>a[i+1][3]))
		{
			j=0;
			while(j<7)
			{
				temp=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=temp;
				j++;
			}
		}
	}
	for(i=0;i<p-1;i++)
	{
		if(a[i][3]==0)
		{
			j=0;
			while(j<7)
			{
				temp=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=temp;
				j++;
			}
		}
	}
	if(a[i][3]==0)
	p--;	
}
void main()
{
	static int i,j,t,tq,bt,dif;
	float sum=0;
	char ch;
	FILE *fp;
	fp=fopen("input.txt","r");
	ch=fgetc(fp);			//taking input from file;
	n=ch-'0';
	p=n;
	ch=fgetc(fp);
	tq=ch-'0';
	fgetc(fp);
	printf("Number of processes:%d\n",n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			ch=fgetc(fp);
			a[i][j]=ch-'0';
			if(j==2)
			{
				bt+=a[i][j];
				a[i][3]=a[i][j];
			}
		}
		fgetc(fp);
	}
	printf("\nProcessing:");
	t=0;
	j=0;
	while(t<=bt)
	{
		swap(t);
		if(a[j][2]==a[j][3])
			a[j][4]=t;
		a[j][3]--;
		t++;
		if(a[j][3]==0)
		{
			a[j][5]=t;
			a[j][6]=a[j][5]-a[j][2]-a[j][1];
		}
	}
	printf("\nP_ID\tA.T.\tB.T.\tR.T.\tC.T.\tW.T.");
	for(i=0;i<n;i++)
	{	
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",a[i][0],a[i][1],a[i][2],a[i][4],a[i][5],a[i][6]);
		sum+=a[i][6];
	}
	printf("\nTotal waiting time of all process:%f\nAverage waiting time for each process:%f",sum,sum/n);
}
