#include<stdio.h>
void main()
{
	char a[20],b[20];
	int k,i=0;
	printf("Enter the plain text:");
	gets(a);
	printf("Enter the key:");
	scanf("%d",&k);
	while(a[i]!='\0')
	{
		b[i]=(a[i++]+n)%26;
	}
	printf("Encrypted Ciphertext is:");
	puts(b);
	
}
