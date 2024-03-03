#include <stdio.h>
#include <stdlib.h>

#define N  500

int random(int P){
	return rand()%P;
}
void FillInc(int*,int);
int  BubbleSort(int*,int,int* M);
void FillRand(int*,int);
void FillDec(int*,int);
void Tabl(int*,int);
void PRINTF(int*,int);
int  jor(int*,int,int*M);

int main(){
	int A[N],M;
	FillInc(A,10);PRINTF(A,10);BubbleSort(A,10,&M);PRINTF(A,10);
	printf("\n---------------------------");
	FillRand(A,10);PRINTF(A,10);BubbleSort(A,10,&M);printf("\nM=%d",M-45);PRINTF(A,10);
	printf("\n---------------------------");
	FillDec(A,10);PRINTF(A,10);BubbleSort(A,10,&M);PRINTF(A,10);
	printf("\n---------------------------");
	Tabl(A,N);
	printf("|___|___________|________|________|________|\n");
	return 0;
}

void FillInc(int* A,int P){
	for(int i=0;i<P;i++){
		A[i]=i+1;
	}
}
int  BubbleSort(int* A,int P,int *M){
	int temp,C=0;
	for(int i=P-1;i>=0;i--){
		for(int j=0;j<i;j++){
			C++;
			if(A[j]>A[j+1]){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				*M+=3;
			}
		}
	}
	*M+=C;
	if(P<100 && A[9]!=10){
	printf("\n����M(max)=%d",3*C);
	printf("\n����M(min)=%d",0);
	}
}
void FillRand(int* A,int P){
	int a=0,b=20;
	printf("\n");
	for(int i=0;i<P;i++){
		A[i]=(float)rand()*(b-a)/RAND_MAX+a;
	}
}
void FillDec(int* A,int P){
	printf("\n");
	for(int i=0;i<P;i++){
		A[i]=P-i;
	}
}
void Tabl(int* A,int P){
	int M,C;
	printf("\n");
	printf("___________________________________________\n");
	printf("| N | M(t)+C(t) |         M(F)+C(F)        |\n");
	printf("|   |           |__________________________|\n");
	printf("|   |           |  Dec   |  Rand  | Inc    |\n");
	printf("|___|___________|________|________|________|\n");
	BubbleSort(A,100,&M);jor(A,100,&M);
	BubbleSort(A,200,&M);jor(A,200,&M);
	BubbleSort(A,300,&M);jor(A,300,&M);
	BubbleSort(A,400,&M);jor(A,400,&M);
	BubbleSort(A,500,&M);jor(A,500,&M);
}
void PRINTF(int* A,int P){
	int M;
	printf("\n");
	for(int i=0;i<P;i++){
	printf("%d |",A[i]);
	}
}
int jor(int* A,int P,int *M){
	int C,Max,MC;
	Max = 3*C;
	MC=Max+C;
	printf("|%d|  %6d   |  %6d|%6d  |%7d |\n",P,MC,MC,*M,C);
}
