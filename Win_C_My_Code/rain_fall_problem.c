#include<stdio.h>

#include<conio.h>

int stack[20];

int arr[20];

void check(int n)

{

  int p,q,a=0;

  static int i=0;

  p=stack[n];

  if(n==-1)

  return;

  q=0;

  while(q<=n)

  {

    if(p>=stack[q])

    {

      a++;

    }

    q++;

  }

  arr[i]=a;

  i++;

  check(n-1);

}

void main()

{

  int i,a=0,d=0,b=0;

  FILE *fp;

  char ch;


  printf("\n input the amount of rain from file..:");

  fp=fopen("rain.txt","r");

  ch=fgetc(fp);

  if(ch!=EOF)

  {

    while(ch!='\n')

      a=a*10+(ch-'0');

  }

  i=0;

  ch=fgetc(fp);

  while(1)

  {

     if(ch==EOF)

       break;

     else

     {

       if(ch!='\n')

       {

	 d=d*10+(ch-'0');

       }

       else

       {

	 stack[i]=d;

	 i++;

       }

       ch=fgetc(fp);

     }

  }

  check(a-1);

  for(i=a-1;i>=0;i--)

  {

    b=b+1;

    printf("%dday %d ",b,arr[i]);

  }

  getch();

}


