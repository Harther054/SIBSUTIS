#include <stdio.h>

float pew(float x,int n);

int main(){
	int n;
	float x,y,a,b;
	printf("input x and n:");
	scanf("%f%d",&x,&n);
	y =pew(x,n);
	printf("Îòâåò:%f\n",y);
	return 0;
	
}
float pew(float x,int n){
	float a,b,d=1;
	a=x;
	b=x;
	if(n>0){
		for(int i=1;i<n;i++){
			x=a*b;
			a=x;
		}
	}
	else if(n<0){
		for(int i=0;i>n;i--){
			x=1/a*d;
			d=x;
		}
	}
	else if (n==0){
		x=1;
	}
	return x;
}
