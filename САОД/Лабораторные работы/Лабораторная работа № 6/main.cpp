#include <iostream>
#include "header.h"

void tabl1();
void tabl2();

using namespace std;
int main() {
  int N;
  cin >> N;
  int A[N],C=0,M=0,k=0;
  FillRand(A,N);
  for(int i=0;i<N;i++){
    cout << "" << A[i] << ' ';
  }
  cout << endl;
  ShellSort(A,N,&C,&M,&k);
  for(int i=0;i<N;i++){
    cout << "" << A[i] << ' ';
  }
  cout << endl;
  cout << "C(f)= " << C << " M(f)= " << M << " k= " << k <<endl;
  tabl1();
  tabl2();
  return 0;
}

void tabl1(){
  int N=100,sum=0,M=0,C=0,k=0;
  int tablica[5][4];
  int *A = new int [500];
  int *B = new int [500];
  for(int i=0;i<5;i++){
    tablica[i][0]=N;
    N+=100;
  }
  N=100;
  for(int i=0;i<5;i++){
    FillRand(A,N);

    ShellSort(A,N,&C,&M,&k);
    tablica[i][1]=k;
    k=0;

    IncertSort(A,N,&C,&M);
    sum = C + M;
    tablica[i][2]=sum;

    C=0;M=0;

    ShellSort(A,N,&C,&M);
    sum = C + M;
    tablica[i][3]=sum;
    N+=100;
  }
   cout << "\tN\tk\tInsert\tShell" << endl;
  for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
      cout << '\t' << tablica[i][j];
  }
  cout << endl;
  }
}
void tabl2(){
  cout << endl;
  int N=100,sum=0,M=0,C=0,k=0;
  int tablica[5][5];
  int *A = new int [500];
  int *B = new int [500];
  for(int i=0;i<5;i++){
    tablica[i][0]=N;
    N+=100;
  }
  N=100;
  for(int i=0;i<5;i++){
    FillRand(A,N);

    ShellSort(A,N,&C,&M,&k);
    tablica[i][1]=k;
    k=0;

    C=0;M=0;
    ShellSort(A,N,&C,&M);
    sum = C + M;
    tablica[i][2]=sum;

    tablica[0][3]=57;
    tablica[1][3]=132;
    tablica[2][3]=132;
    tablica[3][3]=301;
    tablica[4][3]=301;

    C=0;M=0;
    ShellSort(A,N,&C,&M);
    sum = C + M;
    tablica[i][4]=sum;

    N+=100;
  }
   cout << "\tN\tk-KHYT\tShell\tk\tShell" << endl;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      cout << '\t' << tablica[i][j];
  }
  cout << endl;
  }
}
