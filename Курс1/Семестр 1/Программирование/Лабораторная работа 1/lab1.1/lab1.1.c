#include <stdio.h> // ���������� ����������� ������� � �����  ������������ ��� ��������� �������� ������������ ����� � ������.
#include <math.h> //���������� ������� ������������  ���������� �������������� �������

int main()  // int ��� ����������, main - �������(�������), ()- ������ ����������. 
{	
	float x,y,z,t; // float - ��� ����������, x,y,z,t- ����������.
	printf("input y,z"); // z = 4 , y=2  //printf - �������� ����� �� �����, �� ��� � ������� - ��������� ������.
	scanf("%f%f",&y,&z); // scanf - �������� �����, ("%f%f") - ��������� ������, (&y, &z) - ������ ����������.
	t=5/(1+pow(y,2)); // �������� ���������� t 
	x=2*y+3*sinh(t)-z; // �������� ���������� x
    printf("X = %.2f", x); // printf �������� ������ �� �����, ("��������� ������" ����������) 
	return 0; // ������ ��� ������ �� ������� main.
}
