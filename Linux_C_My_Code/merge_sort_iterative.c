#include<stdio.h>
#include<stdlib.h>
void merge_sort(int *a, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *a1 = (int *) malloc(n1*sizeof(int));
    int *a2 = (int *) malloc(n2*sizeof(int));
    int i , j,k;
    for (i = 0; i<n1;i++)
        a1[i] = a[i+low];
    for(j = 0; j< n2;j++)
        a2[j] = a[mid+1+j];
    i = 0;
    j = 0;
    k = low;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            a[k++] = a1[i++];
        }
        else
            a[k++] = a2[j++];

    }
    while(i<n1)
        a[k++] = a1[i++];
    while(j<n2)
        a[k++] = a2[j++];
    free(a1);
    free(a2);
}

int main()
{
    int i, n, j, low =0, mid, high;
    int *a;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    high = n;
    a = (int*) malloc(n*sizeof(int));
    for( i = 0; i<n ; i++ )
        scanf("%d",&a[i]);
    j = 2;
    for( j = 1; j < n ; j *= 2 )
    {
        for (i=0; i<n;i+=2*j)
        {
            low = i;
            mid = i + j - 1;
            int to = i+2*j-1;
            int high1 = to < high ? to : high;
            merge_sort(a,low,mid,high1);
        }
    }
    for(i = 0; i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}