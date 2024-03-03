//В китайском гороскопе года носят следующие названия: 
//крыса, корова, тигр, заяц, дракон, змея,  лошадь, овца, обезьяна, петух, собака, свинья. 
//Учитывая, что 2008 - год крысы, написать программу, определяющую название года по его номеру.
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main(){
   	setlocale(LC_ALL, "russian");
	int s,m;
    printf("Введите год :");  scanf("%d",&m);
    s=m%12;
    switch(s){
	case 0: 
	printf(" Обезьяны"); 
	break;
    case 1: 
	printf(" Петуха"); 
	break;
    case 2: 
	printf(" Собаки"); 
	break;
    case 3: 
	printf(" Свиньи"); 
	break;
    case 4: 
	printf("Крысы"); 
	break;
    case 5: 
	printf("Коровы"); 
	break;
    case 6: 
	printf(" Тигра"); 
	break;
    case 7: 
	printf(" Кролика"); 
	break;
    case 8: 
	printf(" Дракона"); 
	break;
    case 9: 
	printf("Змеи"); 
	break;
    case 10: 
	printf("Лошади"); 
	break;
    case 11: 
	printf("Козы"); 
	break;
    default: 
		printf("\n Ошибка");
    }
    return 0;
}
