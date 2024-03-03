#include <iostream>
#include "header.h"
#include <graphics.h>

using namespace std;

void Foo(int* A, int n, int* C, int* M, int* C2, int* M2){
  int sum1 = 0, sum2 = 0, SUM1 = 0, SUM2 = 0;

  sum1 = (*C + *M) / 600;
  SUM1 = (*C2 + *M2) / 600;
  *C = 0; *M = 0;	*C2 = 0; *M2 = 0;

  FillRand(A, n);
  BubbleSort(A, n, C, M);
  sum2 = (*C + *M) / 600;

  FillRand(A, n);
  ShakerSort(A, n,C2, M2);
  SUM2 = (*C2 + *M2) / 600;

  setcolor(GREEN);
  line(50 + n - 100, 800 - sum1, 50 + n, 800 - sum2);
  setcolor(WHITE);
  line(50 + n - 100, 800 - SUM1, 50 + n, 800 - SUM2);
}

void Chart(){
	int* F = new int[600];
	char bac[20];
	int n = 100, C = 0, M = 0, C2 = 0, M2 = 0;
	initwindow(1600, 900);
	setfillstyle(1, 0);
	bar(0, 0, 1599, 1599);
	setcolor(15);
	line(0, 800, 1690, 800);
	line(50, 0, 50, 900);
	line(50, 0, 70, 50);
	line(50, 0, 30, 50);
	line(1589, 800, 1539, 770);
	line(1589, 800, 1539, 830);
	for (int i = 1; i < 6; i++)
	{
		line(50 + 100 * i, 790, 50 + 100 * i, 810);
	}
	for (int i = 1; i < 15; i++)
	{
		line(40, 800 - 50 * i, 60, 800 - 50 * i);
	}
	for (int i = 1; i < 6; i++)
	{
		sprintf(bac, "%d", i * 100);
		moveto(50 + 100 * i, 830);
		outtext(bac);
	}
	for (int i = 1; i < 15; i++)
	{
		sprintf(bac, "%d", i * 30000);
		moveto(60, 780 - 50 * i);
		outtext(bac);
	}
	for (int i = 0; i < 5; i++)
	{
		Foo(F, n, &C, &M, &C2,&M2);
		n += 100;
	}
	system("PAUSE");
}

void tabl(){
  cout << "\n\n\n";
  int tablica[5][7],N=0,C=0,M=0;
  int* A = new int[600];
  for(int i = 0;i < 5;i++){
     tablica[i][0] = 100 + N;
     N+=100;
  }
  N=100;
  for(int i =0;i < 5; i++){
    FillDec(A,N);
    BubbleSort(A, N, &C, &M);
    tablica[i][1]= C + M;
    N+=100;
    M =0; C=0;
  }
  N=100;
  for(int i =0;i < 5; i++){
    FillRand(A,N);
    BubbleSort(A, N, &C, &M);
    tablica[i][2]= C + M;
    N+=100;
    M =0; C=0;
  }
  N=100;
  for(int i =0;i < 5; i++){
    FillInc(A,N);
    BubbleSort(A, N, &C, &M);
    tablica[i][3]=C + M;
    N+=100;
    M =0; C=0;
  }
  N=100;
  for(int i =0;i < 5; i++){
    FillDec(A,N);
    ShakerSort(A, N, &C, &M);
    tablica[i][4]= C + M;
    N+=100;
    M =0; C=0;
  }
  N=100;
  for(int i =0;i < 5; i++){
    FillRand(A,N);
    ShakerSort(A, N, &C, &M);
    tablica[i][5]= C + M;
    N+=100;
    M =0; C=0;
  }
  N=100;
  for(int i =0;i < 5; i++){
    FillInc(A,N);
    ShakerSort(A, N, &C, &M);
    tablica[i][6]= C + M;
    N+=100;
    M =0; C=0;
  }
  cout << "\t\t    buble sort\t\tshaker sort\n";
  cout << "\t\tDec\tRand\tInc\tDec\tRand\tInc\n";
  for(int i = 0; i < 5; i++){
    for(int j =0; j < 7; j++){
    cout << '\t' << tablica[i][j];
    }
    cout << endl;
  }
}

int main(){
  setlocale(LC_ALL, "ru");
  int N=0,C = 0,M = 0,C_teor,M_teor;
  cin >> N;
  int* A = new int[N];
  for(int i=0;i<N;i++){
    A[i]= rand() % 20;
    cout << A[i] << ' ';
  }
  cout << '\n';
  ShakerSort(A, N, &C, &M);
  for (int i = 0; i < N; i++)
	{
		cout << A[i] << ' ';
	}
  cout << endl;
  C_teor = N * (N - 1) / 2;
	M_teor = 3 * N * (N - 1) / 2;
	cout << "fack \n " << C << ' ' << M << '\n';
	cout << "teor \n " << C_teor << ' ' << M_teor << '\n';
  tabl();
  Chart();
  return 0;
}

