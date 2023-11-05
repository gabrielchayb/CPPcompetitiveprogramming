#include <stdio.h>

/*(8 pontos) Faça uma função chamada maxpot() que recebe como parâmetros três
inteiros: X, Y e MAX. Esta função deve devolver 2 valores:
- O resultado de XY
, SEM usar a função pronta pow (exponenciação) da linguagem c;
- O valor 1 (um) se resultado de XY
for maior que MAX, ou 0 (zero) caso contrário
*/

int maxpot(int x, int y, int max){
      int i, resultado = 1;

      for(i = 0; i < y; i++){
         resultado = x * resultado;
      }

      if(resultado > max){
         return 1;
      }
      
      else{
         return 0;
      }
}

int main(){
   int x, y, max;
   scanf("%d %d %d", &x, &y, &max);
   printf("%d\n", maxpot(x, y, max));
   return 0;
}

