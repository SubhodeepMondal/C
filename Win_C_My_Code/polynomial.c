#include<stdio.h>
#include<conio.h>
struct poly
{
	int pw,flag;
	float co;
}pf[100],ps[100],pt[100];
void create_poly(struct poly p[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Enter the power:");
		scanf("%d",&p[i].pw);
		printf("Enter the co-efficient:");
		scanf("%f",&p[i].co);
		pf[i].flag=0;
	}
}
int find_power(struct poly p[],int n1,int pow)
{
	int i;
	while(i<n1)
	{
		if(p[i].pw==pow)
		{
			
			return (i);
		}
		else
		i++;
	}
	return (-1);
}
int add_poly(struct poly pf,int n1,struct poly ps,int n2)
{
	int i=0,j=0,k=0,n3=0,temp;
	n3=n1;
	do
	{
		temp=pf[i].pw;
		j=find_power(ps,n2,temp);
		if(j==-1)
		{
			pt[k].pw=pf[i].pw;
			pt[k].co=pf[i].co;
			pf[1].flag=1;
			i++;
		}
		else
		{
			pt[k].pw=pf[i].pw
			pt[k].pw=pf[i].pw+ps[j].pw;
			pf[i].flag=1;
			ps[j].flag=1;
			i++;
			j++;
			k++;
		}
	}while(i<n1);
	while(j<n2)
	{
		if(ps[j].flag==0)
		{
			pt[k].pw=ps[j].pw;
			pt[k].co=ps[k].co;
			k++;
			n3++;
		}
		j++;
	}
	return (n3);
}
void print_poly(struct poly p[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(p[i].co!=0)
		printf("%2.2f[x^%d] ",p[i].co,p[i].pw);
	}
}
void main()
{
	int n1,n2,n3;
	printf("Enter the number of term in the first poly:");
	scanf("%d",&n1);
	printf("\n Enter the data for first polynomial:");
	create_poly(pf,n1);
	printf("Enter the number of term int the second poly:");
	scanf("%d",&n2);
	printf("\n Enter the data for first polynomial:");
	n3=add_poly(&pf,n1,&ps,n2,&pt);
	printf("The resultant polynomial is :\n");
	print_poly(pt,n3);
}
