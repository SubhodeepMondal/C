#include<stdio.h>
#include<stdbool.h>
struct check
{
	int flag1,flag2;
}p[10][10];

void main()
{
	FILE *fp;
	char c,ch[100];
	int flag=0;
	int i=0,j,a,b,x,y,n,m,w=0;
	fp=fopen("input.c","r");
	if(fp==NULL)
		printf("Problem in opening file.");
	else
		printf("File opened");
	while(1)
	{
		ch[i]=fgetc(fp);
		if(ch[i++] == EOF)
			break;
	}
	n=ch[w++]-'0';
	m=ch[w++]-'0';
	printf("\nSize of the checkbox:%d x %d",n,m);
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p[i][j].flag1=ch[w++]-'0';
			p[i][j].flag2=0;
			printf("%d  ",p[i][j].flag1);
		}
		printf("\n");
	}	
	a=ch[w++]-'0';
	b=ch[w++]-'0';
	printf("Starting pointer:(%d,%d)",a,b);
	x=ch[w++]-'0';
	y=ch[w++]-'0';
	printf("\nEnding pointer:(%d,%d)",x,y);
	search(a,b,x,y,n,m,&flag);
	if(flag==0)
		printf("\nEnd pointer is not reachable.");
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
	if(*flag==1)
		printf("(%d,%d)",a,b);
}
