#include <iostream>
#include <cmath>

using namespace std;


void input_array(double* X, double* Y, int M)
{
	for(int i(0); i < M; i++)
	{
		cin >> X[i];
	}
	for(int i(0); i < M; i++)
	{
		cin >> Y[i];
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

double Algorithm(double* X, double* Y, int M, double P, double x)
{
	int k = 0;
	double numerator = 1.0, denominator = 1.0;
	for(int i(0); i < M; i++)
	{
		for(int j(0); j < M; j++)
		{
			if(j == k)
				continue;
			numerator *= (x-X[j]);
		}
		for(int g = 0; g < M; g++)
		{
			if(g == k)
				continue;
			denominator *= (X[i]-X[g]);
		}
		P += Y[i]*(numerator/denominator);
		k++;
		numerator = 1.0 , denominator = 1.0;	
	}
	return P;
}
// P = 2.56
// 1 2 3 4 
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
	input_array(X, Y, M);
    P =	Algorithm(X, Y, M, P, x);
    cout << "answer = " << P << endl;
	return 0;
}
