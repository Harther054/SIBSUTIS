#include <stdlib.h>
#include <stdio.h>
int main()
{  
    float y1,y2,y3,y4,max2,max1;
    printf("Input y1,y2,y3,y4 ");   scanf("%f%f%f%f",&y1,&y2,&y3,&y4);
    max2 = y1;
    if (y2 > max2) max2 = y2;
    if (y3 > max2) max2 = y3;  
    if (y4 > max2) max2 = y4;
    max1=y1;
    if (y1 > y2 && y1 < max2 ) max1 = y1;
    if (y2 > max1 && y2 < max2 ) max1 = y2;
    if (y3 > max1 && y3 < max2 ) max1 = y3;
    if (y4 > max1 && y4 < max2 ) max1 = y4;
    printf ("max1=%8.2f max2=%8.2f ",max1,max2); 
    return EXIT_SUCCESS;
}

