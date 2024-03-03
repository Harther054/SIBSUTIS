#include <iostream>
#include <ctime>

using namespace std;

void** Array_two(int** mass, int n);
void* Array_one(int* D,int n);
void** cpiral_left(int** mass, int* D, int n);
void** diag_left(int** mass, int* D, int n);
void** cpiral_middle(int** mass, int* D, int n);
void** diag_right(int** mass, int* D, int n);

int main()
{
	setlocale(LC_ALL,"rus");
	int n;
	int fin;
	cout << "BBedite pazmer massiBa:";
	cin >> n;
	int** mass = new int*[n];
	for(int i = 0; i < n; i++)
	{
		mass[i] = new int[n];
	}
	int* D = new int[n*n];
	Array_two(mass,n);
	cout << endl;
	Array_one(D,n);
	cout << endl;
	cin >> fin;
	if(fin == 1)
	{
		cpiral_left(mass,D,n);
	}
	if(fin == 2)
	{
		diag_left(mass,D,n);
	}
	if(fin == 3)
	{
		diag_right(mass,D,n);
	}
	if(fin == 4)
	{
		cpiral_middle(mass,D,n);
	}
	for(int i = 0 ; i < n; i++)
	{
		delete[] mass[i];
		
	}
	delete[] mass;

	delete[] D;
	system("pause");
}

void** Array_two(int** mass,int n)
{	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			mass[i][j] = 1 + rand() % 9;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
}
void* Array_one(int* D,int n)
{
	for(int i = 0; i < n*n ; i++)
	{
		D[i] = 0;
	}
}

void** cpiral_left(int** mass, int* D, int n)
{
	int k = 0;
	for(int i = 0; i < n ; i++)
	{
		for(int j = i; j < n-i; j++)								
		{
			D[k] = mass[i][j];
			k++;
		}
		for(int t = i + 1; t < n-i ; t++)
		{
			D[k] = mass[t][n-1-i];
			k++;
		}
		for(int l = n-i-2 ; l > i ; l--)
		{
			D[k]= mass[n-1-i][l];
			k++;
		}
		for(int h = n-1-i; h > i; h--)
		{
			D[k] = mass[h][i];
			k++;
		}

	}
	for(int i = 0; i < n*n ; i++)
	{
		cout << D[i] << " ";
	}
}
void** cpiral_middle(int** mass, int* D, int n)
{
	int k = n%2==0? n/2-1 : n/2;
	int pl_i=0, pl_j=0, flag=0, j=0, sum=1, check=0;
	
	D[0]=mass[k][k];
	for(int i=1; i<n*n; )
	{	
		while((j<sum)&&(i<n*n))
		{
			pl_j++;
			D[i]=mass[k+pl_i][k+pl_j];
			i++;
			j++;
		}
		j=0;

		while((j<sum)&&(i<n*n))
		{
			pl_i++;
			D[i]=mass[k+pl_i][k+pl_j];
			i++;
			j++;
		}
		j=0;
		sum++;	
		while((j<sum)&&(i<n*n))
		{
			pl_j--;
			D[i]=mass[k+pl_i][k+pl_j];
			i++;
			j++;
		}
		j=0;

		while((j<sum)&&(i<n*n))
		{
			pl_i--;
			D[i]=mass[k+pl_i][k+pl_j];
			i++;
			j++;
		}
		j=0;
		sum++;
	}


	for(int i = 0; i < n*n ; i++)
	{
		cout << D[i] << " ";
	}
}

void** diag_left(int** mass, int* D, int n)
{
	int k = 0;
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j <= i; j++)
		{
			D[k]= mass[i-j][j];
			k++;
		}
	}
	for(int j = 1; j < n ; j++)
	{
		for(int i = 0;i <= n-1-j;i++)
		{
			D[k]=mass[n-1-i][j+i];
			k++;
		}
	}
	
	for(int i = 0; i < n*n ; i++)
	{
		cout << D[i] << " ";
	}
}

void** diag_right(int** mass, int* D, int n)
{
	int k = 0;
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j <= i; j++)
		{
			D[k]=mass[i-j][n-1-j];
			k++;
		}
	}
	for(int j = 2; j <= n ; j++)
	{
		for(int i = 0;i <= n-j;i++)
		{
			D[k]=mass[n-1-i][n-j-i];
			k++;
		}
	}
	
	for(int i = 0; i < n*n ; i++)
	{
		cout << D[i] << " ";
	}
}
