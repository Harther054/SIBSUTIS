#pragma once
#include <iostream>
#include <graphics.h>

using namespace std;

void print(int* A, int N) {
  printf("\n");
	for (int i = 1; i < N; i++) {
		cout << "|" << A[i];
	}
}

void FillInc(int* A, int N) {
	for (int i = 0; i < N; i++) {
		A[i] = i;
	}
}

void FillDec(int* A, int N) {
	for (int i = 0; i < N; i++) {
		A[i] = N - i;
	}
}

void FillRand(int* A, int N) {
	for (int i = 1; i < N; i++) {
		A[i] = rand() % 80;
	}
}

void SelectSort(int* A, int N) {
	int P,min;
	for (int i = 0; i < N - 1; i++) {
		min = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		if (i != min) {
			P = A[i];
			A[i] = A[min];
			A[min] = P;
		}
	}
}

void BubbleSort(int* A, int N) {
	int P;
	for(int i = 0; i < N ; i++) {
		for (int j=0; j < N-i-1; j++) {
			if (A[j] > A[j + 1]) {
				P = A[j];
				A[j] = A[j + 1];
				A[j + 1] = P;
			}
		}
	}
}

int BubbleSort(int* A, int N, int* C, int* M) {
  int temp;
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<i;j++){
			*C+=1;
		    if(A[j]>A[j+1]){
				      temp=A[j];
				       A[j]=A[j+1];
				       A[j+1]=temp;
				       *M+=3;
			  }
		 }
	 }
}


void ShakerSort( int* A,int N){
  int temp;
  int L=0, R=N-1, k=N;
  do
  {
  for (int j=R; j>L; j--){
    if (A[j]<A[j-1])
    {temp=A[j];
     A[j]=A[j-1];
     A[j-1]=temp;
     k=j;
     }
  }
  L=k;
  for (int i=L; i<R;i++){
  if (A[i]>A[i+1])
    {temp=A[i];
     A[i]=A[i+1];
     A[i+1]=temp;
     k=i;
  }
  }
  R=k;
  } while(L<R);
  }
void ShakerSort(int* A,int N,int* C, int* M){
int temp;
int L=0, R=N-1, k=N;
do
{
for (int j=R; j>L; j--)
  {*C+=1;
  if (A[j]<A[j-1])
  {temp=A[j];
   A[j]=A[j-1];
   A[j-1]=temp;
   k=j;
   *M+=3;
   }
}
L=k;
for (int i=L; i<R;i++)
{*C+=1;
if (A[i]>A[i+1])
  {temp=A[i];
   A[i]=A[i+1];
   A[i+1]=temp;
   k=i;
   *M+=3;
}
}
R=k;
} while(L<R);
}
