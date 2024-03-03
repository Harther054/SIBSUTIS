/*������� ������, ��� ������ ������� ������ ��������� ������� ���������� �������� ��������� ����� (����� � ������������). 
������� ���������� ���������� � ����������. 
����� ������ ������ ������� ���������� ������ ��������� ���:
time=timer(tip_sort, a, n);
��� � - ������ ��� ����������, ������� ����� ���� ������ ��� ������������� ����.
n-��� ��������� � �������.
n ����� ���������� ������� ��� ������ ������� ����������*/

#include "sort.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#define N 10000

int timer(void (*f) (long long*, int), long long* a, int n)
{
	unsigned int start_time = clock();
	f(a, n);
	unsigned int end_time = clock();
	unsigned int sort_time = end_time - start_time;
	
	return sort_time;
}

int main()
{
	srand(time(0));
	int time;
	long long a[N], temp[N];

	for (int i = 0; i < N; i++)
		{
			a[i] = rand() % 100;
			temp[i] = a[i];
		}

	time = timer(BubbleSort, a, N);
	printf("\n ����� ����������� ����������: %d �����������(�)", time);
	
	for (int i = 0; i < N; i++)
		{
			a[i] = temp[i];
		}

	time = timer(InsertSort, a, N);
	printf("\n\n ����� ���������� ������� ������� ���������: %d �����������(�)", time);
}

