#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct data{
  int a,b,c,d,thread_id;
  long int lb,ub,prime,min;
}data;
int getLen(long int num)
{
  int len=0;
  while(num>=1)
  {
    num/=10;
    len++;
  }
  return len;
}
int isPrime(long int num)
{
  long int i=2,n=num/2;
  int flag =0;
  for(;i<=n;i++)
  {
    if(num%i==0)
    {
      flag=1;
      break;
    }
  } 
  return flag;
}


long int makeNum(int n,int a, int b)
{
  return a*pow(10,n)+b;
}


void *findPrimeSum(void *p)
{
  data *ptr=(data*)p;
  long int *minPtr;
  int flag=1;
  int a=ptr->a;
  int b=ptr->b;
  int c=ptr->c;
  int d=ptr->d;
  int n;
  long int i=ptr->lb;
//  printf("%d,%d,%d,%d\n",a,b,c,n);
  for(;i<=ptr->ub;i++)
  {
    n=isPrime(i);
    if(n==0)
    {
//      printf("The no is:%ld\n",i );

      flag=isPrime(makeNum(getLen(a),i,a));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(a),i,a));
        continue;
      }

      flag=isPrime(makeNum(getLen(i),a,i));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),a,i));
        continue;
      }

      flag=isPrime(makeNum(getLen(b),i,b));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag,makeNum(getLen(b),i,b) );
        continue;
      }

      flag=isPrime(makeNum(getLen(i),b,i));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),b,i));
        continue;
      }

      flag=isPrime(makeNum(getLen(c),i,c));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(c),i,c)); 
        continue;
      }

      flag=isPrime(makeNum(getLen(i),c,i));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),c,i)); 
        continue;
      }

/*     flag=isPrime(makeNum(getLen(d),i,d));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(d),i,d));
        continue;
      }

      flag=isPrime(makeNum(getLen(i),d,i));
      if(flag==1)
      {
//        printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),d,i));
        continue;
      }*/
    }

    if(flag==0)
    {
      printf("The prime number is %ld\n",i );
      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(a),i,a));
      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),a,i));
      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(b),i,b));
      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),b,i));
      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(c),i,c)); 
      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),c,i)); 
//      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(d),i,d));
//      printf("The no is:%d,%ld\n",flag ,makeNum(getLen(i),d,i));
      ptr[n].min=i;
      break;
    }
  }
  if(flag==0)
  {

//    printf("Sum of the primes: %ld\n", a+b+c+i ); cloud computing
    pthread_exit(NULL);
  }
  else
  {
    printf("Unable to found it in thread: %d\n",ptr->thread_id);
    pthread_exit(NULL);
  }


}
 
int main()
{
  long int num,arr[20],diff,min;
  int n,i;
  pthread_t tid[12];
  printf("Enter the upper range\n");
  scanf("%ld",&num);
  printf("How many threads you want to create(<12):\n");
  scanf("%d",&n);
  data *ptr = (data *) malloc(n*sizeof(data));
  diff=(num-110)/n;
  ptr[0].lb=110;
  ptr[0].ub=ptr[0].lb+diff;
  ptr[0].a=3;
  ptr[0].b=7;
  ptr[0].c=109;
  ptr[0].d=673;
  ptr[0].thread_id=0;
  printf("%ld\t%ld\t%ld\n",ptr[0].lb,ptr[0].ub,ptr[0].ub-ptr[0].lb);

  for(i=1;i<n;i++)
  {
    ptr[i].a=3;
    ptr[i].b=7;
    ptr[i].c=109;
    ptr[i].d=673;
    ptr[i].thread_id=i;
    ptr[i].lb = ptr[i-1].ub + 1;
    ptr[i].ub = (ptr[i].lb - 1) + diff;
    if(i==(n-1))
      ptr[i].ub = num;
    printf("%ld\t%ld\t%ld\n",ptr[i].lb,ptr[i].ub,(ptr[i].ub-ptr[i].lb) );
  }
  for(i=0;i<n;i++)
  {
    pthread_create(&tid[i],NULL,findPrimeSum,&ptr[i]);
  }

 long int *numb[12];
  pthread_join(tid[0],NULL);
/*  if(num)
  min=*numb[0];*/

 for(i=0;i<n;i++)
  {
    pthread_join(tid[i],NULL);
//    if(*numb[i]<min)
//      min=*numb[i];
  }

  min=num;
  if(ptr[0].min!=0)
    min=ptr[0].min;
  for(i=1;i<n;i++)
  {
    if(ptr[i].min<min && ptr[i].min!=0)
      min=ptr[i].min;
//    printf("%ld\n",ptr[i].min );
  }

  if(min==num)
    printf("Unable to find\n");
  else
  {
    printf("The minimum prime number in range is:%ld\n", min );
    printf("Sum of the consiquitive 4 prime numbers is: %ld\n",ptr[0].a+ptr[0].b+ptr[0].c+ptr[i].d+min);
  }
  
  pthread_exit(NULL);

  return 0; 


}