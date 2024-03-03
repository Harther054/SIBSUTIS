#include <iostream>
using namespace std;

void ShakerSort(int* A, int n)
{
	int L = 0, R = n - 1, k = n - 1, B;
	for (; L < R;)
	{
		for (int i = R; i > L; i--)
		{
			if (A[i] < A[i - 1])
			{
				B = A[i];
				A[i] = A[i - 1];
				A[i - 1] = B;
				k = i;
			}
		}
		L = k;
		for (int j = L; j < R; j++)
		{
			if (A[j] > A[j + 1])
			{
				B = A[j];
				A[j] = A[j + 1];
				A[j + 1] = B;
				k = j;
			}
		}
		R = k;
	}
}

void perebor(int* A, int n, int b, int* C)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] == b)
		{
			break;
		}
		*C += 1;
	}
}

void binar(int* A, int n, int b, int* C)
{
	int L = 0, R = n - 1, mid = 0, g = -1;
	while (L != R)
	{
		mid = (L + R) / 2;
		*C += 1;
		if (b == A[mid])
		{
			g++;
			break;
		}
		*C += 1;
		if (b < A[mid])
		{
			R = mid;
		}
		else
		{
			L = mid;
		}
	}
	if (g == -1)
	{
		cout << "������";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int* A = new int[100];
	int* B = new int[1000];
	int C1 = 0, C = 0;
	for (int i = 0; i < 100; i++)
	{
		A[i] = rand() % 20;
	}
	for (int i = 0; i < 1000; i++)
	{
		B[i] = rand() % 20;
	}
	ShakerSort(A, 100);
	ShakerSort(B, 1000);
	cout << "\n binar\n";
	binar(A, 100, 6, &C);
	cout << "\n\n" << C;
	cout << "\n binar\n";
	binar(B, 1000, 6, &C1);
	cout << "\n\n" << C1;
	C = 0; C1 = 0;
	cout << "\n perebor\n";
	perebor(A, 100, 6, &C);
	cout << "\n\n" << C;
	cout << "\n perebor\n";
	perebor(B, 1000, 6, &C1);
	cout << "\n\n" << C1;
	return 0;
}
