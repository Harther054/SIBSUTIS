#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

int triangle(int*a,int *b,int *c,float *P,float *S)
{
	float r;
	if(*a+*b>*c&&*a+*c>*b&&*b+*c>*a)
	{
		*P=*a+*b+*c;
		r=*P/2;
		*S=sqrt(r*(r-*a)*(r-*b)*(r-*c));
		return 1;
	}
	else
		printf("error!");
		return 0;

}

int main ()
{
	int a,b,c;
	float P,S;
	printf("input: a,b,c\n");
	scanf("%d%d%d",&a,&b,&c);
	if (triangle(&a,&b,&c,&P,&S)==1)
	{
		printf("P=%f S=%f",P,S);
	}
	return 0;
}
