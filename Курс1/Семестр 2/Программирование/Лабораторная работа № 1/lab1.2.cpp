#include <stdio.h>
#include <math.h>

void taylor(double,double);

int main()
{	
	double x,eps,y;
	printf("input x,y:");
	scanf("%lf",&x);
	scanf("%lf",&eps);
	y=cos(x);
	printf("cos = %lf\n",y);
	taylor(x,eps);
}

void taylor(double x, double eps){
	double p=1,s=1;
	for(int n=1;fabs(p)>eps;n++){
	p*=-x*x/(2*n-1)/(2*n);
	s+=p;
	}
	printf("T cosinus = %lf",s);
}

