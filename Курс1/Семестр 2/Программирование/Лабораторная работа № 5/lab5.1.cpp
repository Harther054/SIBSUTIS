#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
  int n;
  srand(time(NULL));
  n=rand()%10+5;//рандомное количество крок
  int** A = new int*[n];//выделяем память под массив
  for(int i = 0; i < n; i++)
  {
    A[i] = new int[i+ 1 ];
    for(int j = 0; j < i + 1 ; j++)
    {
        A[i][j] = (i+1) * (j+1);//вычислям произведение элементов и заносим в массив
        cout << A[i][j] << ' ';//выводим полученный массив
    }
    printf("\n");
  }
}
