#include<stdio.h>
int fibo(int a,int b,int n)
{
	int t;
	if(n==0){
	return 0;}
	else{
		printf("%d ",a);
		t=a;
		a=b;
		fibo(a,a+t,n--);
	}
}
void main(){
	int a=0,b=1,n;
	printf("Enter the length of serise:");
	scanf("%d",&n);
	fibo(a,b,n);
}
