#include <stdio.h>
#include <stdlib.h>
#include <locale>

const int N = 20,F=40;
int random(int N){
	return rand()%N;
}
int main(){
	setlocale(LC_ALL,"rus");
	int C[N],D[N],E[F],i,c,j;
	int a = 0, b = 20;
	for(i=0;i<N;i++){
		C[i]=random(b-a+1)+a;
		D[i]=random(b-a+1)+a;
	}
	printf("Массив C:\n");
	for(i=0;i<N;i++){
		printf("%d |",C[i]);
	}
	printf("\nМассив D:\n");
	for(i=0;i<N;i++){
		
		printf("%d |",D[i]);
	}
	for(i=0;i<N-1;i++){
		for(j=0;j<N-i-1;j++){
			if(C[j]>C[j+1]){
				c=C[j];
				C[j]=C[j+1];
				C[j+1]=c;
			}
		}
	}
	for(i=0;i<N-1;i++){
		for(j=0;j<N-i-1;j++){
			if(D[j]>D[j+1]){
				c=D[j];
				D[j]=D[j+1];
				D[j+1]=c;
			}
		}
	}
	printf("\nОтсортированный массив С:\n");
	for(i=0;i<N;i++){
		printf("%d  |",C[i]);
	}
	printf("\nОтсортированный массив D:\n");
	for(i=0;i<N;i++){
		printf("%d  |",D[i]);
	}
	int k = 0;
	printf("\nМассив E:\n");
	for(k=1;k<F;k++){
		if(C[i]<D[j]){
		E[k]=C[i++];
		printf("%d  |",E[k]);
		}
		else{
		E[k]=D[j++];
		printf("%d  |",E[k]);
		}	
	}
} 
