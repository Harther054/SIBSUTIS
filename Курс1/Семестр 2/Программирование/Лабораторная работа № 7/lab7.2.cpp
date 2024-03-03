#include <iostream>
using namespace std;

int main()
{
	int n, a;
	cin >> n;
	int* sum = new int[n];
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a = rand() % 8 +2;
		A[i] = new int[a];
		A[i][0] = a;
		sum[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < A[i][0]; j++)
		{
			A[i][j] = rand() % 30;
			sum[i] += A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < A[i][0]; j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << sum[i] << '\n';
	}
}
