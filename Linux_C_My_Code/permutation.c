#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct stack{
    int depth,ite;
}Stack;
void combinationRecursive(char * c,char *b,int i,int n)
{
    if(i==n)
    {
        b[i] = '\0';
        printf("%s\n",b);
        return ;
    }
    else
    {

        for(int k = 0; k < n; k++)
        {
            int flag = 0;
            for( int j = 0; j < i; j++ )
                if( b[j] == c[k] )
                    flag = 1;
            if(flag == 0)
            {
                b[i] = c[k];
                combinationRecursive(c,b,i+1,n);
            }
        }
    }
}


void combinationIterative(char * c, char * b, int i, int n)
{
    int top = -1,j,flag,m;
    Stack *stack = (Stack *) malloc(n*n*sizeof(Stack));
    ++top;
    stack[top].ite= i;
    stack[top].depth = 0;
    printf("%d\n",top);
    m =0;
    while(top != -1 && m<100)
    {
        m++;
        j = stack[top].depth;
        if(j==n)
        {
            b[j] = '\0';
            printf("%s\n",b);
            top--;
        }
        else
        {
            flag = 0;
            int k = stack[top].ite;
            printf("%d,%d :",j,k);
            for(; k < n;k++)
            {
                for(int l = 0; l < j; l++ )
                    if(b[l] == c[k])
                        flag = 1;
                
                if(flag == 0)
                {
                    top ++;
                    stack[top].ite = k;
                    b[j] = c[k];
                    stack[top].depth = j+1;
                    break;
                }
            }
        }
    }
}

void main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i;
    char *c, *b;
    scanf("%d",&n);
    double cpu_time1,cpu_time2;
    c = (char*) malloc((n+1)*sizeof(char));
    b = (char*) malloc((n+1)*sizeof(char));
    for(i = 0; i < n; i++)
        scanf("%c",&c[i]);
        
    c[i] = '\0';
//    printf("%s",c);
    clock_t starttime,endtime;
    starttime = clock();
//    combinationRecursive(c,b,0,n);
    endtime = clock();
    cpu_time1 = ((double)(endtime-starttime)/CLOCKS_PER_SEC);

    starttime = clock();
    combinationIterative(c,b,0,n);
    endtime = clock();
    cpu_time2 = ((double)(endtime-starttime)/CLOCKS_PER_SEC);
    printf("Running Time Recursive: %lf\nRunning Time Iterative %lf",cpu_time1,cpu_time2);
    

}