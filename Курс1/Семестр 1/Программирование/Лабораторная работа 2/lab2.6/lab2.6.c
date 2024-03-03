#include <stdio.h>
int Max(int x,int y)
{
    return x>y?x:y;
}
int Min(int x,int y)
{
    return x<y?x:y;
}
int main()
{
    int x,y,z,t;
    scanf("%i",&x);
    scanf("%i",&y);
    scanf("%i",&z);
    scanf("%i",&t);
    int max = Max(Max(x,y),Max(z,t));
    int min = Min(Min(x,y),Min(z,t));
    printf("Max = %i\nMin = %i\nMax - Min = %i\n",max,min,max-min);
}
