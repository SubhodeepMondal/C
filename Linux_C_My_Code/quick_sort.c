#include<stdio.h>
#include<stdlib.h>

int sort(int * a, int i, int n)
{
    int root = n-1;
    int s = i-1, temp ;
    for(int k= i ; k< n-1; k++)
    {
        if(a[k]<a[root])
        {
            s++;
            temp = a[s];
            a[s] = a[k];
            a[k] = temp;
        }
    }
    s++;
    temp = a[s];
    a[s] = a[root];
    a[root] = temp;
    return s;   
}

void quickSort(int * a, int i, int j, int n)
{
    if (i<j)
    {
        int root = sort(a,i,j);
        quickSort(a,i,root,n++);
        quickSort(a,root+1,j,n++);
    }
    
}

void main()
{
    int n, a[20], i;
    printf("Enter the no. of element in the array:");
    scanf("%d",&n);
    printf("Enter %d numbers:\n",n);
    for (i = 0 ; i<n; i++)
        scanf("%d",&a[i]);
    quickSort(a,0,n,0);
    for( i = 0; i<n; i++)
        printf("%d ",a[i]);
        printf("\n");
}