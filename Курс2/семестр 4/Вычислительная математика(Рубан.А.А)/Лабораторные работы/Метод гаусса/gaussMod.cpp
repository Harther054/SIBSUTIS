#include <iostream>
#include <math.h>
using namespace std;

int Columns = 0, Rows = 0;
double Input_Array(double** Arr)
{ 
	for (int i = 0; i < Columns; i++)
	{
		for (int j = 0; j < Rows; j++)
			cin >> Arr[i][j];
	}
	return **Arr;
}

void Print_Array(double** Arr)
{
	for (int i = 0; i < Columns; i++)
	{
		for (int j = 0; j < Rows; j++)
			cout << Arr[i][j] << " ";
		cout << endl;
	}
	cout << "======================" <<endl;
}

double Algorithm(double** Arr)
{
	double temp1 = 0,temp2 = 0, max = 0;
	int k = 0, count = 0;
	
	for(int m = 0; m < Columns; m++)
	{
		max = fabs(Arr[m][m]);
		count = m;
		for(int i = m; i < Columns; i++)
			if(fabs(Arr[i][m]) > max)
			{
				max = fabs(Arr[i][m]);
				count = i;
			}
			
		if(max == 0)
			cout << "Система не имеет решения" << endl;
				
		for(int j = m; j <= Columns; j++)
		{
			temp2 = Arr[m][j];
			Arr[m][j] = Arr[count][j];
			Arr[count][j] = temp2;
		}
		
		temp1 = Arr[m][m];
		for(int j = Columns ; j >= m; j--)
			Arr[m][j] /= temp1;
			
		for(int i = 0; i < Columns; i++)
		{
			if(i == k)
				continue;
			temp1 = Arr[i][m];
			for(int j = Columns; j >= m; j--)
			{
				if(temp1 > 0)
					Arr[i][j] -= Arr[m][j] * temp1;
				else
					Arr[i][j] += Arr[m][j] * fabs(temp1);
			}
		}
		k++;
		
	}		
	return **Arr;
}

int main()
{
	cout << "input Columns" << endl;
	cin >> Columns;
	cout << "input Rows" << endl;
	cin >> Rows;
	Rows += 1;
	double **Array = new double*[Columns];
	for (int i = 0; i < Columns; i++)
		Array[i] = new double[Rows];
		
	Input_Array(Array);
	Print_Array(Array);
	Algorithm(Array);
	Print_Array(Array);
	
	for(int i = 0; i < Columns; i++)
		delete[] Array[i];
	delete Array;
	
	system("pause");
	return 0;
}


