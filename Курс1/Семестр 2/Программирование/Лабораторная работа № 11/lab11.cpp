#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

struct tov { char surname[20]; char name[15]; char p_name[15]; int places; int weight; } t1;
void input(char* name);
void print(char* name);
void add(char* name);
void find(char* name);
void change(char* name);

using namespace std;
int main(void)
{
	char c;
	while (1)
	{
		system("CLS");
		puts("  1 - создать  файл из N записей");
		puts("  2 - просмотреть файл");
		puts("  3 - добавить в конец файла новую запись");
		puts("  4 - найти и удалить из файла записи о пассажирах, общий вес вещей  которых   меньше, чем 10 кг");
		puts("  5 - изменить вес вещей пассажира по заданной фамилии");
		puts("  0 - Выход");
		c = _getch();
		switch (c)
		{
		case '1':input("file2.dat"); break;
		case '2':print("file2.dat"); break;
		case '3':add("file2.dat"); break;
		case '4':find("file2.dat"); break;
		case '5':change("file2.dat"); break;
		case '0':return 0;
		default: puts(" пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ");
		}
	}
}
void input(char* name)
{
	int i = 0, n = 0;
	char ch;  FILE* tf;
	tf = fopen(name, "wb");
	system("CLS");
	printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ? ");
	scanf("%d", &n);
	printf("\n пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ\n");
	while (i < n)
	{
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅ: "); scanf("%s", &t1.surname);
		printf("\n пїЅпїЅпїЅ: "); scanf("%s", &t1.name);
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ: "); scanf("%s", &t1.p_name);
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ: "); scanf("%d", &t1.places);
		printf("\n пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ: "); scanf("%d", &t1.weight);
		fwrite(&t1, sizeof(t1), 1, tf);
		i++;
	}
	fclose(tf);
}

void print(char* name)
{
	int i; FILE* tf;
	system("CLS");
	tf = fopen(name, "rb");
	i = 1;

	printf("\n пїЅпїЅпїЅпїЅпїЅ\t\tпїЅпїЅпїЅпїЅпїЅпїЅпїЅ\t\t    пїЅпїЅпїЅ\t\t    пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ\t\tпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ\t\tпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ");

	while (fread(&t1, sizeof(t1), 1, tf))
	{
		printf("\n\n%3d%20s\t%15s\t%20s%20d\t%10d", i, t1.surname, t1.name, t1.p_name, t1.places, t1.weight);
		i++;
	}

	fclose(tf);
	_getch();
}

void add(char* name)
{
	char ch;  FILE* tf;
	tf = fopen(name, "ab");
	system("CLS");
	printf("\n пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ\n");
	do
	{
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅ: "); scanf("%s", &t1.surname);
		printf("\n пїЅпїЅпїЅ: "); scanf("%s", &t1.name);
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ: "); scanf("%s", &t1.p_name);
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ: "); scanf("%d", &t1.places);
		printf("\n пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ: "); scanf("%d", &t1.weight);
		fwrite(&t1, sizeof(t1), 1, tf);
		printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ?  y/n  ");
		ch = _getch();
	}   while (ch != 'y');
	fclose(tf);
}

void find(char* name)
{
	char c; FILE* tf;
	int i = 0;
	system("CLS");

	tf = fopen(name, "rb+");

	puts("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ  пїЅпїЅпїЅпїЅпїЅпїЅпїЅ   пїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅпїЅ 10 пїЅпїЅ? y/n");

	fflush(stdin);

	c = _getch();

	if (c=='y')
	{
		fseek(tf,0,0);
		while (fread(&t1, sizeof(t1), 1, tf))
		{
			if (t1.weight < 10)
			{
				fseek(tf,-sizeof(t1),1);
				strcpy(t1.surname,"пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ");
				strcpy(t1.name,"");
				strcpy(t1.p_name,"");
				t1.weight = 0;
				t1.places = 0;
				fwrite(&t1, sizeof(t1), 1, tf);
				fflush(tf);
				printf("\n\n пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ!");
			}
		}
	}

	fclose(tf);
	_getch();
}

void change(char* name)
{
	system("CLS");

	char c, fam[20]; FILE* tf;
	int size;

	tf = fopen(name, "rb+");

	puts("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ");

	fflush(stdin);

	gets(fam);

	printf("\n пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ: ");
	scanf("%d", &size);

	fseek(tf,0,0);

	while (fread(&t1, sizeof(t1), 1, tf))
	{
		if (strcmp(t1.surname, fam) == 0)
		{
			t1.weight = size;
			fseek(tf,-sizeof(t1),1);
			fwrite(&t1, sizeof(t1), 1, tf);
			fflush(tf);
			printf("\n\n пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ!");
		}
	}

	fclose(tf);
	_getch();
}
