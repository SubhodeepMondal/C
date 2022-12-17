#include<stdio.h>
int power(int a,int n)
{
	int b=1;
	if(n==0)
		return 1;
	while(n!=0)
	{
		b*=a;
		n--;
	}
	return b;
}
void main()
{
	char a[20],b[20];
	int i=0,j,k=0,l,n=0,m=0,div1,div2,carr1=0,carr2,c,flag=0;
	printf("Enter the number to be squre rooted:");
	gets(a);
	printf("Enter accuracy:");
	scanf("%d",&c);
	while(a[i++]!='\0')
		n++;
	printf("length of the string:%d",n);
	i=1;
	if(n%2!=0)
	{
		printf("\nIn n");
			while((a[0]-'0')>=i*i)
			{
				carr1=(a[0]-'0')-i*i;
				b[0]=i+'0';
				div1=i++;
				printf("\nCarry=%d  div:%d  i:%d\n",carr1,div1,i);
			}
			k++;
			m++;
	}
	i=0;
	while(i<n/2+c)
	{
		j=1;
		carr1*=power(10,2);
		printf("\nCarry1:%d",carr1);
		while(j>=0&&i<n/2)
		{
			carr1+=(a[k++]-'0')*power(10,j);
			/*printf("\tCarry:%d",carr1);*/
			j--;
		}
		if(i>=n/2||a[k]=='.')
		{
			if(i>=n/2)
			{
				carr1+=0*power(10,2);
				if(i==n/2)
					b[m++]='.';
			}
			else
			{
					b[++m]='.';
					k++;
			}
			
		}
		div1*=10;
		l=1;
		carr2=carr1;
		printf("\ncarry2:%d  carry1:%d  div1:%d  div2:%d  l:%d %a[]:%c",carr2,carr1,div1,div2,l,a[k]);
		while(carr1>=(div1*2+l)*l)
		{
			
			div2=div1*2+l;
			carr2=carr1-div2*l;
			b[m]=l+'0';
			l++;
			flag=1;
			printf("\ncarry2:%d  carry1:%d  div1:%d  div2:%d  l:%d",carr2,carr1,div1,div2,l);
		}
		if(flag==0)
		{
			printf("In if\n");
			b[m]='0';
		}
		else
			div1+=l-1;
		flag=0;
		carr1=carr2;
		b[m+1]='\0';
		
		m++;
		i++;
	}
	i=0;
	printf("\n");
	while(b[i]!='\0')
		printf("%c",b[i++]);
}
