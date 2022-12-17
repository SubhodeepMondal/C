#include<stdio.h>
#include<stdlib.h>

int *countingSort(int *a,int n)
{
    int big, i,*b,*c;
    big = a[0];
    for (i = 1; i < n; i++)
    {
        if(big < a[i])
            big = a[i];
    }

    c = (int *) malloc((big+1)*sizeof(int));
    b = (int *) malloc(n*sizeof(int));

    for( i = 0; i < n; i++)
        c[a[i]] += 1;

    c[0] -= 1;

    for ( i = 1; i <= big; i++)
        c[i] += c[i-1];

    for ( i = 0; i < n; i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]-- ;
    }
    free(c);
    return (b);
        
}
void main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,*a,*b, big;
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);
    b = countingSort(a,n);
    free(a);
    for( i = 0; i < n; i++)
        printf("%d ",b[i]);

}