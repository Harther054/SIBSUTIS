#include <stdio.h>
#include <stdlib.h>


int main() {
	int x,y,z,t,c; // ����� 
	int sym; // ����� ����� 
	printf("input: x,y,z,t,c"); 
	scanf("%d%d%d%d%d", &x, &y,&z, &t, &c); // ����� �������� ���������� 
	if (x > 0) sym += x;
	if (y > 0) sym += y;
	if (z > 0) sym += z;
	if (t > 0) sym += t;
	if (c > 0) sym += c;
	printf("%d", sym); // ����� �� ����� ����� ������������� ����� 	
}
