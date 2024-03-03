#include <iostream>
#include <stdlib.h>
#include "header.h"
#include <graphics.h>
#include <conio.h>

using namespace std;

void tabl();
void tabl2();

int  main() {
    int N,X,C=0,C2=0,C3=0,C4=0;
    cin >> N;
    int A[N];
    FillRand(A,N);
    ShellSort(A,N);
    for(int i=0;i<N;i++){
      cout << "|" <<A[i] << ' ';
    }
    cout << endl;
    cin >> X;
    BSearch1(A,N,X,&C);
    BSearch2(A,N,X,&C2);
    BSearchAll1(A,N,X,&C3);
    BSearchAll2(A,N,X,&C4);
    cout << "C(BSearch1)= " << C << endl;
    cout << "C2(BSearch2)= " << C2 << endl;
    cout << "C3(BSearchAll1)= " << C3 << endl;
    cout << "C3(BSearchAll2)= " << C4 << endl;
    tabl();
    tabl2();
}

void tabl(){
  int N=100,C=0,C2=0,SUM=0,X;
  int* A = new int[1000];
  int* B = new int[1000];
  int tablica[10][3];
  for(int i=0;i < 10;i++){
    tablica[i][0]=N;
    N+=100;
  }
  N=100;
  for(int i=0;i < 10;i++){
    FillInc(A,N);

    BSearch1(A,N,X,&C);
    SUM = C;
    tablica[i][1]=SUM;

    BSearch2(B,N,X,&C2);
    SUM = C2;
    tablica[i][2]=SUM;
    N+=100;
  }
  cout << "\tN\tBSearch1 BSearch2" << endl;
  for(int i=0;i < 10;i++){
    for(int j=0;j < 3;j++){
      cout << '\t' << tablica[i][j];
    }
    cout << endl;
  }
}

void tabl2(){
  cout << "\n\n\n\n";
  int N=100,C4=0,C3=0,SUM=0,X;
  int* A = new int[1000];
  int* B = new int[1000];
  int tablica2[10][3];
  for(int i=0;i < 10;i++){
    tablica2[i][0]=N;
    N+=100;
  }
  N=100;
  for(int i=0;i < 10;i++){
    FillInc(A,N);

    BSearchAll1(A,N,X,&C3);
    SUM = C3;
    tablica2[i][1]=SUM;

    BSearchAll2(B,N,X,&C4);
    SUM = C4;
    tablica2[i][2]=SUM;
    N+=100;
  }
  cout << "\tN\tBSearchAll1 BSearchAll2" << endl;
  for(int i=0;i < 10;i++){
    for(int j=0;j < 3;j++){
      cout << '\t' << tablica2[i][j];
    }
    cout << endl;
  }
}

