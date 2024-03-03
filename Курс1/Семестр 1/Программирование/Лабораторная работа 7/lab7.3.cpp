#include <stdio.h>
#include <stdlib.h>
#include <locale>

const int N = 20;

int random(int N) {
	return rand()%N;
}
int main(){
	setlocale(LC_ALL, "rus");
	int c,j,i,a = -10,b = 10;
	float A[N],B[N],E[N];
	for (i = 0; i < N; i++){
		A[i]=(float)rand()*(b-a)/RAND_MAX+a;
	}
	printf("Вещественные:\n");
	for (i = 0; i < N; i++){
		printf("%.2f |",A[i]);
	}
	printf("\nПоложительные числа массива В:\n");
	for (i = 0; i < N; i++){
		if(A[i]>0){
		B[j]=A[i];
		printf("%.2f |",B[j]);
		}
	}
}
