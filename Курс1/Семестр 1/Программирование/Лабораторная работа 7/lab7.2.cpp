#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

const int N = 15;
int random (int N) {
	return rand()%N;
}
int main(){
	setlocale(LC_ALL, "rus");
	int num, i,z,c,A[N],a = 0,b = 10;
	for (i = 0; i < N;i++){
		A[i]=random(b-a+1)+a;
	}
	printf("Массив");
	for (i=0;i<N;i++){
		printf("%d ",A[i]);
	}
	printf("\nУникальные элементы массива:\n");
	printf("%d ",A[0]);
	for(i=1;i<N;i++){
		for(c=0,z=1;z<i;z++){
			if(A[i]==A[i-z]){
				c++;
			}
		}
		if(c==0){
			printf("%d ",A[i]);
		}
	}
	return 0;
}
