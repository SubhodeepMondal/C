#include<stdio.h>
void main()
{
	char *masterlist[10][10];
	int i, flag;
	char yourname[20];
	printf("Enter the 5 name in the list:\n");
	for(i=0;i<5;i++)
		scanf("%s",masterlist[i]);
	printf("\nEnter yourname:");
	scanf("%s",yourname);
	flag=0;
	for(i=0; i<=5;i++)
	{
		if(strcmp(masterlist[i],yourname)==0)
		{
			printf("Welcome,you can enter the place\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Sorry, you are a trespasser.");
	strcpy(yourname,masterlist[i+1]);
	printf("%s\n",yourname);

}