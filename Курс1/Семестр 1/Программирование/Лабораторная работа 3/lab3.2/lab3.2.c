//��������  ����� ����� �. ���� -9<=c<=9 ������� �������� ����� � ��������� ����� � ������ �����, � ��������� ������ - ��������������� ��������� � ��������� ����.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int main () {
	setlocale(LC_ALL, "russian");
	bool (hoh) = true;
	int c;
	while (hoh) 
	{
	printf("������� �����:");
	scanf("%d", &c);
	switch (c) 
		{
			case -9: case -8: case -7: case -6: case -5: case -4: case -3: case -2: case -1: case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
				printf("%d ������ ��� ����� -9, ���� ������ ��� ����� 9\n", c);
				hoh = false;
				break;
				default: 
				printf("\nerror\n");
				hoh = true;
		}
	}
return EXIT_SUCCESS;
}
