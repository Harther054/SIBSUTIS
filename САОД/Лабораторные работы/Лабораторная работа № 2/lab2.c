#include <stdio.h>
#include <stdlib.h>
#define N 10
int random(){
	return rand()%N;
}
void selectsort(int*,int);
int Checksum(int*,int);
int RunNumber(int*,int);
void FillInc(int*,int);
void FillDec(int*,int);

int main(){
	int A[N],a=1,b=20,x,y;
	for(int i=0;i<N;i++){
		A[i]=(float)rand()*(b-a)/RAND_MAX+a;
		printf("%d |",A[i]);
	}
	x=RunNumber(A,N);
	y=Checksum(A,N);
	printf("\nÑåðèé:%d",x);
	printf("\nÑóììà:%d\n",y);
	selectsort(A,N);
	x=RunNumber(A,N);
	y=Checksum(A,N);
	printf("\nÑåðèé:%d",x);
	printf("\nÑóììà:%d\n",y);
	FillInc(A,N);
	selectsort(A,N);
	FillDec(A,N);
	selectsort(A,N);	
}
void selectsort(int*A,int P){
	int sel=0,M=0,C=0,i,j,min;
	for(int i=0;i<P-1;i++){
		min=i;
		for(int j=i+1;j<P;j++){
			C++;
			if(A[j]<A[min]){
				min=j;
			}
		}
		if(i!=min){
		sel=A[i];
		A[i]=A[min];
		A[min]=sel;
		M=M+3;
		}
	}
	printf("\n");
	for(int i=0;i<P;i++){
		printf("%d |",A[i]);
	}
	printf("\nC=%d",C);
	printf("\nM=%d\n",M);
}
int Checksum(int*A,int P){
	int sum=0;
	for(int i=0;i<P;i++){
		sum+=A[i];
	}
	return sum;
}
int RunNumber(int* A,int P){
	int s=0;
	for(int i=0;i<P;i++){
		if(A[i+1]<A[i]){
			s++;
		}
		else if(A[i]<A[i+1] && A[i+1]<A[i+2]){
			s=1;
		}
	}
	return s;
}
void FillInc(int* A,int P){
	for(int i=0;i<P;i++){
		A[i]=i+1;
		printf("%d |",A[i]);
	}
	printf("\n");
}
void FillDec(int* A,int P){
	for(int i=0;i<P;i++){
		A[i]=P-i;
		printf("%d |",A[i]);
	}
}

