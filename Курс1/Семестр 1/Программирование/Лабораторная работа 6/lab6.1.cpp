# include <stdio.h>
#include <stdlib.h>
#include <locale>

const int N = 20 ;
int random (int N){
	return rand() % N;
}
int main(){
	setlocale(LC_ALL,"russian");
	int i,A[N],a=-10,b=10;
	for(i=0;i<N;i++){
		A[i]=random( b-a+1 )+a;// ����� �������� ��������� ����� � ��������� [a,b]
	}
	printf("�����\n");
	for(i=0;i<N;i++){
		printf("%4d", A[i]);
	}
	printf("\n�������������:\n");
	for(i=0;i<N;i++){ // ��������� ������������� �����
		if(A[i]>0){
			printf("%4d  ",A[i]);
		}
	}
	printf("\n�������������:\n");
	for(i=0;i<N;i++){
		if (A[i]<0){
		printf("%4d  ",A[i]);
	}
	

	}
	system("PAUSE");
	return 0;
}
