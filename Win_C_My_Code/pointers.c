#include<stdio.h>
#include<stdlib.h>
void point(int **x)
{
	int *t;
	t=(int*)malloc(sizeof (int));
	printf("\n%d",&t);
	*x=t;
	return ;
}
void main()
{
	int *i=NULL;
	printf("%d",&i);
	point(&i);
	printf("\n%d",*i);
}
