//¬водитс€  целое число —. ≈сли -9<=c<=9 вывести величину числа в словесной форме с учетом знака, в противном случае - предупреждающее сообщение и повторный ввод.
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
	printf("¬ведите число:");
	scanf("%d", &c);
	switch (c) 
		{
			case -9: case -8: case -7: case -6: case -5: case -4: case -3: case -2: case -1: case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
				printf("%d больше или равно -9, либо меньше или равно 9\n", c);
				hoh = false;
				break;
				default: 
				printf("\nerror\n");
				hoh = true;
		}
	}
return EXIT_SUCCESS;
}
