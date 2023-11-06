#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000005

int main(){ 
    int N,M,T,i,j;
    int *v1,*v2,*p;
    p = &N;
    scanf("%d",p);
    p = &M;
    scanf("%d",p);
    v1 = (int *) malloc(NMAX*sizeof(int));
    v2 = (int *) malloc(NMAX*sizeof(int));
    for(i=0;i<N;i++){
        *(v1+i) = i+1;
    }
    int flag=0;
    while(M--){
        p = &T;
        scanf("%d",p);
        j=0;
        if(flag==0){
            flag++;
            for(i=0;i<N;i++){
                if((i+1)%T!=0){
                    //como remove os multiplos de T, os não multiplos de T sao adicionados em v2
                    //depois de volta para v1 e assim por diante
                    v2[j++] = v1[i];
                } 
            }
        }
        else{
            flag=0;
            for(i=0;i<N;i++){
                if((i+1)%T!=0){
                    v1[j++] = v2[i];
                } 
            }
        }
        N = j; //N = size dos nao multiplos de T que permanecem, isto eh, quantidade de pessoas que vao para a festa
    }
    if(flag==0){
        if(N>10000) for(i=0;i<10000;i++) printf("%d\n",v1[i]);
        else for(i=0;i<N;i++) printf("%d\n",v1[i]);
    }
    else{
        if(N>10000) for(i=0;i<10000;i++) printf("%d\n",v2[i]);
        else for(i=0;i<N;i++) printf("%d\n",v2[i]);
    }
}