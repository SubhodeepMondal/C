#include<stdio.h>
void reverse(char *a,int *n)
{
	printf("\nIn reverse:");
	char b[20];
	int i=0,end;
	*n=length(a);
	end=*n-1;
	for(i=0;i<*n;i++)
	{
		b[i]=*(a+end);
		end--;
	}
	for(i=0;i<*n;i++)
		*(a+i)=b[i];
	
}
int length(char *a)
{
	printf("\nIn length");
	int i=0,count=0;
	while(*(a+i)!='\0')
	{
		count++;
		i++;
	}
	return(count);
}
int check(char* a)
{
	printf("\nIn check");
	int i=0;
	while(*(a+i)!='\0')
	{
		if(*(a+i)!='0')
			return 1;
		i++;
	}
	return 0;
}
void sub(char *a,int * flag,int *n)
{
	printf("\nIn sub");
	int i=0,carry=0;
	while(*(a+i)!='\0')
	{
		if(*(a+i)>'0')
		{
			*(a+i)=((*(a+i)-'0')-1)+'0';
			break;
		}
		else
			*(a+i)='9';
		i++;
	}
	for(i=0;i<*n;i++)
		printf("%c",*(a+i));
	*flag=check(a);
}
/*void mul(char* a,int *n)
{
	int sum;
	printf("\nIn mul");
	int i=0;
	while(i<*n)
	{
		sum=(*(a+i)-'0')*2;
		printf("%d",sum);
		*(a+i)=((*(a+i)-'0')*2)+'0';
		i++;
	}
	return ;
}*/
void mul(char* a,char* b,char* c,int *n)
{
	printf("\nIn mul");
	int i,j=0,sum=0,carry=0,l,k,s=0;
	for(i=0;i<*n;i++)
	{
		while(j<*n)
		{
			k=i;
			l=j;
			sum=0;
			while(l>=i)
			{
				sum=sum+(*(b+l)-'0')*(*(a+k)-'0');
				k++;
				l--;
			}
			sum=carry+sum;
			carry=sum/10;
			*(c+s)=(sum%10)+'0';
			*(c+s+1)='\0';
			printf("\n%c",*(c+s));
			j++;
			s++;
		}
		j--;
	}
}
void main()
{
	int n,i,flag;
	char a[20],c[20];
	gets(a);
	n=length(&a[0]);
	printf("\n%d",n);
	/*reverse(&a[0],&n);
	for(i=0;i<n;i++)
		printf("%c",a[i]);
	flag=check(&a[0]);
	printf("%d",flag);
	while(flag==1)
		sub(&a[0],&flag,&n);
	for(i=0;i<n;i++)
		printf("%c",a[i]);*/
		mul(&a[0],&a[0],&c[0],&n);
	printf("\n");	
	for(i=0;i<n;i++)
		printf("%c",a[i]);
	n=length(c);
	printf("%d\n",n);
	for(i=0;i<n;i++)
		printf("%c",c[i]);
}
