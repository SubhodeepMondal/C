#include<stdio.h>
long int a[1000050],count=0;
int sorting(int low, int high)
{
	int i=low-1,j=low,temp,pivot=a[high];
	for(;j<high;j++)
	{
		count++;
		if(a[j]<=pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	j=i+1;
	temp=a[high];
	a[high]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int low,int high)
{
	if(low<high)
	{
		int pi=sorting(low,high);
		quicksort(low,pi-1);
		quicksort(pi+1,high);
	}
}
void main()
{
	long int i,n,temp;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("Quick_sort.txt","r+");
		if(fp1==NULL)
			fp1=fopen("Quick_sort.txt","w");
	fp2=fopen("input.txt","r");
	ch=fgetc(fp2);
	while(ch!=EOF)
	{
		if(ch==',')
		{
			a[i]=temp;
			temp=0;
			i++;
			n++;
			
		}
		else
			temp=temp*10+(ch-'0');
		ch=fgetc(fp2);
	}
	ch=fgetc(fp1);
	while(ch!=EOF)
		ch=fgetc(fp1);
	quicksort(0,n-1);
	fprintf(fp1,"\n%ld\n%ld\n",n,count);
}
