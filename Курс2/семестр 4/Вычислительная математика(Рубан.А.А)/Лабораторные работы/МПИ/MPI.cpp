#include <iostream>
#include <cmath>

using namespace std;


double c = 0.0, b = 0.0;
int Columns = 0, Rows = 0;

void input_array(double** C, double* D)
{
	for(int i(0); i < Columns; i++)
	{
		for(int j(0); j < Rows; j++)
			cin >> C[i][j];
	}
	for(int i(0); i < Columns; i++)
		D[i] = 0;
}

void print_array(double** C, double* B)
{
	for(int i(0); i < Columns; i++)
	{
		for(int j(0); j < Rows; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	cout << "============" << endl;
}

double QuantityStep(double E)
{
	return ceil(log((E*(1-c))/b)/log(c));
}

double MaxElement(double Max, double value)
{
	if(Max < value)
		Max = value;
	return Max;
}

double Algorithm(double** C, double* B)
{
	int k = 0;
	double temp = 0.0, maxc = 0.0, maxb = 0.0;
	for(int i(0); i < Columns; i++)
	{
		temp = C[i][i];
		for(int j(0); j < Rows; j++)
		{
			if(i != j)
				C[i][j] /= temp;
			else 
				C[i][j] = 0;
			if(j == Rows - 1)
			{
				B[i] = C[i][j];
			 	C[i][j] = 0;
			}
		}
		for(int l(0); l < Rows-1; l++)
		{
			if(l==k)
				continue;
			maxc += fabs(C[i][l]);
		}
		c = MaxElement(c,maxc);
		maxc = 0;
		k++;
	}
	for(int g(0); g < Columns; g++)
	{
		maxb = fabs(B[g]);
		b = MaxElement(b,maxb);
	}
	return **C;
}
double Step(double** C, double* B, double* D, double* L)
{
	int k = 0;
	cout << "input Step:" << endl;
	cin >> k;
	double temp = 0.0;
	for(int m(0); m < k; m++)
	{
		for(int i(0); i < Columns; i++)
		{
			for(int j(0); j < Rows-1; j++)
				temp += C[i][j] * D[j];
			L[i] = B[i] - temp;
			temp = 0;
		}
		for(int i(0); i < Columns; i++)
			D[i] = L[i];	
	}
	for(int i(0); i < Columns; i++)
		cout << D[i] <<  " ";
}
// 5 -1 2 3 -2 -10 3 -4 1 2 5 12
int main()
{	
	int N = 0;
	double E = 0.0;
	cout << "input Columns:" << endl;
	cin >> Columns;
	cout << "input Rows:" << endl;
	cin >> Rows;
	Rows += 1;
	cout << "input E:" << endl;
	cin >> E;
	double** C= new double*[Columns];
	for(int i(0); i < Columns; i++)
		C[i] = new double[Rows];
		
	double* B = new double[Columns];
	
	double* D = new double[Columns];
	
	double* L = new double[Columns];
	
	input_array(C, D);
	
	print_array(C, B);
	
	Algorithm(C, B);

	N = QuantityStep(E);
	
	cout << "|C| = " << c << endl;
	
	cout << "|B| = " << b << endl;
	
	cout << "N = " << N << endl;
	
	Step(C, B, D, L);
	
	for(int i(0); i < Columns; i++)
		delete[] C[i];
	delete[] C;
	
	delete[] B;
	
	delete[] D;
	
	delete[] L;
	
	system("pause");
	return 0;
}
