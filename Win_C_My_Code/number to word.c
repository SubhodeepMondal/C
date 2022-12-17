#include<stdio.h>
char a[][]={
				"zero",
				"one",
				"two",
				"three",
				"four",
				"five",
				"six",
				"seven",
				"eight",
				"nine",
				"ten",
				"eleven",
				"twelve",
				"thirteen",
				"fourteen",
				"fifteen",
				"sixteen",
				"seventeen",
				"eighteen",
				"nineteen",
				"twenty",
				"thirty",
				"fourty",
				"fifty",
				"sixty",
				"seventy",
				"eighty",
				"ninenty",
				"hundred",
				"thousand",
				"million",
				"billion",
				"trillion"
				};
void print(int i)
{
	int j=0
	while(a[i][j]!='\0')
	{
		printf("%c",a[i][j]);
		j++;
	}
}
void main()
{
	long int n;
	int i=0,d;
	printf("Enter an integer for conversion:");
	scanf("%ld",&n);
	if(n==0)
	while(a[0][i]!='\0')
	{
		printf("%c",a[0][i]);
		i++;
	}
	while(n!=0)
	{
		for(i=0;i<=3;i++)
		{
			if(i=0)
			{
				d=n%pow(10,i);
				switch(d)
				{
					case 0: print(0); break;
					case 1:	print(1); break;
					case 2:	print(2); break;
					case 3:	print(3); break;
					case 4:	print(4); break;
					case 5:	print(5); break;
					case 6:	print(6); break;
					case 7:	print(7); break;
					case 8:	print(8); break;
					case 9:	print(9); break;

				}
				
			}
			if(i=1)
		}
		
	}
}

