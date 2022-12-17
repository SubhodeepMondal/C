#include<stdio.h>
#include<conio.h>
#include<math.h>
struct machine
{
   long int D,P,R,G;
};
void main()
{
   long int i,n,c,d,j,a,b,e,f=0,*arr,k,t;
   struct machine m[1000],temp;
   clrscr();
   printf("\n input the number of machine,restructuring cost and restructuring day..:");
   scanf("%ld %ld %ld",&n,&c,&d);
   for(i=0;i<n;i++)
   {
     printf("\n input the days,brought price,sell price and profit of %ld machine..:",i+1);
     scanf("%ld %ld %ld %ld",&m[i].D,&m[i].P,&m[i].R,&m[i].G);
     printf("\n %ld %ld %ld %ld ",m[i].D,m[i].P,m[i].R,m[i].G);
   }
   for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
	if(m[j].D<m[i].D)
	{
	  temp=m[i];
	  m[i]=m[j];
	  m[j]=temp;
	}
     }
   }
   /*for(i=0;i<n;i++)
   {
     printf("\n %ld %ld %ld %ld ",m[i].D,m[i].P,m[i].R,m[i].G);
   } */
   for(i=0;i<n-1;i++)
   {
     b=m[i].D;
     e=i;
     a=c;
     if(m[i].P<=c)
     {
       a=a-m[i].P;
       j=i+1;
       for(k=b+1;k<=d;k++)
       {
	 if(j==n)
	   break;
	 if(k==m[j].D)
	 {
	   if(m[j].P<=a && m[j].G>=m[e].G)
	   {
	     if(m[j].G>m[e].G)
	     {
	       a=(a-m[j].P);
	       a=a+m[e].R;
	       //printf("\n%ld %ld",a,m[e].R);
	       e=j;
	     }
	     else if(m[j].G==m[e].G && m[j].R>m[e].R)
	     {
	       a=(a-m[j].P);
	       a=a+m[e].R;
	      //printf("\n%ld %ld",a,m[e].R);
	       e=j;
	     }
	     else
	     {
	       a=a+m[e].G;
	     }
	   }
	   else
	   {
	     a=a+m[e].G;
	   }
	   j++;
	 }
	 else
	 {
	   a=a+m[e].G;
	 }
       }
     }
     else
       continue;
     arr[f]=a+m[e].R+((d-k+1)*m[e].G);
     f++;
   }
   if(m[i].P<=c)
   {
     arr[f]=c-m[i].P+(d-m[i].D)*m[i].G+m[i].R;
   }
   j=arr[f];
   for(i=f-1;i>=0;i--)
   {
     if(j<arr[i])
       j=arr[i];
   }
   printf("\n the maximum profit is..:%ld",j);
   getch();
}