/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int isprime(int num)
{
	int i,flag =0,t=num;
	if(num>=4)
		t=sqrt(num);
	for(i=2;i<=t;i++)
	{
		if(num%i==0)
		{
			flag =1;
			break;
		}
	}
	if (flag==1)
	{
		return 1;
	}
	else
	{
//		printf("%d ",num);
		return 0;
	}
}
int toNum(char *ch)
{
	int num=0,temp,j=strlen(ch)-1;
	for(int i=0;i<strlen(ch);i++)
	{
		temp=ch[i]-'0';
		num+=temp*pow(10,j--);
//		printf("\n%d,%d,%d\n",temp,num,strlen(ch));

	}
	return num;
}
int main(int argc, char *a[])
{
	int i,j,n,flag1,flag2,temp;
	int lb,ub;
	scanf("%d",&n);
	char **ch=(char **)malloc(n*sizeof(char));
	char cha[20];
//	printf("scanning %d numbers",n);
	for(i=0;i<n*2;i++)
	{
		scanf("%s",cha);
		ch[i]=(char *) malloc(sizeof(cha)*sizeof(char));
		strcpy(ch[i],cha);
//		printf("%s,%s",ch[i],cha);
		lb=toNum(ch[i]);
		i++;

		scanf("%s",cha);
		ch[i]=(char *) malloc(sizeof(cha)*sizeof(char));
		strcpy(ch[i],cha);
//		printf("%s,%s\n",ch[i],cha);
		ub=toNum(ch[i]);

//		printf("%d, %d\n",lb,ub);

		if(lb>2)
		{
			j=lb;
			do
			{
				flag1=isprime(j);
				if(flag1==0)
				{
					lb=j;
					break;
				}
				j++;
			}while(j<=(lb+ub)/2);
		}
		else
		{
			lb=2;
			flag1 =0;
		}
		

		j=ub;
		do
		{
			flag2=isprime(j);
			if(flag2==0)
			{
				ub=j;
				break;
			}
			j--;
		}while(j>=(lb+ub)/2+1);
//		printf("\n");


//		printf("%d, %d",flag1,flag2);
		if(flag1==0 && flag2==0)
		printf("%d\n",ub-lb);
		else if(flag1==1 && flag2==1)
			printf("-1\n");
		else if(flag1==1 && flag2==0)
			printf("0\n");
		else if(flag1==0 && flag2==1)
			printf("0\n");
	}
	
}