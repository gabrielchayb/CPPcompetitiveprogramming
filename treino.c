#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int soma_palavras=0,soma_paragrafos=0,review_count=0,mudanca=1;
    int tamanho_menor_palavra=INT_MAX; //valor inicialmente muito grande
    int tamanho_maior_palavra=-INT_MAX; //valor inicialmente muito pequeno
    char *menor_palavra,*maior_palavra;
    menor_palavra = (char *) malloc(500);
    maior_palavra = (char *) malloc(500);
    char excecao_palavra[] = " .,;-\n\t()!/\""; //todos os caracteres que não permanecem a composição de uma palavra
    char nome_arquivo[] = "..\\trabalho4\\rev1.bin";
    FILE *p;
    while(1){
        nome_arquivo[16] = mudanca+'0'; mudanca++; //de rev1 passa para rev2 e assim por diante
        p = fopen(nome_arquivo,"rb"); //abre o arquivo
        if(p==NULL){ //se o arquivo não existe (ou se deu erro), acaba o programa
            break;
        }


        review_count++; //contador de arquivos analisados
        char *review_completa = (char *) malloc(5000); 
        int pos=0;
        char c;
        while((c = fgetc(p))!=EOF){ //inicialmente guardamos a review completa em uma string de até 5000 caracteres
            review_completa[pos] = c;
            if(pos!=0 && review_completa[pos]=='\t' && review_completa[pos-1]=='\n'){ //se há um \n seguido de um \t, é um paragrafo
                soma_paragrafos++;
            }
            pos++; //passa para a proxima posição que sera guardado na string review_completa
        } review_completa[pos] = '\0'; //fecha a string com \0


        char *palavra = strtok(review_completa,excecao_palavra); //guarda a primeira palavra da review
        while(palavra!=NULL){ //se realmente existe uma palavra
            soma_palavras++;
            int tam = strlen(palavra);
            if(tam < tamanho_menor_palavra){ //se o tamanho dessa palavra for menor do que o tamanho da menor palavra, guardo a nova palavra
                tamanho_menor_palavra = tam;
                strcpy(menor_palavra,palavra);
            }
            if(tam > tamanho_maior_palavra){ //se o tamanho dessa palavra for maior do que o tamanho da maior palavra, guardo a nova palavra
                tamanho_maior_palavra = tam;
                strcpy(maior_palavra,palavra);
            }
            palavra = strtok(NULL,excecao_palavra); //passa para a próxima palavra da review
        }
        free(review_completa); //libera a memória
        fclose(p); //fecha o arquivo
    }
    p = fopen("..\\trabalho4\\relatorio.out","w"); //arquivo "relatorio.out" é aberto para ser escrito as informações da analise dentro dele
    if(p==NULL){
        printf("Erro.");
        exit(1);
    }
    double media_palavras = (soma_palavras*1.0)/review_count;
    fprintf(p,"1) Media do numero de palavras por review: %.1lf\n",media_palavras);
    double media_paragrafos = (soma_paragrafos*1.0)/review_count;
    fprintf(p,"2) Media do numero de paragrafos por review: %.1lf\n",media_paragrafos);
    fprintf(p,"3) Maior palavra: %s\n",maior_palavra);
    fprintf(p,"4) Menor palavra: %s\n",menor_palavra);
    fclose(p);
    exit(1);
}