#include<stdio.h>
long int a[1000000];
int main()
{
	long long int i=0,j,temp=0,n=0,count=0;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("insertion.txt","r+");
	if(fp1==NULL)
			fp1=fopen("insertion.txt","w");
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
	n++;
	ch=fgetc(fp1);
	while(ch!=EOF)
		ch=fgetc(fp1);
	for(i=0;i<n;i++)
	{
		j=i;
		while(j>0&&a[j]<a[j-1])
		{
			count++;
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
			j--;
		}
	}
	fprintf(fp1,"\n%lld\n%lld\n",n,count);
}
