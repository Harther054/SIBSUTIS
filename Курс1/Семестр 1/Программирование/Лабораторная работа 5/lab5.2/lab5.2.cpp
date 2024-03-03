//	Найти наибольшее и наименьшее значение функции  y= (a*x^2+b*x+c)*sin(x) 
// при изменении x от xнач  до xкон  с шагом h.Вывести значения y. 
//Исходные данные: a  = 2.14;  b= - 4.21;  c = 3.25; xнач= -4.5; xкон = -13.5;h= 0.5 .
//(ответ min=-361.783, max=308.497)
#include <stdio.h>
#include <math.h>
#include <locale>

int main() {
	setlocale(LC_ALL, "russian");
	float a=2.14,b=-4.21,c=3.25,x1=-4.5,x2=-13.5,h=0.5,y=0,max,min;
	y = (a*pow(x1,2)+b*x1+c)*sin(x1);
	max = y;
	min = y;
	while(x1 >= x2){
	y = (a*pow(x1,2)+b*x1+c)*sin(x1);
	x1 -= h;
	if(max < y){
		max = y;
	}
	if( min > y){
		min = y;
	}
	printf("%.3f\n",y);
	}
printf("Максимальное = %.3f  Минимальное = %.3f ", max,min );
}


