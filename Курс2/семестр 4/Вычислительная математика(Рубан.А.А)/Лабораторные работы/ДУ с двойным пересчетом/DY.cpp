#include <iostream>
#include <string>

using namespace std;

void Algoritm(double x , double y, float h, int step, double* f, double* DY)
{
	DY[0] = y;
	for (int i = 0; i < step; i++)
	{
		f[i] = 2 * x - DY[i];
		DY[i + 1] = DY[i] + f[i] * h;

		x += h;
		cout << "Step " << i << endl;
		cout << f[i] << endl;
		cout << DY[i + 1] << endl;
	}

}

int main()
{
	double x = 0, y = 0, step = 0;;
	cout << "Input x, y ,h :" << endl;
	cin >> x >> y;
	cout << "input step" << endl;
	cin >> step;

	double* f = new double[step];
	double* DY = new double[step];

	double b = 1.6;
	double h = (b - x) / step;
	Algoritm(x, y, h, step, f, DY);


	return 0;
}