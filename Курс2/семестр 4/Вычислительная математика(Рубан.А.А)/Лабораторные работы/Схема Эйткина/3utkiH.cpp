#include <iostream>
#include <cmath>

using namespace std;

void input_array(double* X, double* Y, int M)
{
	for(int i(0); i < M; i++)
	{
		cin >> X[i];
		Y[i] = sqrt(X[i]);
	}
	
}

void print_array(double* X, double* Y, int M)
{
	for(int i(0); i < M; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
	for(int i(0); i < M; i++)
	{
		cout << Y[i] << " ";
	}

} 
void print_array2(double** Array, double* Y, int M)
{
	int k = M-1;
	for(int i(0); i < M; i++)
	{
		for(int j(0); j < M; j++)
		{
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
}

double Algorithm(double* X, double* Y, int M, double P, double x, double** Array)
{
	int k = M;
	double numerator = 0, denominator = 0;	
	for(int i(0); i < 3; i++)
	{
		for(int j(0); j < k; j++)
		{
			numerator = Y[j]*(x-X[j+1+i]) - Y[j+1]*(x-X[j]);	
			denominator = X[j]-X[j+1+i];
			Y[j] = (numerator/denominator);
			Array[j][i] = Y[j];	
		}
		print_array2(Array,Y,M);
		k--;
	}
	P = Y[0];
	cout << endl;
	return P;
}
// 1.000 1.4142 1.7321 2.000
int main()
{
	int  M = 0;
	double x = 0.0, P = 0;
	cout << "input M:";
	cin >> M;
	cout << "input P(x):";
	cin >> x;
	double* X = new double[M];
	double* Y = new double[M];
	double** Array = new double*[M];
	for(int i(0); i < M; i++)
		Array[i] = new double[M];
	input_array(X, Y, M);
	P =	Algorithm(X, Y, M, P, x,Array);
	print_array2(Array, Y, M);
	cout << "answer = " << P << endl;
	system("pause");
	return 0;
}
