#include <stdio.h>
#include <stdlib.h>

int main() {
	int x,y,z,t,c,g; // числа для ввода
	int sum, com, p; // sum - сумма , com - произведение 	
	printf("input: x,y,z,t,c,g"); // вывод на экран "введите числа"
	scanf("%d%d%d%d%d%d", &x, &y, &z, &t, &c, &g); // 
	sum = x+y+z+t+c+g; // математическая операция  
	com = x*y*z*t*c*g; // математическая операция
	if (sum > com) // если сумма больше произведения то ....
	{
		p = sum - com;
		printf("sum more com"); 
		printf("\n%d > %d", sum, com);// сумма больше произведения 
		printf("\nМеньше на %d", p);
	}
	else if (com > sum) //если произведение больше суммы то ....
	{ 
		p = com - sum;
		printf("com more sum"); // произведение больше суммы
		printf("\n%d > %d", com,sum);
		printf("\nМеньше на %d", p);  
	}
	else if (sum = com) // сумма равна произведению
	{
	printf("sum equal com");
	printf("\n%d = %d", com,sum);
	}
}
