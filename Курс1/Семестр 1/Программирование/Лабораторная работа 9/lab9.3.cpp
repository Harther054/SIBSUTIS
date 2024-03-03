#include <stdio.h>
#include <stdlib.h>
#include <locale>
const int N = 5;
int random(int N){
	return rand()%N;
}

int main(){
	setlocale(LC_ALL,"rus");
	int B[N][N],A[N][N],a=0,b=5,i,j,temp;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j]=random(b-a+1)+a;
		}
	}
	printf("Матрица\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%2d",A[i][j]);
		}
	printf("\n");
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			B[j][i]=A[i][j];
		}
	}
	printf("транспонированная матрица\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%2d",B[i][j]);
		}
	printf("\n");
	}
}
