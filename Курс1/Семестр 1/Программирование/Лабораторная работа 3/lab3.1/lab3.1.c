//Вводится число М - номер месяца. Определить номер квартала и время года по введенному номеру месяца.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

int main() {
	int m;
	setlocale(LC_ALL, "russian");
	printf("Введите месяц:");
	scanf("%d", &m);
	printf("В %d месяце дней:", m);
	
	switch (m)
	{
		case 1:
			printf("31\n");
			printf("квартал 1\n");
			printf("Зима");
			break;
		case 2:
			printf("28/29\n");
			printf("квартал 1\n");
			printf("Зима");
			break;
		case 3: 
			printf("31\n");
			printf("квартал 1\n");
			printf("Весна");
			break;
		case 4:
			printf("30\n");
			printf("квартал 2\n");
			printf("Весна");
			break;
		case 5:
			printf("31\n");
			printf("квартал 2\n");
			printf("Весна");
			break;
		case 6: 
			printf("30\n");
			printf("квартал 2\n");
			printf("Лето");
			break;
		case 7: case 8:
			printf("31\n");
			printf("квартал 3\n");
			printf("Лето");
			break;
		case 9:
			printf("30\n");
			printf("квартал 3\n");
			printf("Осень");
			break;
		case 10: 
			printf("31\n");
			printf("квартал 4\n");
			printf("Осень");
			break;
		case 11:
			printf("30\n");
			printf("квартал 4\n");
			printf("Осень");
			break;
		case 12:
			printf("31\n");
			printf("квартал 4\n");
			printf("Зима");
			break;
	}
	return 0;
}
