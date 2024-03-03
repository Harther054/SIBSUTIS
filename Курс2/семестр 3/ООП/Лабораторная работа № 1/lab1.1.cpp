#include <iostream>
#include <ctime>

using namespace std;

int* getArray( int size, int maxValue)
{
	int* mas = new int[size];
	mas[0] = size;
	for (int i = 1; i < size; i++)
	{
		mas[i] = rand() % maxValue;
	}
	return mas;
}


void print(int* arr, int size)
{
	cout << arr[0] << ":";
	for(int i = 1 ; i < size; i++)
		cout << arr[i] << ' ';
}

int main()
{
	srand(time(NULL));
	int size = rand() % 10;
	int maxValue = 100;
	int* arr = getArray(size, maxValue);
	print(arr, size);

	return 0;
}