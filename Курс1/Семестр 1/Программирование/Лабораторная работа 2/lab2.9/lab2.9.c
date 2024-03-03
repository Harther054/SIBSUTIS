#include <stdlib.h> 
#include <stdio.h> 
int main() 
{ 
    float y1,y2,y3,max; 
    printf("Input y1,y2,y3 "); scanf("%f%f%f",&y1,&y2,&y3); 
    max=y1; 
    if (y2>max) max=y2; 
    if (y3>max) max=y3; 
    if (max==y1 && y2>y3) printf ("y3=%8.2f y2=%8.2f y1=%8.2f " ,y3,y2,y1); 
    if (max==y1 && y3>y2) printf ("y2=%8.2f y1=%8.2f y3=%8.2f " ,y2,y1,y3); 
    if (max==y2 && y1>y3) printf ("y1=%8.2f y3=%8.2f y2=%8.2f " ,y1,y3,y2); 
    if (max==y2 && y3>y1) printf ("y2=%8.2f y1=%8.2f y3=%8.2f " ,y2,y1,y3); 
    if (max==y3 && y1>y2) printf ("y1=%8.2f y3=%8.2f y2=%8.2f " ,y1,y3,y2); 
    if (max==y3 && y2>y1) printf ("y3=%8.2f y2=%8.2f y1=%8.2f " ,y3,y2,y1); 
    return EXIT_SUCCESS; 
}


