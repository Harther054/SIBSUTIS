#include <stdlib.h> 
#include <stdio.h> 
int main() 
{ 
    float x,y,z,x1,y1,z1; 
    printf("Input x,y,z "); scanf("%f%f%f",&x1,&y1,&z1); 
    if (x1<y1 && x1<z1 && y1<z1) {
	x=x1;y=y1;z=z1;
	} 
    if (x1<y1 && x1<z1 && z1<y1) {
	x=x1;y=z1;z=y1;
	} 
    if (y1<x1 && y1<z1 && x1<z1) {
	x=y1;y=x1;z=z1;
	} 
    if (y1<x1 && y1<z1 && z1<x1) {
	x=y1;y=z1;z=x1;
	} 
    if (z1<y1 && z1<x1 && y1<x1) {
	x=z1;y=y1;z=x1;
	} 
    if (z1<y1 && z1<x1 && x1<y1) {
	x=z1;y=x1;z=y1;
	} 
    printf ("x=%8.2f y=%8.2f z=%8.2f" ,x,y,z);  
    return EXIT_SUCCESS; 
}

