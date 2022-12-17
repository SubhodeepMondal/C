#include<stdio.h>
struct coffee
{
	 int flag1,flag2;
}a[20][20];
int look(int x,int y,int c,int k,int l,int count,int m,int p,int q)
{
	printf("a[%d][%d]=%d,m=%d,count:%d\n",k,l,a[k][l],m,count);
	if(k==-1||l==-1||k==x||l==y)
	{
		printf("from if(k==-1||l==-1||k==x||l==y)\n");
		return(count);
	}
	if(a[k][l].flag1==1&&a[k][l].flag2==0)
	{
		count++;
		a[k][l].flag2=1;
	}
	if(m==c)
	{
		printf("from if(m==c)\n");
		return(count);
	}
	if(p!=k+1)
	{
		p=k;q=l;
		printf("k+1,l\n");
		count=look(x,y,c,k+1,l,count,m+1,p,q);
	}
	if(q!=l+1)
	{
		p=k;q=l;
		printf(" 	k,l+1\n");
		count=look(x,y,c,k,l+1,count,m+1,p,q);
	}
	if(p!=k-1)
	{
		p=k;q=l;
		printf(" 		k-1,l\n");
		count=look(x,y,c,k-1,l,count,m+1,p,q);
	}
if(q!=l-1)
	{
		p=k;q=l;
		printf(" 				k,l-1\n");
		count=look(x,y,c,k,l-1,count,m+1,p,q);
	}
	printf("from end of function\n");
	return(count);
}
void clear(int x,int y)
{
	int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<y;j++)
	a[i][j].flag2=0;
}
void shop(int x,int y,int c,int k,int l,int count,int m)
{
	static int b[20][20],i,j,max=0,cox,coy,p,q;
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		{
			printf("before look:%d\n",c);
			p=i;
			q=j;
			b[i][j]=look(x,y,c,i,j,count,m,p,q);
			clear(x,y);
			printf("after look:%d\n",b[i][j]);
		}
	for(i=0;i<x;i++)
	{
	
		printf("\n");
		for(j=0;j<y;j++)
		{
			printf("%d ",b[i][j]);
			if(b[i][j]>max)
			{
				max=b[i][j];
				cox=i;
				coy=j;
			}
		}
	}
	printf("\n%d(%d,%d)",max,cox+1,coy+1);
}
void main()
{
	static int x,y,n,q,b[20],i,j,k,l,c,count,m;
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
		a[k-1][l-1].flag1=1;
	}
	printf("Pattern of coffee shop:");
		for(i=0;i<x;i++)
		{
			printf("\n");
			for(j=0;j<y;j++)
				printf("%d ",a[i][j]);
		}
	printf("\nEnter max travelling length for queries:");
	for(i=0;i<q;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<q;i++)
	{
		c=b[i];
		k=l=count=0;
		shop(x,y,c,k,l,count,m);
	}
}
