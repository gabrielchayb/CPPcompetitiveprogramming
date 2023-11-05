#include <stdio.h>

int cont(int N){
   if (N < 10){
      return 1;
   }
   else{
      return 1 + cont(N / 10);
   }
}
int main(){
   int N; //432
   scanf("%d", &N);
   int qtd = cont(N);
   printf("%d", qtd);

}

