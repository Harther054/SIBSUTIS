#include <stdio.h>
 
main()
{
float N;
int Z=1, I, X=3;
 
printf("N = ");
scanf("%f",&N);
printf("P-s: 2");
 
while (X<N)
{
   for (I = 2; I < X; I++) {
		if (!(X % I)) {
   		Z = 0;
   		}
	} 
   if (Z){
   printf(",%d",X);
	}
   Z = 1;
 
   X++;
}
return 0;
}
