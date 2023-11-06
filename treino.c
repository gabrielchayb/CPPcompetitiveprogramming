#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SMAX 505

char m[60][60];
int tam1,tam2;

void build(){
    char i='A',j='A',value='A';
    //i = linha, j = coluna, value = valor que mudará ao decorrer da construção da tabula rasa
    while(i!='z' || j!='z'){
        m[i-'A'][j-'A'] = value;
        if(j=='z'){
            j = 'A';
            //se value for maiusculo, como chegou na última coluna, basta mudar duas vezes, então A não vira a, mas sim B, logo é só somar +1
            if(value>='A' && value<='Z'){
                value++;
                if(value>'Z') value -= 26; //se ultrapassar, subtrai 26 (letras do alfabeto)
            }
            //se value for minusculo, como chegou na última coluna, basta mudar duas vezes, então A não vira a, mas sim B, logo é só somar +1
            else{
                value++;
                if(value>'z') value -= 26; //se ultrapassar, subtrai 26 (letras do alfabeto)
            }
            //se for letra maiuscula, transforma essa letra em minuscula (só somar 32)
            if(i>='A' && i<='Z') i += 32;
            //se for letra minuscula, volto para maiuscula (decrementa 32) e soma mais 1, para ir para a letra da frente
            else i -= 31;
        }
        else{
            if(value=='z') value = 'A';
            else{
                if(value>='A' && value<='Z') value += 32;
                else value -= 31;
            }
            //se for letra maiuscula, transforma essa letra em minuscula (só somar 32)
            if(j>='A' && j<='Z') j += 32;
            //se for letra minuscula, volto para maiuscula (decrementa 32) e soma mais 1, para ir para a letra da frente
            else j -= 31;
        }
    } m[i-'A'][j-'A'] = value;
}

char letra_cifra(char ch1, char ch2){ //recebe o caractere da mensagem e o caractere da palavra-chave
    char resp; //caractere resposta, atribuo o que esta salvo na tabula rasa nele e retorno
    resp = m[ch1-'A'][ch2-'A'];
    return resp;
}

char *cifra(char *str1, char *str2){
    char *novo; //ponteiro char que é alocado dinamicamente e guardará a mensagem cifrada
    novo = (char *) malloc(tam1*sizeof(char));
    int b=0,c=0; //b representa as posições da str2 (a palavra-chave), ao decorrer do for é incrementado, mas se ultrapassar do tamanho da string, volta para 0
    //c representa as posições de *novo, ao decorrer do for é incrementado
    for(int a=0;a<tam1;a++){
        if(str1[a]!=' '){ //se não for um espaço, é chamado a função letra_cifra para pegar o caractere cifrado
            novo[c++] = letra_cifra(str1[a],str2[b++]);
            if(b==tam2) b=0;
        }
        else novo[c++] = ' '; //se for espaço, essa posição da string será apenas um espaço
    }
    return novo;
}

int main(){
    char *str1,*str2,*str3; 
    //alocação dinamica de duas strings
    str1 = (char *) malloc(SMAX*sizeof(char));
    str2 = (char *) malloc(SMAX*sizeof(char));
    //leitura de duas strings
    gets(str1);
    gets(str2);
    //o tamanho de cada string é salvo em variaveis int
    tam1 = strlen(str1);
    tam2 = strlen(str2);
    //função build é chamada, a qual constroi a tabula rasa
    build();
    //o ponteiro str3 recebe o que será retornado da função
    str3 = cifra(str1,str2);
    //mensagem cifrada resultante é impressa
    for(int i=0;i<tam1;i++) printf("%c",str3[i]);
    //memoria é liberada
    free(str3); free(str2); free(str1);
}
