#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
const int  N = 4;

int tabl[4][5] = { {0,0,0,0},
{0, 371279, 743342, 995434, 122237},
{0, 28, 65,	28, 44},
{0,	1993, 1956, 1993, 1977} };
char str[4][10] = { "Ivanov", "Petrov", "SmipHoB", "LopyxoB" };

int* Phone(int k, int* B)
{
	int i, temp, temp2, j, c, c2;
	for (i = 2; i <= N; i++)
	{
		temp = B[i];
		c = B[i];
		temp2 = tabl[k][c];
		j = i - 1;
		c2 = B[j];
		while (j > 0 && temp2 < tabl[k][c2])
		{
			B[j + 1] = B[j];
			j = j - 1;
			c2 = B[j];
		}
		B[j + 1] = temp;
	}
	return B;
}

void Search(int X, int* C, int e)									//�������� �����
{
	int L = 1, R = N, m = N, d;
	while (L <= R)
	{
		m = (L + R) / 2;
		d = C[m];
		if (tabl[e][d] == X)
		{
			L = R;
			printf("%8s", str[d - 1]);
			for (int s = 1; s < N; s++)
			{
				printf("%8d", tabl[s][d]);
			}
		}
		if (tabl[e][d] < X)
		{
			L = m + 1;
		}
		else R = m - 1;
	}
}

int BSearchAll1(int X, int* C, int e)
{
	int L = 1, R = N, found = 0, m = N, d, M;
	while (L <= R)
	{
		m = (L + R) / 2;
		d = C[m];
		if (tabl[e][d] < X)
		{
			L = m + 1;
		}
		else
			if (tabl[e][d] == X)
			{
				found++;
				printf("%8s", str[d - 1]);
				for (int s = 1; s < N; s++)
				{
					printf("%8d", tabl[s][d]);
				}
				printf("\n");
				int M = d;
				M++;
				if (C[M] <= X)
				{
					while (C[M] == X && M <= R)
					{
						found++;
						printf("%8s", str[d - 1]);
						for (int s = 1; s < N; s++)
						{
							printf("%8d", tabl[s][d]);
						}
						printf("\n");
					}
				}

				R = m - 1;
			}

			else R = m - 1;
	}
	if (found == 0)
		printf("No matches");
}

using namespace std;
int main()
{
	int i, j, temp, c, c2, temp2, b, X;


	printf("\n");
	printf(" Name \t  Phone\t      Age   Year\n");
	for (j = 1; j <= N; j++)
	{
		printf("%8s", str[j - 1]);
		for (i = 1; i < N; i++)
		{
			printf("%8d", tabl[i][j]);
		}
		printf("\n");
	}

	int* B;
	B = new int[N + 1];

	for (i = 1; i <= N; i++)
	{
		B[i] = i;
	}

	B = Phone(1, B);

	printf("\n\nPhone sorting:\n\n");
	printf(" Name \t  Phone\t      Age   Year\n");
	for (j = 1; j <= N; j++)
	{
		b = B[j];
		printf("%8s", str[b - 1]);
		for (i = 1; i < N; i++)
		{

			printf("%8d", tabl[i][b]);
		}
		printf("\n");
	}


	int* C;
	C = new int[N + 1];

	for (i = 1; i <= N; i++)
	{
		C[i] = i;
	}

	C = Phone(2, C);

	printf("\n\nAge sorting:\n\n");
	printf(" Name \t  Phone\t      Age   Year\n");
	for (j = 1; j <= N; j++)
	{
		b = C[j];
		printf("%8s", str[b - 1]);
		for (i = 1; i < N; i++)
		{

			printf("%8d", tabl[i][b]);
		}
		printf("\n");
	}

	printf("\nEnter age: ");
	scanf("%d", &X);
	printf("\n");

	BSearchAll1(X, C, 2);

	printf("\n\nEnter phone number: ");
	scanf("%d", &X);
	printf("\n");

	BSearchAll1(X, B, 1);

	return 0;
}
