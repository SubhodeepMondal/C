#include<stdio.h>
void reverse(char *a,int *n)
{
	printf("\nIn reverse:");
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
		printf("%c",*(a+i));
	}
	printf("\nlength:%d",*n);
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
	printf("\nIn check:");
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
	printf("P=%d\n",*p);
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
				printf("\na[%d]:%c   b[%d]:%c",l,*(a+l),k,*(b+k));
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
			printf("\nsum:%d carry:%d i:%d j:%d,c[s]:%c",sum,carry,i,j,c[s]);
			j++;
			s++;
		}
		j--;
	}
	printf("\nlength:%d",length(&c[0]));
	for(i=0;i<=length(&c[0]);i++)
	{
		*(d+i)=c[i];
	}
	for(i=0;i<length(d);i++)
	{
		printf(" d[%d]:%c",i,*(d+i));
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
	for(i=0;i<*n;i++)
		printf("%c",*(a+i));
	printf("\n");
}
void main()
{
	char a[100],b[20],c[100];
	int i,flag,n,m,p;
	printf("Enter the value of minuend:\n");
	gets(a);
	printf("Enter the value of multiplicand:\n");
	gets(b);
	reverse(&b[0],&m);
	reverse(&a[0],&n);
	flag=check(&b[0]);
	sub(&b[0],&flag,&m);
	if(flag==1)
	{
		mul(&a[0],&a[0],&c[0],&n,&n);
		sub(&b[0],&flag,&m);
		p=length(&c[0]);
	}
	while(flag==1)
	{	
		for(i=0;i<n;i++)
			printf("%c",a[i]);
			printf("\n");
		for(i=0;i<p;i++)
			printf("%c",c[i]);
		mul(&c[0],&a[0],&c[0],&n,&p);
		sub(&b[0],&flag,&m);
		p=length(&c[0]);
		printf("length:%d\n",p);
	}
	reverse(&c[0],&n);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%c",c[i]);
}
