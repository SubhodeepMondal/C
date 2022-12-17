#include<stdio.h>
void reverse(char *a,int *n)
{
	char b[100];
	int i=0,end;
	*n=length(a);
	end=*n-1;
	for(i=0;i<*n;i++)
	{
		b[i]=*(a+end);
		end--;
	}
	for(i=0;i<*n;i++)
	{
		*(a+i)=b[i];
	}
}
int length(char *a)
{
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
	int i=0;
	while(*(a+i)!='\0')
	{
		if(*(a+i)!='0')
			return 1;
		i++;
	}
	return 0;
}
void mul(char* a,char* b,char *d,int *n,int *p)
{
	char c[100];
	int i,j=0,sum=0,carry=0,l,k,s=0;
	for(i=0;i<*n;i++)
	{
		while(j<*p)
		{
			k=i;
			l=j;
			sum=0;
			while(l>=i)
			{
				sum=sum+(*(b+k)-'0')*(*(a+l)-'0');
				k++;
				l--;
				if(k==*n)
					break;
			}
			sum=carry+sum;
			carry=sum/10;
			c[s]=((sum%10)+'0');
			if(carry!=0)
			{
				c[s+1]=carry+'0';
				c[s+2]='\0';
			}
			else
			c[s+1]='\0';
			j++;
			s++;
		}
		j--;
	}
	for(i=0;i<=length(&c[0]);i++)
	{
		*(d+i)=c[i];
	}
}
void main()
{
	char a[20],b[20],c[100];
	int i,flag,n,m,p;
	printf("Enter the value of multiplicant:\n");
	gets(a);
	printf("Enter the value of multiplier:\n");
	gets(b);
	reverse(&b[0],&m);
	reverse(&a[0],&n);
	mul(&a[0],&b[0],&c[0],&n,&n);
	reverse(&c[0],&p);
	printf("\n");
	for(i=0;i<p;i++)
		printf("%c",c[i]);
}
