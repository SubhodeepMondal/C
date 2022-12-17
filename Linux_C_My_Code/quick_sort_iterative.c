#include<stdio.h>
#include<stdlib.h>

int quickPartition(int * a, int i, int j)
{
    int x = j-1;
    int b = i-1, temp;
    for( int k  = i ; k < j-1; k++)
    {
        if(a[k] < a[x])
        {
            b++;
            temp = a[k];
            a[k] = a[b];
            a[b] = temp;
        }
    }
    b++;
    temp = a[x];
    a[x] = a[b];
    a[b] = temp;
    return b;
}

void main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, *a,*stack,top = -1,i,j,root;
    scanf("%d",&n);
    a = (int *) malloc(n*sizeof(int));
    for( i = 0; i<n; i++)
        scanf("%d",&a[i]);
    stack = (int *) malloc(2*n*sizeof(int));
    stack[++top] = 0;
    stack[++top] = n;
    while(top>-1)
    {
        j = stack[top--];
        i = stack[top--];
        
        root = quickPartition(a,i,j);
        if( root > i+1)
        {
            stack[++top] = i;
            stack[++top] = root;
        }
        if( root < j-1 )
        {
            stack[++top] = root+1;
            stack[++top] = j;
        }
    }
    for( i = 0; i<n; i++)
        printf("%d ",a[i]);
}