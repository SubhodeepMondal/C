#include <stdio.h>
#include <stdlib.h>

int findno(int value,int n,int *a)
{
    int lb =0,ub = n;
    int mid = (lb+ub)/2;
    if(n<2)
    {
        if(value == a[0])
            return 1;
        else if( value == a[1])
            return 1;
    }
    else
    {
        while(lb<ub)
        {
            if(a[mid]==value)
            {
                return 1;
                break;
            }
            else if(a[mid]>value)
            {
                ub=mid;
                mid = (lb+ub)/2;
            }
            else
            {
                lb = mid;
                mid = (lb+ub)/2;
            }
        }
    }
    return 0;
}


void putnum(int value, int n, int *a)
{
    a[n]=value;
}


int ugly_number(int value,int n,int *a)
{
    int arr[]={2,3,5};
    if(value == 1)
        return 1;
    else if(findno(value,n,a))
        return 1;
    else
    {
        int flag[]={0,0,0};
        printf("%d,%d\n",value,n);

        for (int i =0;i<=2;i++)
        {
            if(value%arr[i]==0) 
                flag[i] = ugly_number(value/arr[i],n,a);
        }
        if (flag[0] || flag[1] || flag[2])
        {
            putnum(value,n,a);
            return 1;
        }
        else
            return 0;
    }
}

void main()
{
    int value,j=1,final,i;
    printf("Enter the nth position no to find the ugly no.:\n");
    scanf("%d",&value);
    int *a = (int*)malloc(value*sizeof(int));
    a[0]= 1;
    for(i =2;j<=value;i++)
        {
            final = ugly_number(i,j,a);
            if(final)
                j++;
        }
    printf("%d,%d\n",final,i-1);
}