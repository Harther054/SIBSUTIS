#include <iostream>
#include <ctime>

using namespace std;

struct room //формируем структуру

{

int num;

int sqr;

int fac;//вложенная структура

int popul;

};

struct fac {

int roomAmount = 0;

int sAmount = 0;

float SquareOnPeople = 0;

string name;

};

using namespace std;

int main() {

srand(time(NULL));

room rooms[10];

for (int i = 0; i < 10; i++)

rooms[i] = {i + 1, rand() % 20 + 10, rand() % 5 + 1, rand() % 5 + 1};//заполняем структуру случайными числами

int facAmount = 0;

for (auto &i : rooms)

if (i.fac > facAmount)

facAmount = i.fac;

fac fac[facAmount];//помещаем в отдельный массив

for (int i = 0; i < 10; i++) {

fac[rooms[i].fac].roomAmount++;

fac[rooms[i].fac].sAmount += rooms[i].popul;

fac[rooms[i].fac].SquareOnPeople += rooms[i].sqr;

}

fac[1].name = "IVT";

fac[2].name = "MRM";

fac[3].name = "AES";

fac[4].name = "GF";

for (int i = 0; i < facAmount; i++)

fac[i].SquareOnPeople /= fac[i].sAmount;//ищем среднюю площадь на одного студента

cout << "fac rooms students SquareOnPeople\n";

for (int i = 0; i < facAmount; i++)

if (fac[i].roomAmount) {

cout << fac[i].name << " " << fac[i].roomAmount << " "<< fac[i].sAmount << " "<< fac[i].SquareOnPeople<< endl;//выводим данные о общежитии

}

}
