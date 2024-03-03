#include <iostream>
#include "math.h"

using namespace std;

double func(double x) 
{
    return pow(x, 2) - 3;
}

double func1(double x) 
{
    return 2 * x;
}

double func2(double x) 
{
    return 2;
}

void half_division_method(double a, double b, double eps) 
{
    double c;
    int count = 1;
    while (fabs(b - a) / 2 > eps) {
        cout << "иру " << count << ":\n";
        c = (a + b) / 2;
        cout << "a = " << a << "; b = " << b << "\n";
        cout << "Compare " << func(a) * func(c) << " and " << func(c) * func(b) << ":\n";
        if (func(a) * func(c) < 0) {
            b = c;
            cout << "Take left" << func(a) * func(c) << "\n";
        }
        else if (func(c) * func(b) < 0) {
            a = c;
            cout << "Take Right" << func(c) * func(b) << "\n";
        }
        count++;
    }
    c = (a + b) / 2;
    cout << "\nAnswer:\nx = " << c << "\n";
}

void chord_method(double a, double b, double eps) 
{
    double c, prev_c, numerator = 0, denominator = 0;
    c = numerator / denominator;
    prev_c = c;
    do {
        numerator = a * func(b) - b * func(a);
        denominator = func(b) - func(a);
        c = numerator / denominator;
        func(c);
        if (func(a) * func(c) < 0) {
            prev_c = b;
            b = c;
        }
        else if (func(b) * func(c) < 0) {
            prev_c = a;
            a = c;
        }
    } while (fabs(c - prev_c) > eps);
    c = numerator / denominator;
    cout << "\nAnswer:\nx = " << c << "\n";
}

void newtons_method(double a, double b, double eps) 
{
    double c, k, x;
    if (func(a) / func2(a) > 0) {
        c = a;
    }
    else {
        c = b;
    }
    do {
        k = c;
        c = c - func(c) / func1(c);
    } while (fabs(c - k) > eps);
    cout << "\nx = " << c << "\n";
}

int main() 
{
    double a, b, m_function_value, eps;
    cout << "Enter the left boundary of the segment: ";
    cin >> a;
    cout << "Enter the right boundary of the segment: ";
    cin >> b;
    cout << "Enter the epsilon: ";
    cin >> eps;
    m_function_value = func(a) * func(b);
    cout << "\nMultiplication of the function values at the extreme points: " << m_function_value << "\n";
    half_division_method(a, b, eps);
    //chord_method(a, b, eps);
    //newtons_method(a, b, eps);
    return 0;
}
