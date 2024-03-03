#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int x,y,z,t;
	printf("input: x,y,z,t");
	scanf("%d%d%d%d", &x,&y,&z,&t);
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (z < 0) z = 0;
	if (t < 0) t = 0;
	printf("%d %d %d %d", x, y, z, t);
}
