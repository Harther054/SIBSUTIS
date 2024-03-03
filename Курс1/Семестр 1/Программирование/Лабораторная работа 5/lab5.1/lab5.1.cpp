#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 
int main()
{
    int i;
    i=0;
    double p1=0,p2=0,e,pi;
    p1 +=pow(-1,i)/(2*i+1);// 1
    i ++;
    p2 +=pow(-1,i)/(2*i+1);//1/3
    e=0.00001;// точность
    i=1;
    while((p1-p2)>e||(p1-p2)*(-1)>e){// пока разность суммы умноженная на 1 или -1 не будет меньше е
    p1+=pow(-1,i)/(2*i+1);//1-1/3 
    i++; 
    p2=p1+pow(-1,i)/(2*i+1);//1-1/3+1/5
	}
	pi=4*p1;
    printf("pi=%.5f",pi);
    return 0;
}
