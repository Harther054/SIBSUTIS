#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <graphics.h>
#define N 501

void FillRand(int* a, int size)
{
	for (int i = 1; i <= size; ++i)
		a[i] = rand() % 100;
}

void PrintMas(int* a, int size)
{
	for (int i = 1; i <= size; ++i)
		printf("%4d", a[i]);
	puts("\n");
}

void MC(int size)
{
	float Cmax, Mmax;
	Cmax = 2*size*log(size)+size+2;
	Mmax = size*log(size)+6.5*size-4;
	printf("Cmax = %7.2f\nMmax = %7.2f\n", Cmax, Mmax);
}

void FillInc(int* a, int size) {
    for (int i = 1; i <= size; ++i)
        a[i] =  i;
}

void FillDec(int* a, int size) {
    for (int i = 1; i <= size; ++i)
        a[i] =  -i;
}

int ShellSort(int* a, int size)
{int k, k1=0, h=1, j, i, temp, M=0, C=0;
	for(k=h;k<size;k++)
	{
		for (i=k+1; i<=size; i++)
		{
			temp=a[i]; j=i-k;
			while(j>0&&temp<a[j])
			{
				C++;
				a[j+k]=a[j];
				j=j-k;
				M++;
			}
			a[j+k]=temp;
			M++;
		}
	}
	int MC = M + C;
	return MC;
}

void HeapSort(int* a, int size)
{
	int L, R, x, i, j, temp, y=1, M=0, C=0;
	L = size/2;
	R = size;
	while(L>0)
	{
		C++;
		x = a[L]; M++;
		i = L;
		while(y>0)
		{
			j = 2*i;
			if (j>R)
			{
				C++;
				break;
			}
			if (j<R && a[j+1]<=a[j])
			{
				C+=2;
				j = j+1;
			}
			if (x<=a[j])
			{
				C++;
				break;
			}
			a[i]=a[j];
			M++;
			i = j;
		}
		a[i]=x;
		M++;
		L = L-1;
	}
	R = size;
	L = 1;
	while(R > 1)
	{
		C++;
		temp = a[1];
		a[1] = a[R];
		a[R] = temp;
		M+=3;
		R = R-1;
		y=1;
		x = a[L]; M++;
		i = L;
		while(y>0)
		{
			j = 2*i;
			if (j>R)
			{
				C++;
				break;
			}
			if (j<R && a[j+1]<=a[j])
			{
				C+=2;
				j = j+1;
			}
			if (x<=a[j])
			{
				C++;
				break;
			}
			a[i]=a[j];
			M++;
			i = j;
		}
		a[i]=x;
		M++;
	}

	int MC = M+C;
	if (size > 10)
		printf("%12d", MC); else
		printf("\nC = %d, M = %d\n\n", C, M);
}

int HeapSort2(int* a, int size)
{
	int L, R, x, i, j, temp, y=1, M=0, C=0;
	L = size/2;
	R = size;
	while(L>0)
	{
		C++;
		x = a[L]; M++;
		i = L;
		while(y>0)
		{
			j = 2*i;
			if (j>R)
			{
				C++;
				break;
			}
			if (j<R && a[j+1]<=a[j])
			{
				C+=2;
				j = j+1;
			}
			if (x<=a[j])
			{
				C++;
				break;
			}
			a[i]=a[j];
			M++;
			i = j;
		}
		a[i]=x;
		M++;
		L = L-1;
	}
	R = size;
	L = 1;
	while(R > 1)
	{
		C++;
		temp = a[1];
		a[1] = a[R];
		a[R] = temp;
		M+=3;
		R = R-1;
		y=1;
		x = a[L]; M++;
		i = L;
		while(y>0)
		{
			j = 2*i;
			if (j>R)
			{
				C++;
				break;
			}
			if (j<R && a[j+1]<=a[j])
			{
				C+=2;
				j = j+1;
			}
			if (x<=a[j])
			{
				C++;
				break;
			}
			a[i]=a[j];
			M++;
			i = j;
		}
		a[i]=x;
		M++;
	}
	int MC = M+C;
	return MC;
}

using namespace std;
int main()
{
	srand(time(0));
	int a[N];

	printf("\nRandom array:");
	FillRand(a, 500);
	PrintMas(a, 12);

	MC(10);

	printf("\n\nSorted array:\n");
	HeapSort(a, 12);
	PrintMas(a, 12);

	printf(" n  "); printf("\t\tHeapSort(Mf+Cf) \n\t     inc\tdec\t    rand\n");

	for (int i = 100; i <= 500; i += 100)
	{
		printf("%d ", i);
		FillInc(a, i); HeapSort(a, i);
		FillDec(a, i); HeapSort(a, i);
		FillRand(a, i); HeapSort(a, i); puts("\n");
	}

	initwindow(700,700);
	moveto ( 100, 0 );
	lineto ( 100, 700);
	moveto ( 0, 600 );
	lineto ( 700, 600);

	outtextxy ( 50, 50, "Mf+Cf" );
	outtextxy ( 50, 610, "n" );

	for (int i=200; i<=600; i+=100) {
		moveto ( i, 590);
		lineto ( i, 610);
	}
	outtextxy (180, 620, "100" );
	outtextxy (280, 620, "200" );
	outtextxy (380, 620, "300" );
	outtextxy (480, 620, "400" );
	outtextxy (580, 620, "500" );

	for (int i=500; i>=100; i-=100) {
		moveto ( 90, i);
		lineto ( 110, i);
	}

	outtextxy(20, 500, "60.000");
	outtextxy(20, 400, "120.000");
	outtextxy(20, 300, "180.000");
	outtextxy(20, 200, "240.000");
	outtextxy(20, 100, "300.000");

	FillRand(a, 100);
	int b = ShellSort(a, 100);
	float b1 = 600 - (100 / 6) * b / 10000;
	FillRand(a, 200);
	int c = ShellSort(a, 200);
	float c1 = 600 - (100 / 6) * c / 10000;
	FillRand(a, 300);
	int d = ShellSort(a, 300);
	float d1 = 600 - (100 / 6) * d / 10000;
	FillRand(a, 400);
	int e = ShellSort(a, 400);
	float e1 = 600 - (100 / 6) * e / 10000;
	FillRand(a, 500);
	int f = ShellSort(a, 500);
	float f1 = 600 - (100 / 6) * f / 10000;

	setcolor(2);

	outtextxy(600, 170, "ShellSort");

	moveto(200, b1);
	lineto(300, c1);
	lineto(400, d1);
	lineto(500, e1);
	lineto(600, f1);

	setcolor(4);
	outtextxy(600, 550, "HeapSort");
	FillRand(a, 100);
	b = HeapSort2(a, 100);
	b1 = 600 - (100 / 6) * b / 10000;
	FillRand(a, 200);
	c = HeapSort2(a, 200);
	c1 = 600 - (100 / 6) * c / 10000;
	FillRand(a, 300);
	d = HeapSort2(a, 300);
	d1 = 600 - (100 / 6) * d / 10000;
	FillRand(a, 400);
	e = HeapSort2(a, 400);
	e1 = 600 - (100 / 6) * e / 10000;
	FillRand(a, 500);
	f = HeapSort2(a, 500);
	f1 = 600 - (100 / 6) * f / 10000;

	moveto(200, b1);
	lineto(300, c1);
	lineto(400, d1);
	lineto(500, e1);
	lineto(600, f1);

	getch();
	closegraph();

	return 0;
}
