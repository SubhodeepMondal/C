#include<stdio.h>
#include<conio.h>
void main()
{
  int a[20],n,i,d=0,s=0;
  printf("\n input the size of the array..:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\n input the value..:");
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    d=d+a[i];
    if(d<0)
    d=0;
    if(s<d)
    s=d;
  }
  printf("\n sum of subsequence number is..:%d",s);
  getch();
}
