#include <stdio.h>


void subsequence(int i, int n, int depth, int* arr)
{
    if(i == n )
        return ;
    else
    {
        //printf("%d ",i);
        for (int j = i;j<n;j++)
        {
            arr[depth] = j;
            printf("%d: ",depth);
            for (int k =0; k<= depth;k++)
                printf("%d ",arr[k]);
            printf("\n");
            subsequence(j+1,n,depth+1,arr);
            
            
        }
    }
}

void main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr[10];
    subsequence(0,4,0,arr);
}