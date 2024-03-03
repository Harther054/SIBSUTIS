

void BubbleSort(long long* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 2; j >= i; j--)
		{
			if (a[j] > a[j + 1])
			{
				int max = a[j];
				a[j] = a[j + 1];
				a[j + 1] = max;
			}
		}
	}
}

void InsertSort(long long* a, int size)
{
	int temp, i, j;
	for (i = 1; i < size; i++)
	{
		temp = a[i];
		j = i - 1;
		do
		{
			a[j + 1] = a[j];
			j = j - 1;
		} while (j >= 0 && temp < a[j]);
		a[j + 1] = temp;
	}
}
