#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int** genRandMatrix(int size, int maxValue);
int* genRandArray(int size, int maxValue);
void printMatrix(int** matrix, int size);
void print(int* arr, int size);

int main() {
    srand(time(0));
    int size = 1 + rand() % 10;
    int row_size;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
        delete[] matrix;
    }

}
int* genRandArray(int size, int maxValue ) {
    int* arr = new int[size];
    arr[0] = size;
    for (int i = 1; i < size; i++)
    {
        arr[i] = 1 + rand() % maxValue;
    }

    return arr;

}
int** genRandMatrix(int size, int maxValue) {
    int** mas = new int* [size];
    for (int i = 0; i < size; i++)
    {
        int Gsize = 1 + rand() % 10;
        mas[i] = genRandArray(Gsize, maxValue);
    }

    return mas;
}

void print(int* arr, int size) {
    cout << arr[0] - 1 << ":";
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void printMatrix(int** Matrix, int size)
{
    cout << size << endl;
     for (int i = 0; i < size; i++)
       {
            print(Matrix[i], Matrix[i][0]);
            cout << endl;
        }
}