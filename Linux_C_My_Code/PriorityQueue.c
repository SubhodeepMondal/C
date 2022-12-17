#include <stdio.h>
#include <stdlib.h>

int sum =0;

void findSum(int *arr, int *a, char* ch,int depth)
{
    int sumSubSec = 0;
    int numarr[10];
    char chararr[10];

    for (int i = 0; i<=depth;i++)
    {
        numarr[i] = a[arr[i]];
        chararr[i] = ch[arr[i]];
    }
        
    for (int i =0; i<=depth;i++)
    {
        if(chararr[i]=='+')
        {
            sumSubSec += numarr[i];
        }
        else if( chararr[i] == '-')
        {
            int min = 9999,index=0;
            for (int j = 0; j<=depth;j++)
            {
                if(min>numarr[j] && numarr[j]!= 0)
                {
                    min = numarr[j];
                    index = j;
                }
            }
            if ( min != 9999 )
                numarr[index] = 0;
            printf("After char:");
            for(int j =0;j<=depth;j++)
                printf("%c %d,",chararr[j], numarr[j] );
        }

    }
    printf("SumSub: %d\n",sumSubSec);
    sum += sumSubSec;

}

void subSequence(int i,int depth, int n, int* arr,int* a, char* ch)
{
    if (i == n )
        return ;
    else
    {
        for(int j = i;j<n;j++)
        {
            arr[depth] = j;
            printf("%d: ",depth);
            for (int k =0; k<= depth;k++)
                printf("%d ",arr[k]);
            printf("\n");
            findSum(arr,a,ch,depth);
            subSequence(j+1, depth+1, n , arr,a,ch);
        }
    }
}

void main()
{
    int n;
    scanf("%d",&n);
    char *ch = (char *) malloc(n*sizeof(char));
    int * a = (int *) malloc(n*sizeof(int));
    int *arr = (int *) malloc(n*sizeof(int));
    char cha;
    for (int i=0 ; i<n ; i++)
    {
        scanf(" %c",(ch+i));
        if(getchar()== '\n')
            *(a+i)= 0;
        else
            scanf("%d",(a+i));
    }
    for (int i =0; i<n;i++)
    {
        printf("%c,%d\n",ch[i],a[i]);
    }
    printf("\n");
    subSequence(0,0,n,arr,a,ch);
    printf("%d\n",sum);
}