#include <stdio.h>
#include <string.h>
#include <math.h>

void main(int argc, char *a[])
{
	char ch[20][20],count[5];
	int n=0,i,j=0,k,flag, temp1,temp2;
/*	if(argc>2)
	{
		for(i =0;i<argc;i++)
		{
			if(i==0)
				continue;
			else if(i==2)
				strcpy(count,a[i]);
			else
			{
				strcpy(ch[j++],a[i]);
			}
		}
	}*/
	scanf("%s %d",ch[0],&n);
	for(i=1;i<=n;i++)
		scanf("%s",ch[i]);
/*	j = strlen(count)-1;
	for(i=0;i<strlen(count);i++)
	{
		temp1 = count[i]-'0';
		n+=temp1*pow(10,j);
		j--;
	}*/

	for(i =0;i<=n;i++)
	{
			printf("%s\n",ch[i]);
		
	}


	for(i=1;i<=n;i++)
	{
		temp1=0;
		for(j=0;j<strlen(ch[i]);j++)
		{
			flag=0;
			for(k=temp1;k<strlen(ch[0]);k++)
			{
				if(ch[0][k]==ch[i][j])
				{
					temp1 = k+1;
					flag=1;
					printf("%c,%c,%d,%d\n",ch[0][k],ch[i][j],temp1,flag);
					break;
				}
			}
			if(flag==0)
			break;
		}
		if(flag==0)
			printf("Negative\n");
		else
			printf("Positive\n");
	}	
}