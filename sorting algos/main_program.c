#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	long int n,i,data,set,j=0;
	FILE *fp;
	printf("How many data set will be there:");
	scanf("%ld",&set);
	while(j!=set)
	{
		printf("How many number to be sorted:");
		scanf("%ld",&n);
		fp=fopen("input.txt","w");
		data=rand()%n;
		fprintf(fp,"%ld",data);
		srand(time(0));
		for(i=1;i<n;i++)
		{
			fprintf(fp,",");
			fprintf(fp,"%ld",rand());
		}
		fclose(fp);
		system("insertion.exe");
		system("bubble.exe");
		system("Quick_sort.exe");
		system("mergesort.exe");
		system("heap_sort.exe");
		system("bst_sort.exe");
		j++;
	}

}
