//	����� ���������� � ���������� �������� �������  y= (a*x^2+b*x+c)*sin(x) 
// ��� ��������� x �� x���  �� x���  � ����� h.������� �������� y. 
//�������� ������: a  = 2.14;  b= - 4.21;  c = 3.25; x���= -4.5; x��� = -13.5;h= 0.5 .
//(����� min=-361.783, max=308.497)
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
printf("������������ = %.3f  ����������� = %.3f ", max,min );
}


