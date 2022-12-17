#include<stdio.h>
void reverse(char *a)
{
	char b[100];

	int i=0,end,n;
	n=length(a);
	end=n-1;
	for(i=0;i<n;i++)
	{
		b[i]=*(a+end);
		end--;
	}
	for(i=0;i<n;i++)
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
	printf("\nIn mul");
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
				printf("\nb[%d]:%c   a[%d]:%c  n:%d  m:%d",k,*(b+k),l,*(a+l),*n,*p);
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
			printf("\nsum:%d carry:%d i:%d j:%d,c[s]:%c\n",sum,carry,i,j,c[s]);
			j++;
			s++;
		}
		j--;
	}
	*p=length(&c[0]);
	for(i=0;i<=*p;i++)
	{
		*(d+i)=c[i];
		printf("%c",*(d+i));
	}
}
void sub(char *a,int * flag,int *n)
{
	printf("\nIn sub:");
	int i=0,carry=0;
	while(i<*n)
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
	*flag=check(a);
	for(i=*n-1;i>=0;i--)
	{
		if(*(a+i)=='0')
		{
			*(a+i)='\0';
			
		}
		else
			break;
	}
	for(i=0;i<*n;i++)
		printf("%c",*(a+i));
	*n=length(a);
	printf("\n");
}
void stcp(char *a,char* b)
{
	int i=0;
	while(*(a+i)!='\0')
	{
		*(b+i)=*(a+i);
		i++;
	}
}
void main()
{
	char a[50],b[100];
	int i,flag,n,m,p;
	printf("Enter the value of minuend:\n");
	gets(a);
	reverse(&a[0]);
	stcp(&a[0],&b[0]);
	n=length(&a[0]);
	m=n;
	sub(&a[0],&flag,&n);
	while(flag==1)
	{
		mul(&b[0],&a[0],&b[0],&n,&m);
		printf("\n");
		for(i=0;i<m;i++)
			printf("  b[%d]%c",i,b[i]);
		sub(&a[0],&flag,&n);
	}
	reverse(&b[0]);
	printf("length:%d",m);
	printf("\n");
	for(i=0;i<m;i++)
		printf("%c",b[i]);
}
