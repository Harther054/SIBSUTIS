#include <iostream>
#include <math.h>
using namespace std;

int Columns = 0, Rows = 0;
double Input_Array(double** Arr)
{
	for (int i(0); i < Columns; i++)
	{
		for (int j(0); j < Rows; j++)
			cin >> Arr[i][j];
	}
	return **Arr;
}

void Print_Array(double** Arr)
{
	for (int i(0); i < Columns; i++)
	{
		for (int j(0); j < Rows; j++)
			cout << Arr[i][j] << " ";
			
		cout << endl;
	}
	cout << "======================" <<endl;
}

double Algorithm(double** Arr)
{
	double temp = 0;
	int k = 0;
	for(int m(0); m < Columns; m++)
	{	
		temp = Arr[m][m];
		//for(int j = Columns ; j >= m; j--)
		//	Arr[m][j] /= temp;
		for(int j= m; j <= Columns; j++)
		{
			Arr[m][j] /= temp;	
		}	
		for(int i(0); i < Columns; i++)
		{
			if(i == k)
				continue;
			temp = Arr[i][m];
			for(int j = Columns; j >= m; j--)
			{
				if(temp > 0)
					Arr[i][j] -= Arr[m][j] * temp;
				else
					Arr[i][j] += Arr[m][j] * fabs(temp);
			}
		}
		k++;
		Print_Array(Arr);
		cout << m << " Columns ";
		cout << endl;
	}			
	return **Arr;
}
//-2 1 -3 -8 3 1 -6 -9 1 1 2 5 
int main()
{
	cout << "input Columns" << endl;
	cin >> Columns;
	cout << "input Rows" << endl;
	cin >> Rows;
	Rows += 1;
	double **Array = new double*[Columns];
	for (int i(0); i < Columns; i++)
		Array[i] = new double[Rows];
	Input_Array(Array);
	Print_Array(Array);
	Algorithm(Array);
	Print_Array(Array);
	for(int i(0); i < Columns; i++)
	{
		cout << "x" << i << "=" << Array[i][3];
		cout << endl;
	}
	
	for(int i = 0; i < Columns; i++)
		delete[] Array[i];
	delete[] Array;
	
	system("pause");
	return 0;
}


