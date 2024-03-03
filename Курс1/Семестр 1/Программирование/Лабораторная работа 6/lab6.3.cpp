#include <stdio.h>
#include <stdlib.h>
#include <locale>

const int N = 20;
int random(int N)  {
	return rand()%N;
}
 int main(){
 	setlocale(LC_ALL,"russian");
 	int i,a=0,b=10; 
 	float A[N];
 	printf("Вещественные:\n");
 	for(i=0;i<N;i++){
 		A[i]=(float)rand()*(b-a)/RAND_MAX+a;
 		printf("%2.2f ",A[i]);
	}
	printf("\nбольшие своих соседей справа и слева:\n");
	for(i=0;i<N;i++){
		if(A[i] > A[i+1] && A[i] > A[i-1]) {
		printf("%2.2f ",A[i]);
		}
	} 
}
