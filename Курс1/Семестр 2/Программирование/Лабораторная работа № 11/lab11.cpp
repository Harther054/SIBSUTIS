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
		puts("  1 - �������  ���� �� N �������");
		puts("  2 - ����������� ����");
		puts("  3 - �������� � ����� ����� ����� ������");
		puts("  4 - ����� � ������� �� ����� ������ � ����������, ����� ��� �����  �������   ������, ��� 10 ��");
		puts("  5 - �������� ��� ����� ��������� �� �������� �������");
		puts("  0 - �����");
		c = _getch();
		switch (c)
		{
		case '1':input("file2.dat"); break;
		case '2':print("file2.dat"); break;
		case '3':add("file2.dat"); break;
		case '4':find("file2.dat"); break;
		case '5':change("file2.dat"); break;
		case '0':return 0;
		default: puts(" �������� �����");
		}
	}
}
void input(char* name)
{
	int i = 0, n = 0;
	char ch;  FILE* tf;
	tf = fopen(name, "wb");
	system("CLS");
	printf("\n ������� ������� ��������? ");
	scanf("%d", &n);
	printf("\n ���� ������ ���������\n");
	while (i < n)
	{
		printf("\n �������: "); scanf("%s", &t1.surname);
		printf("\n ���: "); scanf("%s", &t1.name);
		printf("\n ��������: "); scanf("%s", &t1.p_name);
		printf("\n ���������� ���������� ������� ����: "); scanf("%d", &t1.places);
		printf("\n ����� ��� �����: "); scanf("%d", &t1.weight);
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

	printf("\n �����\t\t�������\t\t    ���\t\t    ��������\t\t���������� ����\t\t��� ������");

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
	printf("\n ���� ������ ���������\n");
	do
	{
		printf("\n �������: "); scanf("%s", &t1.surname);
		printf("\n ���: "); scanf("%s", &t1.name);
		printf("\n ��������: "); scanf("%s", &t1.p_name);
		printf("\n ���������� ���������� ������� ����: "); scanf("%d", &t1.places);
		printf("\n ����� ��� �����: "); scanf("%d", &t1.weight);
		fwrite(&t1, sizeof(t1), 1, tf);
		printf("\n ���������?  y/n  ");
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

	puts("\n ������� �� ����� ������ � ����������, ����� ��� �����  �������   ������, ��� 10 ��? y/n");

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
				strcpy(t1.surname,"������ �������");
				strcpy(t1.name,"");
				strcpy(t1.p_name,"");
				t1.weight = 0;
				t1.places = 0;
				fwrite(&t1, sizeof(t1), 1, tf);
				fflush(tf);
				printf("\n\n ������ �������!");
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

	puts("\n ������� ���������, ��� ����� �������� ����� ��������");

	fflush(stdin);

	gets(fam);

	printf("\n ���������� ���: ");
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
			printf("\n\n ������ ��������!");
		}
	}

	fclose(tf);
	_getch();
}
