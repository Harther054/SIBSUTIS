#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#define N 100
#include "sort.h"

void BubbleSort(long long *a, int size);
void InsertSort(long long *a, int size);

int timer(void (*f) (long long*, int), long long* a, int n)
{
	int start_time =  clock()/1000;
	f(a, n);
	int end_time = clock()/1000;
	int sort_time = end_time - start_time;

	//cout << sort_time << endl;

	return sort_time;
}

int main()
{
	srand(time(0));
	int time;
	long long a[N];
	//printf("\n ����� ��������� �������: ");
	//scanf("%d", &n);

	for (int i = 0; i < N; i++)
		{
			a[i] = rand() % 100;
			printf("%d", a[i]);
		}

	Bubblesort(a, N);

	for (int i = 0; i < N; i++)
		{
			//a[i] = rand() % 100;
			printf("%d", a[i]);
		}

	time = timer(BubbleSort, a, N);
	printf("\n ����� ����������� ����������: %d ������", time);

	time = timer(InsertSort, a, N);
		printf("\n ����� ���������� ������� ������� ���������: %d ������", time);
}
