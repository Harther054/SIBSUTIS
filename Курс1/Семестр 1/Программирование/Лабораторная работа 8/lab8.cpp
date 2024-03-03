//f(x)=(x+1)2sqrt(lg x); a=2; b=10;
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
const int N=10;
int main()
{
	float a=2, b=10, x=1, h=0, I1=0, I2=0, f=0, l=0;
	float A[N+1];
	h=(b-a)/N;
	for(int i=0; x<b; i++)
	{
		f=pow(x+1,2)*sqrt(log10(x));
		A[i]=f;
		x=x+h;
	}	for(int i=0; i<N; i++)
	{
		if (i==0||i==N)
		{
		 	A[i]=A[i]/2;	
		}
		I1+=A[i];
	}
		for(int i=0; i<N; i++)
	{
		if (i==0||i==N)
		{
		 	A[i]=A[i]*2;		 	
		}
	}
	I1*=h;
	printf ("\nI1=%f",I1);
		for(int i=0; i<N; i++)
	{
		l=A[i];
		if(i%2==0)
		{
			A[i]*=2;
		}
		if(i%2==1)
		{
			A[i]*=4;
		}
		if(i==0||i==N)
		{
			A[i]=l;
		}
		I2+=A[i];
		
		 	
	}
	I2=I2*h/3;
	printf ("\nI2=%f",I2);
	system("PAUSE");	
	return 0; 
	
}
