#include<stdio.h>
#include<math.h>
static int n,b[20];
static char a[20][20];
check(char ch)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[0][i]==ch)
			break;
		if(a[0][i]==0)
		{
			a[0][i]=ch;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i][0]==ch)
			break;
		if(a[i][0]==0)
		{
			a[i][0]=ch;
			break;
		}
	}
}
place(char ch1,char ch2)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(ch1==a[0][i])
		{
			for(j=0;j<=n;j++)
				if(a[j][0]==ch2)
				{
					a[i][j]=1;
					break;
				}
		}
		break;	
	}
}
pos(char ch,int flag)
{ 
	int i;
	for(i=1;i<=n;i++)
	{
		if(ch==a[i][0]&&flag==0)
			return i;
		if(ch==a[0][i]&&flag==1)
			return i;
	}
}
int req(int m,int p,int q,int i,int j)
{
	if(i==n)
		return m;
	if(i==q)
	{
		if(97>=a[0][i]&&a[0][i]>=122)
			return m;
		if(65>=a[0][i]&&a[0][i]>=90)
			return m;
	}
	if(a[p][i]==0)
	{
		req(m,p,q,i+1,j);
		b[j]=m;
		j++;
	}
	if(97>=a[0][i]&&a[0][i]>=122)
			m=req(m,i+1,q,1,j)+1;
	if(65>=a[0][i]&&a[0][i]>=90)
			m=req(m,i+1,q,1,j)+ceil(m/20);
}
void main()
{
	int i,min,m,j,p,q;
	char ch,ch2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		j=1;
		printf("%d",i);
		if(j==1)
		{
			printf("Enter starting location:");
			scanf("%c",&ch);
			check(ch);
			j++;
		}
		if(j==2)
		{
			printf("Enter starting location:");
			scanf("%c",&ch2);
			check(ch2);
		}
		place(ch,ch2);
	}
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=n;j++)
			printf(" %c",a[i][j]);
	}
	scanf("%d",&m);
	scanf("%c",ch);
	scanf("%c",ch2);
	p=pos(ch,0);
	q=pos(ch2,1);
	req(m,p,q,0,0);
	min=b[0];
	for(i=1;i<=n;i++)
		if(b[i]<min)
			min=b[i];
	printf("The no. of coins to travel with:%d",min);
}
