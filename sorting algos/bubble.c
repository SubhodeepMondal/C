#include<stdio.h>
long int a[1000000];
int main()
{
	long long int n,i=0,j,temp=0,count=0;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("bubble.txt","r+");
	if(fp1==NULL)
			fp1=fopen("bubble.txt","w");
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			count++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
		fprintf(fp1,"\n%ld\n%lld\n",n,count);
	return 0;
}
