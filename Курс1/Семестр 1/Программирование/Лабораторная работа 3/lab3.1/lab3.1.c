//�������� ����� � - ����� ������. ���������� ����� �������� � ����� ���� �� ���������� ������ ������.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

int main() {
	int m;
	setlocale(LC_ALL, "russian");
	printf("������� �����:");
	scanf("%d", &m);
	printf("� %d ������ ����:", m);
	
	switch (m)
	{
		case 1:
			printf("31\n");
			printf("������� 1\n");
			printf("����");
			break;
		case 2:
			printf("28/29\n");
			printf("������� 1\n");
			printf("����");
			break;
		case 3: 
			printf("31\n");
			printf("������� 1\n");
			printf("�����");
			break;
		case 4:
			printf("30\n");
			printf("������� 2\n");
			printf("�����");
			break;
		case 5:
			printf("31\n");
			printf("������� 2\n");
			printf("�����");
			break;
		case 6: 
			printf("30\n");
			printf("������� 2\n");
			printf("����");
			break;
		case 7: case 8:
			printf("31\n");
			printf("������� 3\n");
			printf("����");
			break;
		case 9:
			printf("30\n");
			printf("������� 3\n");
			printf("�����");
			break;
		case 10: 
			printf("31\n");
			printf("������� 4\n");
			printf("�����");
			break;
		case 11:
			printf("30\n");
			printf("������� 4\n");
			printf("�����");
			break;
		case 12:
			printf("31\n");
			printf("������� 4\n");
			printf("����");
			break;
	}
	return 0;
}
