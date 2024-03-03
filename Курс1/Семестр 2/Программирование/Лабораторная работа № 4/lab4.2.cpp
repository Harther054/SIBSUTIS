#include <iostream>

#include <stdlib.h>

#include <time.h>

using namespace std;

int main()

{

srand(time(NULL));

int **A,**D,j,i,m = 0, n = 0;

cout << "Enter m: ";

cin >> m;

cout << "Enter n: ";

cin >> n;

cout << endl;

A = new int *[n];

for (int i = 0; i < n; i++)

{

A[i] = new int[m];

}

D = new int *[n + 1];

for (i = 0; i < n + 1; i++)

{

D[i] = new int[m+1];

}

for (i = 0; i < n; i++)

{

for (j = 0; j < m; j++)

{

A[i][j] = rand() % 10;

D[i][j] = A[i][j];

}

}

for (i = 0; i < m; i++)

{

for (j = 0; j < n; j++)

{

D[n][i] += A[j][i];

}

}

for (i =0; i < n; i++)

{

for (j = 0; j < m; j++)

{

D[i][m] += A[i][j];

}

}

for (i =0; i < n; i++)

{

for (j = 0; j < m; j++)

{

D[n][m] += D[i][j];

}

}

for (i = 0; i < n+1; i++)

{

for (j = 0; j < m+1; j++)

{

cout << D[i][j] << " ";

}

cout << endl;

}
}
