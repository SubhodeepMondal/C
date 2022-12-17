#include<stdio.h>
long int a[1000000],b[1000000],count=0;;
void merging(int low, int mid, int high) 
{
   int l1, l2, i;
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
   	count++;
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   while(l1 <= mid)    
      b[i++] = a[l1++];
   while(l2 <= high)   
      b[i++] = a[l2++];
   for(i = low; i<=high; i++)
      	a[i]=b[i];
}
void sort(int low, int high) 
{
   int mid;
   if(low < high) 
   {
      mid = (low+high)/2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } 
   else 
   { 
      return;
   }   
}
void main() 
{ 
   long int i,n=0,temp=0;
   char ch;
	FILE *fp1,*fp2;
	fp1=fopen("merge_sort","r+");
		if(fp1==NULL)
			fp1=fopen("merge_sort.txt","w");
	fp2=fopen("input.txt","r");
	ch=fgetc(fp2);
	while(ch!=EOF)
	{
		if(ch==',')
		{
			a[i]=temp;
			temp=0;
			i++;
			n++;
			
		}
		else
			temp=temp*10+(ch-'0');
		ch=fgetc(fp2);
	}
	n++;
	ch=fgetc(fp1);
	while(ch!=EOF)
		ch=fgetc(fp1);
   sort(0,n);
   fprintf(fp1,"\n%ld\n%ld\n",n,count);
}
