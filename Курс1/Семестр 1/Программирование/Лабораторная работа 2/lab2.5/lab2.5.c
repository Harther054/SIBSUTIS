#include <stdio.h>
#include <stdlib.h>


int main() {
	int v,x,y,t,z, min;
	printf("input: x,y,t,z");
	scanf("%d%d%d%d", &x,&y,&t,&z);
	min = x;
	if (x < min) min = x, v = 1; 
	if (y < min) min = y, v = 2; 
	if (t < min) min = t, v = 3; 
	if (z < min) min = z, v = 4;
	printf("%d", v);
}
