#include<stdio.h>
#include<stdbool.h>
struct check
{
	int flag1,flag2;
}p[10][10];

void main()
{
	int flag=0;
	int i,j,a,b,x,y,n,m;
	printf("Enter the size checkbox:");
	scanf("%d%d",&n,&m);
	printf("Enter the path value of the checkbox(1=true,0=false):");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			printf("a[%d][%d]:",i,j);
			scanf("%d",&p[i][j].flag1);
			p[i][j].flag2=0;
		}
	printf("Enter the starting point:");
	scanf("%d%d",&a,&b);
	printf("Enter the ending point:");
	scanf("%d%d",&x,&y);
	search(a,b,x,y,n,m,&flag);
}
search(int a,int b,int x,int y,int n,int m,int *flag)
{
	/*printf("\na:%d,b:%d,x:%d,y:%d,p[%d][%d]:%d",a,b,x,y,a,b,p[a][b].flag1);*/
	
	if(a==x&&b==y)
	{
		printf("\nPoints from end to start:");
		printf("(%d,%d)",a,b);
		*flag=1;
		return;
	}
	if(a==n||b==m||a<0||b<0)
		return;
	if(p[a][b].flag1==0||p[a][b].flag2==1)
		return ;
	p[a][b].flag2=1;
	if(*flag==0)
		search(a+1,b,x,y,n,m,flag);
	if(*flag==0)
		search(a,b-1,x,y,n,m,flag);
	if(*flag==0)
		search(a-1,b,x,y,n,m,flag);
	if(*flag==0)
		search(a,b+1,x,y,n,m,flag);
	printf("(%d,%d)",a,b);
}
