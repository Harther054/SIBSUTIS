#include <iostream>

using namespace std;

int Foo(int* B,int N){
  if(N == 0){
    return 0;
  }
  if(*B > 0){
    Foo(B+1,N-1);
    cout << *B << ' ';
  }
  if(*B < 0){
    cout << *B << ' ';
    Foo(B+1,N-1);
  }
}

int main(){
  int N =10;
  int A[N] = {32,43,-2,3,22,-9,88,-57,45,-11};
  Foo(A,N);
  return 0;
}
