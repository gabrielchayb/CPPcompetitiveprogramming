#include <stdio.h>

/*Escrever a função recursiva int max(int n, int *v) que retorna o maior
elemento do vetor v (de n elementos). 
*/

int max(int n, int *v){ // n = 5, v = {1, 2, 3, 4, 5}
      if(n == 1){
         return v[0]; // 1
      }

      int x = max(n-1, v); // x = 4

      if(x > v[n-1]){   // 4 > 5
         return x;
      }

      return v[n-1];    // 5
}

int main(){
   int v[5] = {1, 2, 3, 4, 5};
   printf("%d\n", max(5, v));
   return 0;
}

