#include<stdio.h>
#include<stdlib.h>

typedef struct suminfo 
{
    int sum,i,j;
}sumInfo;

sumInfo findSumCrossingSubarray(int *a, int low, int mid, int max)
{
    sumInfo s;
    int left_sum = -99999;
    int sum = 0;
    for (int i = mid; i>= low; i--)
    {
        sum += a[i];
        if (sum > left_sum)
        {
            
            left_sum = sum;
            s.i = i;
        }

    }
    int right_sum = -99999;
    sum = 0;
    for ( int i = mid+1; i<max; i++)
    {
        sum += a[i];
        if( sum > right_sum)
        {
            right_sum = sum;
            s.j= i;
        }
    }
    s.sum = left_sum + right_sum;
    return s;
}

sumInfo findMaxSubArray(int *a,int low,int high)
{
    int mid;
    sumInfo s_l,s_r,s_c;
    int left_sum, right_sum, cross_sum;
    if(low == high)
        return ;
    else
    {
        mid = (low+high)/2;
        s_l = findMaxSubArray(a,low,mid);
        s_r = findMaxSubArray(a,mid+1,high);
        s_c = findSumCrossingSubarray(a, low, mid, high);

        if (s_l.sum >= s_r.sum && s_l.sum >= s_c.sum)
            return s_l;
        else if (s_r.sum >= s_l.sum && s_r.sum >= s_c.sum)
            return s_r;
        else
            return s_c;        
    }
}

void main()
{
    int *a;
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    a = (int*) malloc(n*sizeof(int));
    for(int i = 0; i< n; i++)
        scanf("%d",&a[i]);
    sumInfo s = findMaxSubArray(a,0,n);
    printf("The max sum possible is %d, %d, %d\n", s.i+1, s.j+1, s.sum);
}