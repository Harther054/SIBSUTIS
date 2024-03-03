#include <locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <conio.h>
#include <time.h>



int children (int &n,int &m)
{
	int g=n-m;
	float c;
	float pb=0.45,pg=0.55;
	float u1=1,u2=1,u3=1;
	float p;
	if(n>=0&&m>=0&&n>=m)
	{
		for(int i=0;i<n;i++)
	{
		u1=(i+1)*u1;
	}
		for(int i=0;i<m;i++)
	{
		u2=(i+1)*u2;
	}
		for(int i=0;i<n-m;i++)
	{
		u3=(i+1)*u3;
	}
	pg=pow(pg,g);
	pb=pow(pb,m);
	c=u1/(u2*u3);
	p=c*pg*pb;
	printf("%f",p);
		return 1;
	}
	else
		return 0;

}

int main ()
{
	int n,m;
	setlocale(LC_ALL,"Russian");
	printf(" n \n");
	scanf("%d%d",&n,&m);
	if(children(n,m)==1)
	{
		;
	}
	return 0;
}
