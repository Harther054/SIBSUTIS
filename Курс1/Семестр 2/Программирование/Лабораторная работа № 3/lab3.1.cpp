#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main(){
  int n,m=0,k;
  printf("n:");
  scanf("%d",&n);
  int *b =(int*) malloc(n*4);
  srand(time(NULL));
  if(b==NULL){
    printf("error!");
    return 1;
  }
  for(int i = 0; i < n; i++){
    b[i] = rand() %100 - 50;
    if(b[i]>0){m++;}
    if(b[i]<0){k++;}
  }
  for(int i = 0; i < n; i++){
    printf("%d  ",b[i]);
  }
  printf("\n%d  ",m);
  printf("\n%d  ",k);
  int *c =(int*) malloc(m*4);
  int *d =(int*) malloc(k*4);
  int j =0;
    printf("\n");
  for(int i = 0; i < n; i++){
    printf("%d  ",b[i]);
  }
  for(int i = 0; j < m; i++){
    printf("%d  ",b[i]);
    if(b[i]>0){
      c[j]=b[i];
      j++;
    }
  }
  printf("\n");
  for(int i = 0; i < m; i++){
    printf("%d  ",c[i]);
  }
}
