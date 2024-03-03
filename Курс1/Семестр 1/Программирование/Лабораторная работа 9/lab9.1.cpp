//1.Матрица А имеет размерность 10x20. В матрице  поменять местами    
//1-ю и 2-ю строки, 3-ю и 4-ю строки, …., 9-ю и 10-ю строки. 
#include <stdio.h>
#include <stdlib.h>
#include <locale>
const int N = 10;
const int M = 20;
int radmon(int N){
	return rand()%N;
}
int main(){
	setlocale(LC_ALL,"rus");
	int A[N][M],i,j,temp;
	int a=1,b=5;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			A[i][j]=radmon(b-a+1)+a;
		}
	}
	printf("Матрица\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<N;i+=2){
		for(j=0;j<M;j++){
			temp=A[i][j];
			A[i][j]=A[i+1][j];
			A[i+1][j]=temp;
		}
	}
	printf("перестановка\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}
}
