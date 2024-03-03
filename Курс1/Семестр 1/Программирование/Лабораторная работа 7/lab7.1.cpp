#include <stdio.h>
#include <math.h>
#include <locale>
const int N=59;
main()
{
	setlocale(LC_ALL, "Russian");
	int i,j;
	float y,c,a,b,x1,x2,h,A[N],g;
	a=2.14; b=-4.21; c=3.25; x1=-4.5, x2=-33.5, h=0.5, h=0.5, i=0;
	while(x1>=x2){
	i++;
	x1=x1-h;
	y=a*x1*x1*sin(x1)+b*x1+c;
	A[i]=y;
	printf("%.3f",A[i]);
	}
	for (i=0;i<N-1;i++){
		for (j=0;j<N-i-1;j++){
			if (A[j]<A[j+1]){
			g=A[j];
			A[j]=A[j+1];
			A[j+1]=g;
			}
		}
	}
printf("\n Отсортированный массив:\n");
	for(i=0;i<N;i++){
	printf("%.3f |",A[i]);
	}
return 0;
}
