#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include <conio.h>
const int N=16;
int main(){
	setlocale(LC_ALL,"rus");
	int sum,p,i,n,A[N];
	for (i=0;i<N;i++){
	scanf("%d",&n);
	A[i]=n;
	}
	printf("\n");
	for (i=0;i<N;i++){
		p = A[i];
		if(i % 2 == 0){
			p*=2;
		}
		if (p > 9){
			p-=9;
		}
		sum+=p;
	}
	if(sum%10==0){
		printf("true");
	}
	else{
		printf("false");
	}
getch();	
}
