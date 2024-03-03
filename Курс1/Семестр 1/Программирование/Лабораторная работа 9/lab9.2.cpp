#include <stdio.h>    
#include <stdlib.h>
#include <math.h>

int main() {
	float a[5][5]; 
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) a[i][j] = (float)rand() * 10 / RAND_MAX;
	printf("Original array: \n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) printf("%3.2f ", a[i][j]);
		printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		float f = 0;
		for (int j = 0; j < 5; j++) {
			f += a[i][j];
		}
		for (int j = 0; j < 5; j++)
			a[i][j] /= f;
	}
	printf("Modified array: \n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) printf("%3.3f ", a[i][j]);
		printf("\n");
	}
	printf("\n"); system("pause");
	return 0;
}
