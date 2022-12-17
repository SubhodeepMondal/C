#include<stdio.h>

typedef struct data{
	int a,b;
}data;

void main()
{
	/* code */
	data *ptr= (data *) malloc (sizeof(data)*5);
	for(int i=0; i<5;i++)
	{
		ptr[i].b=5;
		ptr[i].a=i;
		printf("%d %d\n",ptr[i].a,ptr[i].b );
	}
}