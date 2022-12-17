#include <stdio.h>
#include <stdlib.h>
void maxHeapify(int * a, int i,int n)
{
    int l = 2*i, r = 2*i+1;
    int largest;
    if (l <n && a[l] > a[i])
        largest = l;
    else 
        largest = i;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest!= i)
    {
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxHeapify(a,largest,n);
    }
}

void buildMaxHeap(int * a, int n)
{
    for(int i = (n-1)/2; i>= 0; i--)
        maxHeapify(a, i, n);
    for(int i = 0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
    for ( int i = n-1; i >= 1; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        n--;
        maxHeapify(a, 0, n);
        for(int j = 0; j<n; j++)
            printf("%d ",a[j]);
        printf("\n");
    }
}

void main ()
{
    int n, *a;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));   
    printf("Enter %d numbers:",n);
    for(int i = 0; i<n;i++)
        scanf("%d",&a[i]);
    buildMaxHeap(a,n);
    for(int i = 0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}   