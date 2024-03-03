#include <stdio.h>
#include <stdlib.h>
#define N 10
int random(int c){
	return rand()%c;
}
void FillInc(int*,int);
void FillDec(int*,int);
void FillRand(int*,int);
int CheckSum(int*,int);
int RunNumber(int*,int);
void PrintMas(int*,int);

int main(){
	int A[N],i,Sum,Number;
	float SR;
	
	FillInc(A,N);
	PrintMas(A,N);
	
	FillDec(A,N);
	PrintMas(A,N);
	
	FillRand(A,N);
	PrintMas(A,N);
	
	Sum = CheckSum(A,N);
	Number = RunNumber(A,N);
	
	printf("CheckSum = %d\n",Sum);
	printf("RunNumber = %d\n",Number);
		
	return 0;
}

void FillInc(int *A,int c){
	for(int i=0;i<c;i++){
	A[i]=i+1;
	}
}
void FillDec(int *A,int c){
	for(int i=0;i<c;i++){
	A[i]=c-i;
	}
}
void FillRand(int *A,int c){
	int a=1,b=10;
	for(int i=0;i<c;i++){
	A[i] = (float)rand()*(b-a)/RAND_MAX+a;
	}
}
int CheckSum(int *A,int c){
	int sum =0;
	for(int i=0;i<c;i++){
		sum+= A[i];
	}
	return sum;
}

int RunNumber(int *A,int c){
	int k=0,i; 
	for(i=0;i<c;i++){
		if(A[i]>A[i+1]){
			k++;
		}
	}
	return k;
}
void PrintMas(int *A,int c){
	for(int i=0;i<c;i++){
		printf("%d |",A[i]);
	}
	printf("\n");
}


