#include <iostream>
#include <ctime>

using namespace std;

int main(){
  int m, n = 5, max = 0, mi = 0, mj = 0;
  cout << "m:";
  cin >> m;
  int **B = new int*[m];
  for(int i = 0; i < m; i++){          //создаём и заполняем масств
    B[i] = new int[n];
    for(int j = 0; j < n; j++){
      B[i][j] = 1 + rand() % 9;
      cout << B[i][j] << ' ';
    }
    cout << endl;
  }
  for(int i = 0; i < m; i++){         // максимальный элемент
    for(int j = 0; j < n; j++){
      if(B[i][j] > B[mi][mj]){
        mi = i;
        mj = j;
        n--;
        m--;
      }
    }
  }
  int **C = new int*[m];            //создаём массив C
  for(int i = 0; i < m; i++){
    C[i] = new int[n];
  }
  for(int i = mi; i < m; i++){
    C[i] = B[i+1];
  }
  for(int i = 0; i < m; i++){
    for(int j = mj; j < n; j++){
      C[i][j] = C[i][j+1];
    }
  }
  cout << endl;
  for(int i = 0; i < m; i++){              //вывод
    for(int j = 0; j < n; j++){
      cout << C[i][j] << ' ';
    }
    cout << endl;
  }
  for(int i = 0; i <=m; i++){           //удаления массива
    delete[] B[i];
    delete[] B;
    delete[] C[i];
    delete[] C;
  }
  return 0;
}
