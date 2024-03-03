#include <iostream>
#include <stdlib.h>
#include "header.h"
#include <cmath>
#include <graphics.h>

using namespace std;

void tabl();
void Grafik();
void Tryd(int*,int,int*,int*,int*,int*,int*,int*,int*,int*);

int main(){
  int N = 0, C = 0, M = 0, C_teor_min, M_teor_min,M_teor_max,C_teor_max;
  cin >> N;
  int* A = new int[N];
  for (int i = 0; i < N; i++) {
    A[i] = rand() % 40;
    cout << A[i] << ' ';
  }
  cout << '\n';
  IncertSort(A,N,&C,&M);
  for (int i = 0; i < N; i++) {
    cout << A[i] << ' ';
  }
  cout << endl;
  cout << "C= " <<  C << ' ' << M << endl;
  C_teor_min = N-1;
  M_teor_min = 2*(N-1);
  C_teor_max = ((pow(N,2)-N)/2);
  M_teor_max = ((pow(N,2)-N)/2)+2*N-2;
  cout << "C(min)= " << C_teor_min << " M(min)= " << M_teor_min << endl;
  cout << "C(max)= " << C_teor_max << " M(max)= " << M_teor_max << endl;
  tabl();
  Grafik();
}

void tabl(){
  int tablica[5][5],M = 0, C = 0, N = 100,sum = 0;
  int *A = new int[500];
  int *L = new int[500];
  int *G = new int[500];
  int *F = new int[500];
	for (int i = 0; i < 5; i++)
	{
		tablica[i][0] =  N;
		N += 100;
	}
	N = 100;
	for (int i = 0; i < 5; i++){
		FillRand(A, N);
		print(A, L, N);
		print(A, G, N);
		print(A, F, N);

		SelectSort(A, N, &C, &M);
		sum = C + M;
		tablica[i][1] = sum;
		
		C = 0, M = 0;
		BubbleSort(L, N, &C, &M);
		sum = C + M;
		tablica[i][2] = sum;

		C = 0, M = 0;
		ShakerSort(G, N, &C, &M);
		sum = C + M;
		tablica[i][3] = sum;

		C = 0, M = 0;
		IncertSort(F, N, &C, &M);
		sum = C + M;
		tablica[i][4] = sum;
		N += 100;
	}
  cout << "\tN\tSelect\tBubble\tShaker\tInsert" << endl;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cout << '\t' << tablica[i][j];
    }
    cout << endl;
  }
}

void Grafik(){
	int* A = new int[600];
	char por[20];
	int N = 0,Mf = 0, Cf = 0,Mf1 = 0, Cf1 = 0,Mf2 = 0, Cf2 = 0,Mf3 = 0, Cf3 = 0;
	initwindow(1920,1280,"График");
	setfillstyle(1,7);
	line(100,100,100,700);
	line(100,700,700,700);
	for(int i = 0;i <= 5; i++){
		line(100+70*i,690,100+70*i,710);
	}
	for(int i = 0;i <= 15 ; i++){
		line(90, 700 - 40 * i, 110, 700 - 40 * i);
	}
	for(int i = 1; i <= 15;i++){
		sprintf(por,"%d\n",i*22500);
		moveto(40,680 - 40 * i);
		outtext(por);
	}
	for(int i = 1; i <= 5;i++){
		sprintf(por,"%d\n",i * 100);
		moveto(100+65*i,740);
		outtext(por);
	}
	for(int i = 0; i < 5; i++){
		Tryd(A,N,&Cf,&Mf,&Cf1,&Mf1,&Cf2,& Mf2,&Cf3,&Mf3);
		N+=100;
	}
	getch();
	closegraph();
}

void Tryd(int* A,int N, int* Cf,int* Mf,int* Cf1,int* Mf1,int* Cf2,int* Mf2,int* Cf3,int* Mf3){
  int *L = new int[500];
  int *G = new int[500];
  int *F = new int[500];
  int sum = 0,SUM = 0,sum1 = 0,SUM1 = 0, sum2 = 0, SUM2 = 0, sum3 = 0, SUM3 = 0;
  sum = (*Cf + *Mf)/ 1000;
  sum1 = (*Cf1 + *Mf1)/ 1000;
  sum2 = (*Cf2 + *Mf2)/ 1000;
  sum3 = (*Cf3 + *Mf3)/ 1000;
  
	FillRand(A,N);
	print(A, L, N);
	print(A, G, N);
	print(A, F, N);
	
	SelectSort(A,N,Cf,Mf);
	SUM = (*Cf + *Mf)/ 1000;
	
	BubbleSort(L,N,Cf1,Mf1);
	SUM1 = (*Cf1 + *Mf1)/ 1000;
			
	ShakerSort(G,N,Cf2,Mf2);
	SUM2 = (*Cf2 + *Mf2)/ 1000;

	IncertSort(F,N,Cf3,Mf3);
	SUM3 = (*Cf3 + *Mf3)/ 1000;
	
	setcolor(GREEN);
	line(50 + N - 100,700-sum,50+N,700-SUM);
	setcolor(WHITE);
	line(50 + N - 100,700-sum1,50+N,700-SUM2);
	setcolor(BLUE);
	line(50 + N - 100,700-sum2,50+N,700-SUM2);
	setcolor(RED);
	line(50 + N - 100,700-sum3,50+N,700-SUM3);
}

