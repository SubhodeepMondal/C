#include<stdio.h>
#include<time.h>
int main()
{
    int ran,i=1,flag=0,num,no;
    no=8;
    ran=time(NULL)%100;
    printf("You have %d attempts\n\n",no);
    printf("Guess a number between 0 to 100 :\n");
    while(i<=no)
    {
    	scanf("%d",&num);
    	if(ran==num)
    	{
    		flag=1;
    		printf("You found the number in %d attempts.",i);
    		break;
		}
		if(num>ran)
		{
			printf("Entered number is bigger then correct number:");
			printf("\nTry again you have %d attempts left\n",no-i);
		}
		if(num<ran)
		{
			printf("Entered number is smaller then correct number:");
			if(no-i!=0)
				printf("\nTry again");
			printf("\nyou have %d attempts left\n",no-i);
		}
		i++;
	}
	if(flag==0)
	{
		printf("You have excited no. of attempts\n");
		printf("The correct number was:%d",ran);
	}
}
