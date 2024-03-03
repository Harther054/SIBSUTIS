#include <iostream>

using namespace std;

int Foo(int a){
	if(a!=1){
		Foo(a/2);
	}
	cout << a%2 << ' ';

}
int main(){
	int a;
	cin >> a;
	Foo(a);
}
