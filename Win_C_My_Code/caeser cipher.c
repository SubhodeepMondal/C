#include<stdio.h>
void main()
{
	char a[20];
	int k,i=0;
	printf("Enter the plain text:");
	gets(a);
	printf("Enter the key:");
	scanf("%d",&k);
	while(a[i]!='\0')
	{
		if(a[i]<91)
			a[i]=65+(a[i]+k-65)%26;
		if(a[i]>96)
			a[i]=97+(a[i]+k-97)%26;
		i++;
	}
	printf("\nEncrypted Ciphertext is:");
	puts(a);
	i=0;
	while(a[i]!='\0')
	{
		if(a[i]<91)
			a[i]=65+(a[i]-k-65)%26;
		if(a[i]>96)
			a[i]=97+(a[i]-k-97)%26;
		i++;
	}
	printf("\nDecrypted plaintext is:");
	puts(a);
}
