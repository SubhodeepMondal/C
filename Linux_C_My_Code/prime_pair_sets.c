#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
 long * arrPrime;
 long count=1;
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
  for(i=0;i<count && arrPrime[i]<=ceil(sqrt(num));i++)
  {
    if(num%arrPrime[i]==0)
    {
      flag=1;
      break;
    }
  }
  for(i=arrPrime[i-1];i<num/2;i++)
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
 
int main()
{
  int a=3,b=7,c=109,d=673,flag=1,n=0,k=1;
  long int i,num;
  printf("Enter the upper range\n");
  scanf("%ld",&num);
  arrPrime=(long *)malloc(num/4*sizeof(long));

  arrPrime[0]=2;
  clock_t begin =clock(),end;
  for(i=3;i<=673;i++)
  {
    n=isPrime(i);
    if(n==0)
    {
      arrPrime[k]=i;
      k++;
      count++;
    }
  }


  for(i=674; i<=num ; i++)
  {
    n=isPrime(i);
    if(n==0)
    {
      arrPrime[k]=i;
      k++;
      count++;
//      printf("The prime no:%ld\n",i);


      flag=isPrime(makeNum(getLen(a),i,a));
//      printf("The prime:%d,%ld\n",flag,makeNum(getLen(a),i,a));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(i),a,i));
//      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),a,i));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(b),i,b));
//      printf("The prime:%d,%ld\n",flag,makeNum(getLen(b),i,b));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(i),b,i));
//      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),b,i));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(c),i,c));
//      printf("The prime:%d,%ld\n",flag,makeNum(getLen(c),i,c));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(i),c,i));
//      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),c,i));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(d),i,d));
      if(flag==1)
        continue;

      flag=isPrime(makeNum(getLen(i),d,i));
      if(flag==1)
        continue;
    }
    if(flag==0)
    {
      printf("The prime number is %ld,%ld\n",i,count );
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(a),i,a));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),a,i));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(b),i,b));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),b,i));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(c),i,c));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),c,i));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(d),i,d));
      printf("The prime:%d,%ld\n",flag,makeNum(getLen(i),d,i));
      break;
    }
  }
  end = clock();


/*  for(i=0;i<count;i++)
    printf("%ld\t", arrPrime[i]);
  printf("\n");*/


  if(flag==0)
    printf("Sum of the primes: %ld\n", a+b+c+d+arrPrime[count-1]);
  else
    printf("Unable to found it\n");

  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("The time spent:%f\n", time_spent);

}