#include <stdio.h>
#include <stdlib.h>

int main() {
	int x,y,z,t,c,g; // ����� ��� �����
	int sum, com, p; // sum - ����� , com - ������������ 	
	printf("input: x,y,z,t,c,g"); // ����� �� ����� "������� �����"
	scanf("%d%d%d%d%d%d", &x, &y, &z, &t, &c, &g); // 
	sum = x+y+z+t+c+g; // �������������� ��������  
	com = x*y*z*t*c*g; // �������������� ��������
	if (sum > com) // ���� ����� ������ ������������ �� ....
	{
		p = sum - com;
		printf("sum more com"); 
		printf("\n%d > %d", sum, com);// ����� ������ ������������ 
		printf("\n������ �� %d", p);
	}
	else if (com > sum) //���� ������������ ������ ����� �� ....
	{ 
		p = com - sum;
		printf("com more sum"); // ������������ ������ �����
		printf("\n%d > %d", com,sum);
		printf("\n������ �� %d", p);  
	}
	else if (sum = com) // ����� ����� ������������
	{
	printf("sum equal com");
	printf("\n%d = %d", com,sum);
	}
}
