#include<stdio.h>
int look(int a[][20],int x,int y,int c,int k,int l,int count)
{
	if(a[k][l]==1)
		count++;
	if(k==-1||l==-1)
		return(count);
	if(k==x||l==y)
		return(count);
	if(count==c)
		return count;
	look(a,x,y,c,k-1,l,count);
	look(a,x,y,c,k,l-1,count);
	look(a,x,y,c,k+1,l,count);
	look(a,x,y,c,k,l+1,count);
	return(count);
}
void shop(int a[][20],int x,int y,int c,int k,int l,int count)
{
	int b[20][20],i,j,max=0,cox,coy;
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		{
			printf("before look:\n");
			b[i][j]=look(a,x,y,c,k,l,count);
		}
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		{
			if(b[i][j]>max)
			{
				max=b[i][j];
				cox=i;
				coy=y;
			}
		}
		printf("%d(%d,%d)",max,cox,coy);
}
void main()
{
	static int a[20][20],x,y,n,q,b[20],i,j,k,l,c,count;
	printf("Enter the size of city:");
	scanf("%d%d",&x,&y);
	printf("Enter the no of coffee shop in the area:");
	scanf("%d",&n);
	printf("Enter no of queries:");
	scanf("%d",&q);
	printf("Enter the location of coffee shop:");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&k,&l);
		a[k][l]=1;
	}
	printf("Enter max travelling length for queries:");
	for(i=0;i<q;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<q;i++)
	{
		c=b[i];
		k=l=count=0;
		shop(a,x,y,c,k,l,count);
	}
}
