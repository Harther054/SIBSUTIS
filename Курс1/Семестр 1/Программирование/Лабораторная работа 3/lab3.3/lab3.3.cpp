//� ��������� ��������� ���� ����� ��������� ��������: 
//�����, ������, ����, ����, ������, ����,  ������, ����, ��������, �����, ������, ������. 
//��������, ��� 2008 - ��� �����, �������� ���������, ������������ �������� ���� �� ��� ������.
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main(){
   	setlocale(LC_ALL, "russian");
	int s,m;
    printf("������� ��� :");  scanf("%d",&m);
    s=m%12;
    switch(s){
	case 0: 
	printf(" ��������"); 
	break;
    case 1: 
	printf(" ������"); 
	break;
    case 2: 
	printf(" ������"); 
	break;
    case 3: 
	printf(" ������"); 
	break;
    case 4: 
	printf("�����"); 
	break;
    case 5: 
	printf("������"); 
	break;
    case 6: 
	printf(" �����"); 
	break;
    case 7: 
	printf(" �������"); 
	break;
    case 8: 
	printf(" �������"); 
	break;
    case 9: 
	printf("����"); 
	break;
    case 10: 
	printf("������"); 
	break;
    case 11: 
	printf("����"); 
	break;
    default: 
		printf("\n ������");
    }
    return 0;
}
