//1.������� � ����� ����������� 10x20. � �������  �������� �������    
//1-� � 2-� ������, 3-� � 4-� ������, �., 9-� � 10-� ������. 
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
	printf("�������\n");
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
	printf("������������\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}
}
