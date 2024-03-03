#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((int)time(0));
    int m, n, k, p=0;
    cout << "m="; cin >> m;
      int *A = new int[m];

    cout << "Array A:\n";
    for (int i = 0; i < m; i++)
    {
        A[i]=rand()%9 + 1;
        cout << A[i] << " ";
    }
    cout << "\n";

    cout << "k<m  k="; cin >> k;
    n=m/k;
    if(m%k) n++;

      int **B = new int*[n];
    for (int i = 0; i < n; i++)
       B[i]=new int[k]();

    cout << "Matrix B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if(p<m) B[i][j]=A[p++];
        cout << B[i][j] << " ";
        }
    cout << "\n";
    }

    delete[]A;
    for (int i = 0; i < n; i++)
    delete[]B[i];
    delete[]B;
system("pause");
return 0;
}
