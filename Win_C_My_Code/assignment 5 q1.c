#include<stdio.h>
#include<math.h>

int fd(int a,int b,int c,int d)
{
    return(abs(a-c)+abs(b-d));
}

int main()
{
	int t,c[2][1000],n,dx,dy,q,x,y,j,qu[20],res[200][3],r=0,w,cv,ccv,cx,cy,i,k,l,m;
	scanf("%d %d %d %d",&dx,&dy,&n,&q);
	for(j=0;j<n;j++)
	{
		scanf("%d %d",&c[0][j],&c[1][j]);
	}
	for(j=0;j<q;j++)
		scanf("%d",&qu[j]);
	for(j=0;j<q;j++)
	{
		cv=0;
		w=qu[j];
		for(k=1;k<=dx;k++)
		{
			for(l=1;l<=dy;l++)
			{
				ccv=0;
				for(m=0;m<n;m++)
				{                                              
					if(fd(k,l,c[0][m],c[1][m])<=w)
					{
						ccv++;
						//printf("\n$$$ %d %d %d %d %d %d %d",k,l,c[0][m],c[1][m],fd(k,l,c[0][m],c[1][m]),w,ccv);                                                                                                                                                                                
					}
				}
				if(ccv>cv)
				{         
					cv=ccv;
					cx=k;
					cy=l;
					//printf("***%d %d",k,l);
				}
				if(ccv==cv && l<cy)
				{         
					cv=ccv;
					cx=k;
					cy=l;
					//printf("***%d %d",k,l);
				}
				if(ccv==cv && l==cy && k<cx)
				{         
					cv=ccv;
					cx=k;
					cy=l;
					//printf("***%d %d",k,l);
				}
			} 
		}                                                            
		printf("\n%d (%d,%d)",cv,cx,cy);
	}
	getch();
	return 0;
}
