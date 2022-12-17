#include<stdio.h>
static int a[20][10],n;
int swap(int index1,int index2,int time)						//to sort queue;
{
	int i,j,temp,dif;
	for(i=0;i<n-1;i++)
	{
		if(a[i][index1]>a[i+1][index1]||(a[i][index1]==a[i+1][index1]&&a[i][index2]>a[i+1][index2])||a[i][index2]==0)
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
	/*printf("\nP_ID\tA.T.\tB.T.\tB.T.\tR.T.\tC.T.\tW.T.");
	for(i=0;i<n;i++)
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);*/
	dif=a[0][1]-time;
	if(dif<0)
		dif=0;
	return dif;
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
				a[i][3]=a[i][j];
		}
		fgetc(fp);
	}
	for(i=0;i<n;i++)
		j=swap(1,3,0);
	printf("\nProcessing:\nGnatt Chart:");
	j=0;
	while(a[j][3]!=0)
	{
		printf("%d_P%d_",t,a[0][0]);
		a[j][4]=t;
		a[j][5]=t+a[j][2];
		a[j][6]=a[j][5]-a[j][1]-a[j][2];
		a[j][3]-=a[j][3];
		t+=a[j][2];
		sum+=a[j][6];
		printf("%d_",a[j][5]);
		dif=swap(1,3,t);
		t+=dif;
		if(dif!=0)
			printf("cpu_idle_");
	}
	printf("end\n");
	for(i=0;i<n;i++)
		t=swap(0,1,0);
	printf("\nP_ID\tA.T.\tB.T.\tR.T.\tC.T.\tW.T.");
	for(i=0;i<n;i++)
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",a[i][0],a[i][1],a[i][2],a[i][4],a[i][5],a[i][6]);
	printf("\nTotal waiting time of all process:%f\nAverage waiting time for each process:%f",sum,sum/n);
}
