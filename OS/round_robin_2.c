#include<stdio.h>
static int a[20][10],n;
int swap(int index1,int index2,int time)						//to sort queue;
{
	int i,j,temp,dif;
	for(i=0;i<n-1;i++)
	{
		if((a[i][index1]>=a[i+1][index1]&&a[i+1][index2]!=0)||a[i][index2]==0)
		{
			j=0;
			while(j<8)
			{
				temp=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=temp;
				j++;
			}
		}
	}
	dif=a[0][4]-time;
	if(dif<0)
		dif=0;
	return dif;
}
void main()
{
	static int i,j,t,tq,bt,dif;
	float sum;
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
			if(j==1)
				a[i][4]=a[i][j];
			if(j==2)
				a[i][3]=a[i][j];
		}
		fgetc(fp);
	}
	for(i=0;i<n;i++)
		j=swap(4,2,0);
	printf("\nProcessing:\nGnatt Chart:");
	j=0;
	while(a[j][3]!=0)
	{
		printf("%d_P%d_",t,a[0][0]);
		if(a[j][1]==a[j][4])
			a[j][5]=t;		//Calculation of response time;
		if(a[j][3]<=tq) 	//Calculation of completion time;
		{
			a[j][6]=a[j][3]+t;
			t+=a[j][3];
			a[j][3]=0;
		}
		else
		{
			a[j][3]-=tq;
			t+=tq;
		}
		i=1;
		bt=t;
		while(i<n)			//Calculation to maintain queue;
		{
			if(a[i][3]<tq)
				bt+=a[i][3];
			else
				bt+=3;
			a[0][4]=bt;
			if(bt<a[i+1][4]&&a[0][3]!=0)
				break;		
			i++;
		}
		if(a[j][3]==0)		//Calculation of waiting time;
		{
			a[j][7]=a[j][6]-a[j][2]-a[j][1];
			sum+=a[j][7];
		}
		printf("%d_",t);
		dif=swap(4,3,t);
		t+=dif;
		if(dif!=0)
			printf("cpu_idle_");
	}
	printf("end\n");
	for(i=0;i<n;i++)
		t=swap(0,2,0);
	printf("\nP_ID\tA.T.\tB.T.\tR.T.\tC.T.\tW.T.");
	for(i=0;i<n;i++)
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",a[i][0],a[i][1],a[i][2],a[i][5],a[i][6],a[i][7]);
	printf("\nAverage waiting time for each process:%f",sum/n);
}
