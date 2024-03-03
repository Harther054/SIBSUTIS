#include <iostream>
#include <cstring>

using namespace std;

void input_function(string function)
{
	cout << "f(x)=";
	cin >> function;
	
}

void print_function(string function)
{
	cout << function << endl;	
}

double conversion(string function, int x)
{
	for(int i(0); i< sizeof(function); i++)
	{

	}

	return x;
}

void gold_section(string function)
{

}

int main()
{
	string function;
	string pep;
	int x = 0;
	pep = input_function(function);
	print_function(pep);
	//conversion(function, x);
	//gold_section(function);
	
	system("pause");
	return 0;
}
