//3.	Список фамилий вводится через запятую в виде строки. Упорядочить фамилии по алфавиту.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <Windows.h>

using namespace std;
main ( )
{  SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

   char st[] = "Иванов,Павлов,Орлов,Соколов,Морозов", ms[20][80], st2[80];
   int i,j,n,t, m[20];
for(i=j=n=0; st[i]; i++) {
  if (st[i]==',' && st[i+1]!=',') {
    ms[n][j]=0; 
    j=0; 
    n++; 
  }
  else  ms[n][j++]=st[i];
}
ms[n++][j]=0;						

for(i=0; i<n; i++) {				
  printf("%s\n",ms[i]);
  m[i]=1;
}
printf("\n");

for(i=0;i<n-1;i++) {
 t=i;
 for(j=i+1; j<n; j++) 
   if(strcmp(ms[t],ms[j])>0) t=j;
     strcpy(st2,ms[i]); strcpy(ms[i],ms[t]);strcpy(ms[t],st2);
} 
for(i=0; i<n; i++)
  printf("%s\n",ms[i]);

   system("PAUSE");
   return 0; 
}
