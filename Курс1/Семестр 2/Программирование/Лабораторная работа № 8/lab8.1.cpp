#include <iostream>
#include <ctime>

#define N 5

using namespace std;

struct School //формируем структуру

{

int Number;

int studentsALL;

int students_at_University;

};

void bubbleSort(School schools[], int n) // функция сортировки пузырьком
{
  int i, j;

  for (i = 0; i < n-1; i++)
    for (j = (n - 1); j >i; j--)
      if (( (float)schools[j].students_at_University / schools[j].studentsALL) > ((float) schools[j - 1].students_at_University / schools[j- 1].studentsALL))
        swap(schools[j], schools[j-1]); //сортировка по процентну поступивших в ВУЗ.
}

int main()
{
  srand(time(NULL));
  School schools[N]; //помещаем структуру в массив
  for(int i = 0; i < N; i++)
    schools[i] = {rand() % 100, rand() % 100 + 50, rand() % 50};//заполняем данные структуры рандомными числами

  bubbleSort(schools, N);//вызывем сортировку

  for(int i = 0; i < N; i++ )
  {
    printf("School: %d|Received:|%.2f\n", schools[i].Number, ((float) schools[i].students_at_University / schools[i].studentsALL * 100));//выводим структуру
  }
}
