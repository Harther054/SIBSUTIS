#include <iostream>
#include <ctime>

using namespace std;

int main(){
  int n,i;
  cin >> n;
  float* a = new float[n];
  float** b = new float*[n];
  srand(time(NULL));

  for (i = 0; i < n; i++) {
    a[i] =(float) (rand () % 1000)/50;
  }
  for ( i = 0; i < n; i++) {
    b[i] = &a[i];
  }
  for (int i = 0; i < n; i++){
    cout << *(a+i) << "\t";

    cout << &a[i]  << "\t";

    cout << b[i]  << endl;
  }
  cout << "======================" << endl;
  for(i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        if(*b[i] > *b[j]){
            float* temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
  }
  for (int i = 0; i < n; i++){
    cout << *b[i]  << endl;
  }
  delete [] b;
  delete [] a;
  return 0;
}
