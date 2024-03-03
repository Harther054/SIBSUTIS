#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


int f(int x) {
int a = 1;
for (int j = 1; j <= x; j++) a *= j;
return a;
}
int main() {
int C;
int n;
scanf("%d", &n) ;
for (int i = 1; i <=n; i++) {
C = f(n) / (f(i) * f(n-i));
printf("%d ", C); 
}
}
