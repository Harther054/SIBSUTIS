#include <iostream>

using namespace std;

int Foo(int a){
	cin >> a;
	if(a != 0){
		Foo(a);
	}
	if(a>0){
	cout << "|" << a;
	}
}

int main(){
	int a;
	Foo(a);
	system("pause");
	return 0;
}
