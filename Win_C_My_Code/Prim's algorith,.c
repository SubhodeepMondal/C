#include<stdio.h>

void main()
{
    int cost[10][10]={0},visited[10]={0};
    int i,j,u,v,n,k,total=0,min=999;
    printf("\nEnter Number of Vertices: ");
    scanf("%d",&n);
    printf("\nEnter Cost Matrix According to Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }

    //Display
    printf("\nThe Cost Matrix is: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%3d ",cost[i][j]);
        }
        printf("\n");
    }

    //Prim's Algorithm

    visited[0]=1;
    for(k=0;k<n-1;k++)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(visited[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(visited[j]!=1)
                    {
                        if(cost[i][j]<min)
                        {
                            min=cost[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        visited[u]=1;
        visited[v]=1;
        total+=min;
        printf("\n\nMin (%d, %d) = %d ",u+1,v+1,min);
    }
    printf("\n\nMinimum Shortest Path Length = %d \n",total);
}

