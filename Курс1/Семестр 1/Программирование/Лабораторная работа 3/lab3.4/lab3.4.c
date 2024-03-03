//Вводится номер  месяца М и дня  D.
// Определить  порядковый номер дня в году Т, соответствующий этой дате.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
	setlocale(LC_ALL, "russian");
	int m,d,t;
	t=2;// m - месяц, d - день, t - порядковый номер дня в году.
	printf("Введите номер месяца и дня:\n ");
	scanf("%d%d", &m,&d);
	printf("%d",t);
	switch (m)
	{
		case 1:
			t = d;
			printf("Это %d день в году ", t);
			break;
		case 2:
			t = 31+d;
			printf("Это %d день в году ", t);
			break;
		case 3:
			t = 59+d;
			printf("Это %d день в году ", t);
			break;
		case 4: 
			t = 90+d;
			printf("Это %d день в году ", t);
			break;
		case 5:
			t = 120+d;
			printf("Это %d день в году ", t);
			break;
		case 6:
			t = 151+d;
			printf("Это %d день в году ", t);
			break;
		case 7:
			t = 181+d;
			printf("Это %d день в году ", t);
			break;
		case 8:
			t =212+d;
			printf("Это %d день в году ", t);
			break;
		case 9:
			t = 243+d;
			printf("Это %d день в году ", t);
			break;
		case 10:
			t = 273+d;
			printf("Это %d день в году ", t);
			break;
		case 11:
			t = 304+d;
			printf("Это %d день в году ", t);
			break;
		case 12:
			t = 335+d;
			printf("Это %d день в году ", t);
			break;
			
	}	
	return 0;
}
