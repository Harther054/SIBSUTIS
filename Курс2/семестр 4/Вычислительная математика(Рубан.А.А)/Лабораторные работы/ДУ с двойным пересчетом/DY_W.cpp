#include <iostream>
#include <math.h>

using namespace std;
double** create_array(int size, int size1)
{
	double** Array = new double* [size];
	for (int i = 0; i < size; i++)
		Array[i] = new double[size1];

	return Array;
}

void delete_array(double** Array, int size)
{
	for (int i = 0; i < size; i++)
		delete[] Array[i];

	delete[] Array;
}
void Method_Euler(double x, double y, int step, double** y0, double h)
{
	for (int i = 0; i < step; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				y0[i + 1][j] = y0[i][j] + h * y0[i][j + 1];
			else
			{
				y0[i + 1][j] = y0[i][j] + h * (x * y0[i][j] + y0[i][j - 1]);
				x += h;
			}
		}
	}

	for (int i = 1; i <= step; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << y0[i][j] << endl;
		}
		cout << endl;
	}
}
double Method_Runge_Kutta2_by_time(double x, double y, int step, double** y0, double** y1, double* f, double h)
{
	double res1 = 0;
	for (int i = 0; i < step; i++)
	{
		cout << "Шаг" << i + 1 << endl;
		for (int j = 0; j < 2; j++)
		{
			if(j == 0)
				y0[i][j] = f[j] + (h/2) * f[j + 1];
			else
			{
				y0[i][j] = f[j] + (h/2) * (x * f[j] + f[j - 1]);
				x += (h/2);
			}

			cout << y0[i][j] << endl;
		}
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				y1[i][j] = f[j] + h * y0[i][j + 1];
				res1 = y1[i][j];
			}
			else
			{
				y1[i][j] = f[j] + h * (x * y0[i][j] + y0[i][j - 1]);
				x += (h / 2);
			}
			f[j] = y1[i][j];
			cout << y1[i][j] << endl;
		}
	}
	return res1;
}
double Method_Runge_Kutta2_by_derivative(double x, double y, int step, double** y0, double** y1, double* f, double h)
{
	double res1 = 0;
	for (int i = 0; i < step; i++)
	{
		cout << "Шаг" << i + 1 << endl;
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				y0[i][j] = f[j] + (h / 2) * f[j + 1];
			else
			{
				y0[i][j] = f[j] + (h / 2) * (x * f[j] + f[j - 1]); ;
			}

			cout << y0[i][j] << endl;
		}
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				y1[i][j] = f[j] + (h / 2) * (f[j + 1] + y0[i][j + 1]);
				res1 = y1[i][j];
			}
			else
			{
				y1[i][j] = f[j] + (h / 2) * ((x * f[j] + f[j - 1]) + ((x + h) * y0[i][j] + y0[i][j - 1]));
				x += h;
			}
			f[j] = y1[i][j];
			cout << y1[i][j] << endl;
		}
	}
	return res1;
}
double Method_Runge_Kutta4(double x, double y, int step, double** y0, double** y1, double* f, double** k, double h)
{
	double res1 = 0, temp = 0, temp2 = 0;
	for (int i = 0; i < step; i++)
	{
		cout << "Шаг " << i + 1 << endl;
		y1[i][0] = f[0];
		y1[i][1] = f[1];
		for (int g = 0; g < 4; g++)
		{
			if (g % 2 != 0)
				x += h / 2;
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
				{
					k[g][j] = f[j + 1];
				}
				else
				{
					k[g][j] = x * f[j] + f[j - 1];
				}
				g > 1 ? temp = h : temp = h / 2;
				if (g != 3)
				{
					y0[g][j] = y1[i][j] + temp * k[g][j];
					cout << "\t\t" << "y0 = " << y0[g][j] << "\t\t\t" << "k = " << k[g][j] << endl;
				}
				else
				{
					y1[i][j] += (h / 6) * (k[0][j] + (2 * k[1][j]) + (2 * k[2][j]) + k[3][j]);
					cout << "\t\t" << "y1 = " << y1[i][j] << "\t\t\t" << "k = " << k[g][j] << endl;
					res1 = y1[i][j];
				}

			}
			if (g != 3)
			{
				f[0] = y0[g][0];
				f[1] = y0[g][1];
			}
			cout << endl;
		}
	}

	return res1;
}
double Method_Runge_Kutta2_by_time3(double x, double y, int step, double** y0, double** y1, double* k, double h, double* res2)
{
	int res1 = 0;
	int g = 0;

	for (int i = 0; i < step; i++)
	{
		cout << "Шаг" << i + 1 << endl;
		for (int j = 0; j < 3; j++)
		{
			if (j <= 1)
			{
				y0[i][j] = k[j] + (h / 2) * k[j + 2 - g];
				g += 2;
			}
			else
			{
				y0[i][j] = k[j] + (h / 2) * ((exp(x) + k[j - 1]) / 2);
				x += (h / 2);
			}
		}
		g = 0;
		for (int j = 0; j < 3; j++)
		{
			if (j <= 1)
			{
				y1[i][j] = k[j] + h * y0[i][j + 2 - g];
				g+=2;
				if(j == 0)
					res1 = y1[i][j];
			}
			else
			{
				y1[i][j] = k[j] + h * ((exp(x) + y0[i][j - 1]) / 2);
				x += (h / 2);
			}
			k[j] = y1[i][j];
			//cout << k[j] << " ";
			cout << "x = " << x << " ";
			cout <<  y1[i][j] << " ";
		}
		cout << endl;
	}
	return res1;
}
void Menu(int key)
{
	double x = 0, y = 0, eps = 0;
	int step = 0;
	int res1 = 0, res2 = 0;
	double* f = new double[2];
	cout << "Input x, y:" << endl;
	cin >> x >> y;
	cout << "Input Step:" << endl;
	cin >> step;
	cout << "Input Eps:" << endl;
	cin >> eps;

	double g[2];
	if(key != 5)
	{
		cout << "Введите начальное условие" << endl;
		for (int i = 0; i < 2; i++)
		{
			cin >> g[i];
			f[i] = g[i];
		}
	}

	double h = (1.6 - x) / step;
	switch (key)
	{
		case 1:
		{
			double** y0 = new double* [step + 1];
			for (int i = 0; i <= step; i++)
				y0[i] = new double[2];

			for (int i = 0; i < 1; i++)
				for (int j = 0; j < 2; j++)
					y0[i][j] = f[j];

			Method_Euler(x, y, step, y0, h);

			for (int i = 0; i <= step; i++)
				delete[] y0[i];

			delete[] y0;
			break;
		}
		case 2:
		{
			double** y0, **y1;
			y0 = create_array(step, 2);
			y1 = create_array(step, 2);

			res1 = Method_Runge_Kutta2_by_time(x, y, step, y0, y1, f, h);
			delete_array(y0, step);
			delete_array(y1, step);
			delete[] f;
			while (fabs(res1 - res2) >= 3 * eps) {
				res2 = res1;
				step *= 2;
				y0 = create_array(step, 2);
				y1 = create_array(step, 2);
				double* f = new double[2];
				for (int i = 0; i < 2; i++)
					f[i] = g[i];
				h = (1.6 - x) / step;
				res1 = Method_Runge_Kutta2_by_time(x, y, step, y0, y1, f, h);
				delete_array(y0, step);
				delete_array(y1, step);
				delete[] f;
			}
			break;
		}
		case 3:
		{
			double** y0, ** y1;
			y0 = create_array(step, 2);
			y1 = create_array(step, 2);

			res1 = Method_Runge_Kutta2_by_derivative(x, y, step, y0, y1, f, h);
			delete_array(y0, step);
			delete_array(y1, step);
			delete[] f;
			while (fabs(res1 - res2) >= 3 * eps) {
				res2 = res1;
				step *= 2;
				y0 = create_array(step, 2);
				y1 = create_array(step, 2);
				double* f = new double[2];
				for (int i = 0; i < 2; i++)
					f[i] = g[i];
				h = (1.6 - x) / step;
				res1 = Method_Runge_Kutta2_by_derivative(x, y, step, y0, y1, f, h);
				delete_array(y0, step);
				delete_array(y1, step);
				delete[] f;
			}
			break;
		}
		case 4:
		{
			double** y0, ** y1, **k;

			y0 = create_array(4, 2);
			y1 = create_array(step, 2);
			k = create_array(4, 2);

			res1 = Method_Runge_Kutta4(x, y, step, y0, y1, f, k, h);
			delete_array(y0, step);
			delete_array(y1, step);
			delete_array(k, step);
			delete[] f;
			while (fabs(res1 - res2) >= 15 * eps) {
				res2 = res1;
				step *= 2;
				y0 = create_array(4, 2);
				y1 = create_array(step, 2);
				k = create_array(4, 2);
				double* f = new double[2];
				for (int i = 0; i < 2; i++)
					f[i] = g[i];
				h = (1.6 - x) / step;
				res1 = Method_Runge_Kutta4(x, y, step, y0, y1, f,k, h);
				delete_array(y0, step);
				delete_array(y1, step);
				delete_array(k, step);
				delete[] f;
			}

			break;
		}
		case 5:
		{
			h = (0.6 - x) / step;
			double* t = new double[3];
			double* k = new double[3];
			double* res3 = new double[3];
			for (int i = 0; i < 3; i++)
			{
				cin >> t[i];
				k[i] = t[i];
			}

			double** y0, ** y1;
			y0 = create_array(step, 3);
			y1 = create_array(step, 3);

			res1 = Method_Runge_Kutta2_by_time3(x, y, step, y0, y1, k, h, res3);
			delete_array(y0, step);
			delete_array(y1, step);
			delete[] k;
			while (fabs(res1 - res2) >= 3 * eps) {
				res2 = res1;
				step *= 2;
				y0 = create_array(step, 3);
				y1 = create_array(step, 3);
				double* k = new double[3];
				for (int i = 0; i < 3; i++)
					k[i] = t[i];
				h = (1.2 - x) / step;
				res1 = Method_Runge_Kutta2_by_time3(x, y, step, y0, y1, k, h, res3);
				delete_array(y0, step);
				delete_array(y1, step);
				delete[] k;
			}
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int key;
	cout << "1 - Метод Эйлера." << endl;
	cout << "2 - Метод Рунге-Кутта 2-го порядка с усреднением по времени" << endl;
	cout << "3 - Метод Рунге-Кутта 2-го порядка с усреднением по производной" << endl;
	cout << "4 - Метод Рунге-Кутта 4-го порядка" << endl;
	cout << "5 - ДУ 3-порядка" << endl;
	cin >> key;

	Menu(key);

	return 0;
}