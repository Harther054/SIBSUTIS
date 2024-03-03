#include <stdio.h>
#include <stdlib.h>


int main() {
	int x,y,z,t,c,g,e,f;
	int pl, ot; // pl - положительные, ot - отрицательные.
	pl = 0;
	ot = 0;
	printf("input: x,y,z,t,c,g,e,f");
	scanf("%d%d%d%d%d%d%d%d", &x,&y,&z,&t,&c,&g,&e,&f);
	if (x > 0 ) pl +=1;
	if (y > 0 ) pl +=1;
	if (z > 0 ) pl +=1;
	if (t > 0 ) pl +=1;
	if (c > 0 ) pl +=1;
	if (g > 0 ) pl +=1;
	if (e > 0 ) pl +=1;
	if (f > 0 ) pl +=1;
	ot = 8 - pl;
	printf("%d %d", pl,ot);
	
}
