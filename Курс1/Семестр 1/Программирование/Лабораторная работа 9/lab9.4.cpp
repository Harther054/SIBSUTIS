#include <stdio.h>
#include <stdlib.h>

const int N=3;

int main(){
	int i,j,r,t,a=1,b=5,z=0,A[N][N];
	int a0=1,a1=2,a2=3;
	int b0=1,b1=2,b2=3;
	int c0=1,c1=2,c2=3;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j] = i*N+j+1;
		}
	}
	while(!(a0==a1 && a1==a2 && b0==b1 && b1==b2)){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
			r = (1+rand()%9);
            t = A[r/3][r%3-1];
            A[r/3][r%3-1] = A[i][j];
            A[i][j] = t;
			}	
		}	
		a0=A[0][0]+A[0][1]+A[0][2];
		a1=A[1][0]+A[1][1]+A[1][2];
		a2=A[2][0]+A[2][1]+A[2][2];
		b0=A[0][0]+A[1][0]+A[2][0];
		b1=A[0][1]+A[1][1]+A[2][1];	
		b2=A[0][2]+A[1][2]+A[2][2];
		c0=A[0][0]+A[1][1]+A[2][2];	
		c1=A[0][2]+A[1][1]+A[2][0];	
		z++;	
		}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%2d",A[i][j]);
		}
	printf("\n");	
	}
	printf("Количество = %d",z);
}
