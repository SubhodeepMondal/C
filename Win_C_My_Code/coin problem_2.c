#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static int n;
static double b[20];
static char a[20][20];
check(char ch)
{
	int i;
	for(i=1;i<=2*n;i++)
	{
		if(a[0][i]==ch)
			break;
		if(a[0][i]==0)
		{
			a[0][i]=ch;
			break;
		}
	}
	for(i=1;i<=2*n;i++)
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
	for(i=1;i<=2*n;i++)
	{
		if(ch1==a[0][i])
		{
			for(j=0;j<=2*n;j++)
				if(a[j][0]==ch2)
				{
					a[i][j]='1';
					break;
				}	
				break;
		}	
	}
}
int pos(char ch,int flag)
{ 
	int i;
	for(i=1;i<=n;i++)
	{
		if(ch==a[i][0]&&flag==0)
		{
			return i;
		}
		if(ch==a[0][i]&&flag==1)
		{
			return i;
		}
	}
}
int req(double m,int p,int q,int i,int j)
{
	if(i==n+1)
		return ;
	if(a[p][i]=='1')
	{
		if(i==q)
		{
			if(97<=a[0][i]&&a[0][i]<=122)
				m+=1;
			else
				m+=ceil(m/20);
			j=b[0];
			j++;
			b[j]=m;
			b[0]=j;
			return ;
		}
		else if(97<=a[0][i]&&a[0][i]<=122)
		{
			m+=1;
			req(m,i,q,1,j);
		}
		else
		{
			m+=ceil(m/20);
			req(m,i,q,1,j);
		}
	}
	else
	{
		for(;i<=n;)
		{
			i++;
			req(m,p,q,i,j);
			if(i==q&&a[p][i]=='1')
				break;	
			if(i==n)
				break;
		}
	}
}
void main()
{
	int i,min,m,j,p,q,ptr;
	char ch1,ch2;
	printf("Enter the no. of destination paths:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
			printf("\n%dEnter starting location:",i);
			ch1=getche();
			check(ch1);
			fflush(stdin);
			printf("\nEnter ending location:");
			ch2=getche();
			check(ch2);
			place(ch1,ch2);
	}
	for(i=0;i<=2*n;i++)
	{
		printf("\n");
		for(j=0;j<=2*n;j++)
			printf(" %c",a[i][j]);
	}
	n++;
	printf("\nEnter min coins to destination");
	scanf("%d",&m);
	printf("\nEnter starting point:");
	ch1=getche();
	printf("\nEnter ending point:");
	ch2=getche();
	p=pos(ch1,0);
	q=pos(ch2,1);
	req(m,p,q,1,0);
	ptr=b[0];
	min=b[1];
	for(i=1;i<=ptr;i++)
	{
		if(b[i]<min)
			min=b[i];
	}
	if(ptr!=0)
	printf("\nThe no. of coins to travel to %c is:%d",ch2,min);
	else
		printf("\nCant't reach the destination!!!");
}
