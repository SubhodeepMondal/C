#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char ch=1;
	while(ch!=48){
		printf("Press any key:");
		ch=getch();
		printf("\nThe key is been pressed: %d\n",ch);
	}
	
}
