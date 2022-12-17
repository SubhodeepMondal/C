#include<stdio.h>
long int a[100000],count=0;
void swap(int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void maxheap(int n,int i)
{
	count++;
	int large=i,l=i*2+1,r=i*2+2;
	if(l<n&&a[l]>a[large])
		large=l;
	if(r<n&&a[r]>a[large])
		large=r;
	if(large!=i)
	{
		swap(i,large);
		maxheap(n,large);
	}
	
}
void heapsort(int n)
{
	int i=0,temp,j=n;
	for(i=n/2-1;i>=0;i--)
		maxheap(n,i);
	for( i=n-1;i>=0;i--)
	{
		swap(0,i);
		maxheap(i,0);
	}
}
void main()
{
	long int i,n,temp;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("Heap_sort.txt","r+");
		if(fp1==NULL)
			fp1=fopen("Heap_sort.txt","w");
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
	heapsort(n);
	fprintf(fp1,"\n%ld\n%ld\n",n,count);
}
