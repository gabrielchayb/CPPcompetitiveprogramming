#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ***m, ***aux; // ponteiros que virarão matrizes tridimensionais (uma é a principal,  a outra uma auxiliar)
// ambas guardam o numero de vendas de um produto em cada trimestre de uma filial
int **v;                                         // ponteiro que virará matriz bidimensional (guardará a soma total de cada venda de um produto em cada filial)
int nfiliais, nprodutos;                         // nfilias= número de filiais e nprodutos= número de prdutos
int verifica, verificafilial, verificaproduto;   // variaveis utilizadas para verificar se o sistema já foi inicializado antes e se foi inserido os nomes das filiais e dos produtos
char **nomesfiliais, **nomesprodutos, **nomeaux; // ponteiros que virarão matrizes bidimensionais (uma guardando os nomes do produtos e a outra as filiais)

void Inicializar(){
    if (verifica == 0){
        // verifica se o sistema já foi inicializado anteriormente
        verifica = 1; // marca que já foi inicializado para futuras inicializações
        printf("Insira o numero de filiais: ");
        scanf("%d", &nfiliais);
        printf("Insira o numero de produtos: ");
        scanf("%d", &nprodutos);
        m = (int ***)malloc(nfiliais * sizeof(int **)); // aloca o numero de filiais
        v = (int **)malloc(nfiliais * sizeof(int *));  // aloca o numero de filiais
        for (int i = 0; i < nfiliais; i++){
            m[i] = (int **)malloc(nprodutos * sizeof(int *)); // aloca o numero de produtos
            v[i] = (int *)malloc(nprodutos * sizeof(int));  // aloca o numero de produtos
            for (int j = 0; j < nprodutos; j++){
                m[i][j] = (int *)malloc(4 * sizeof(int)); // aloca o numero de trimestres
                v[i][j] = 0;
                for (int k = 0; k < 4; k++){
                    m[i][j][k] = 0; // coloca tudo como zero inicialmente
                }
            }
        }
        printf("\n");
    }
    else{ 
        // já foi inicializado anteriomente, entra no else
        // temos que liberar tudo antes de inicializar novamente
        for (int i = 0; i < nfiliais; i++){
            for (int j = 0; j < nprodutos; j++){
                free(m[i][j]); // libera a 3° dimensão
            }
            free(m[i]); // libera a 2° dimensão
            free(v[i]); // libera a 2° dimensão
        }
        free(m); // libera a 1° dimensão
        free(v); // libera a 1° dimensão
        if (verificafilial){
            for (int i = 0; i < nfiliais; i++)
                free(nomesfiliais[i]); // libera a 2° dimensão
            free(nomesfiliais);        // libera a 1° dimensão
        }
        if (verificaproduto){
            for (int j = 0; j < nprodutos; j++)
                free(nomesprodutos[j]); // libera a 2° dimensão
            free(nomesprodutos);        // libera a 1° dimensão
        }
        // Após isso podemos inicializar normalmente
        printf("Insira o numero de filiais: ");
        scanf("%d", &nfiliais);
        printf("Insira o numero de produtos: ");
        scanf("%d", &nprodutos);
        m = (int ***)malloc(nfiliais * sizeof(int **)); // aloca o numero de filiais
        v = (int **)malloc(nfiliais * sizeof(int *));  // aloca o numero de filiais
        for (int i = 0; i < nfiliais; i++){
            m[i] = (int **)malloc(nprodutos * sizeof(int *)); // aloca o numero de produtos
            v[i] = (int *)malloc(nprodutos * sizeof(int));  // aloca o numero de produtos
            for (int j = 0; j < nprodutos; j++){
                m[i][j] = (int *)malloc(4 * sizeof(int)); // aloca o numero de trimestres
                v[i][j] = 0;
                for (int k = 0; k < 4; k++){
                    m[i][j][k] = 0; // coloca tudo como zero inicialmente
                }
            }
        }
    }
    printf("INICIALIZACAO FEITA COM SUCESSO!!!\n");
}

void FecharSistema(){
    printf("\nOBRIGADO POR UTILIZAR O SISTEMA!!!\n");
    for (int i = 0; i < nfiliais; i++){
        for (int j = 0; j < nprodutos; j++){
            free(m[i][j]); // libera a 3° dimensão
        }
        free(m[i]); // libera a 2° dimensão
        free(v[i]); // libera 2° dimensão
    }
    free(m); // libera a 1° dimensão
    free(v); // libera a 1°dimensão
    for (int i = 0; i < nfiliais; i++)
        free(nomesfiliais[i]); // libera a 2° dimensão
    free(nomesfiliais);        // libera a 1° dimensão
    for (int j = 0; j < nprodutos; j++)
        free(nomesprodutos[j]); // libera a 2° dimensão
    free(nomesprodutos);        // libera a 1° dimensão
}

void NomeProdutos(){
    if (verifica)
    { // se verifica for 1 significa que já aconteceu a inicialização
        getchar();
        verificaproduto = 1;
        nomesprodutos = (char **)malloc(nprodutos * sizeof(char *)); // aloca a 1° dimensão
        printf("Insira os produtos\n");
        for (int j = 0; j < nprodutos; j++){
            nomesprodutos[j] = (char *)malloc(100 * sizeof(char)); // aloca a 2° dimensão
            printf("Produto %d: ", j + 1);
            gets(nomesprodutos[j]);
        }
        printf("\nPRODUTOS INSERIDOS COM SUCESSO\n");
        for (int i = 0; i < nprodutos; i++){
            printf("Produto %d: %s\n", i + 1, nomesprodutos[i]);
        }
    }
    else
        printf("\nAinda nao foi feita a inicializacao\n");
}

void NomeFiliais()
{
    if (verifica)
    { // se verifica for 1 significa que já aconteceu a inicialização
        getchar();
        verificafilial = 1;
        nomesfiliais = (char **)malloc(nfiliais * sizeof(char *)); // aloca a 1° dimensão
        printf("Insira as filiais \n");
        for (int i = 0; i < nfiliais; i++){
            nomesfiliais[i] = (char *)malloc(100 * sizeof(char)); // aloca a 2° dimensão
            printf("Filial %d: ", i + 1);
            gets(nomesfiliais[i]);
        }
        printf("\n");
        printf("\nFILIAIS INSERIDAS COM SUCESSO\n");
        for (int i = 0; i < nfiliais; i++){
            printf("Filial %d: %s\n", i + 1, nomesfiliais[i]);
        }
    }
    else
        printf("\nAinda nao foi feita a inicializacao\n");
}

void ProdutoTrimestre(){
    if (verifica){
        int t;            // trimestre específico
        char *pescolhido; // produto escolhido
        pescolhido = (char *)malloc(100 * sizeof(char));
        printf("Trimestre escolhido (1, 2, 3, 4): ");
        scanf("%d", &t);
        if (t != 1 && t != 2 && t != 3 && t != 4){
            printf("\nTrimestre inexistente\n");
        }
        else{
            getchar();
            printf("Insira o nome do produto: ");
            gets(pescolhido);
            int verifica2 = 0; // variável para verificar se o produto está no catálogo
            int guarda;        // variável que vai guardar a posição do produto no catálogo
            for (int i = 0; i < nprodutos; i++){
                if (strcmp(pescolhido, nomesprodutos[i]) == 0){
                    verifica2 = 1;
                    guarda = i;
                    break;
                }
            }
            if (verifica2 == 1){
                int x;
                printf("Insira o valor vendido no trimestre %d em cada uma das filiais\n", t);
                for (int j = 0; j < nfiliais; j++){
                    printf("Filial %d: ", j + 1);
                    scanf("%d", &x);
                    m[j][guarda][t - 1] += x;
                    /*somando na posição j que representa a filial, na posição guarda que representa
                    o produto, na posição t-1 (pois é indexado em 0) que representa o trimestre o
                    valor lido em x */
                    v[j][guarda] += x; // soma para guardar o total de vendas de um produto em uma filial
                }
                printf("\nOs valores foram inseridos com sucesso!!!\n");
            }
            else
                printf("\nProduto nao encontrado no catalogo\n");
        }
        free(pescolhido); // libera a 1° dimensão
    }
    else
    {
        printf("\nAinda nao foi feita a inicializacao\n");
    }
}

void ProdutoFilial()
{
    if (verifica){
        char *pescolhido; // produto escolhido
        char *fescolhida; // filial escolhida
        pescolhido = (char *)malloc(100 * sizeof(char));
        fescolhida = (char *)malloc(100 * sizeof(char));
        getchar();
        printf("Insira o nome do produto: ");
        gets(pescolhido);
        int verifica2 = 0; // variável para verificar se o produto está no catálogo
        int guarda;        // variável que vai guardar a posição do produto no catálogo
        for (int i = 0; i < nprodutos; i++){
            if (strcmp(pescolhido, nomesprodutos[i]) == 0){
                verifica2 = 1;
                guarda = i;
                break;
            }
        }
        if (verifica2 == 1){
            printf("Insira o nome da filial: ");
            gets(fescolhida);
            int verifica3 = 0; // variável para verificar se a filial está no catálogo
            int guarda2;       // variável que vai guardar a posição da filial no catálogo
            for (int i = 0; i < nfiliais; i++){
                if (strcmp(fescolhida, nomesfiliais[i]) == 0){
                    verifica3 = 1;
                    guarda2 = i;
                    break;
                }
            }
            if (verifica3 == 1){
                int x;
                printf("Insira o valor vendido do produto %s na filial %s nos 4 trimestres\n", nomesprodutos[guarda], nomesfiliais[guarda2]);
                for (int k = 0; k < 4; k++){
                    printf("Trimestre %d: ", k + 1);
                    scanf("%d", &x);
                    m[guarda2][guarda][k] += x; // aqui soma a venda em um trimestre específico de um produto em uma filial
                    v[guarda2][guarda] += x;    // aqui soma a venda do produto em uma filial, independente do trimestre
                }
                printf("\nValores inseridos com sucesso\n");
            }
            else
                printf("\nFilial nao encontrada no catalogo\n");
        }
        else
            printf("\nProduto nao encontrado no catalogo\n");
        free(pescolhido); // libera a 1° dimensão
        free(fescolhida); // libera a 1° dimensão
    }
    else
    {
        printf("\n Ainda nao foi feita a inicializacao\n");
    }
}

void ProdutoMaisVendidoFilial(){
    if (verifica){
        int maior;
        for (int i = 0; i < nfiliais; i++){
            //como precisa saber o produto mais vendido de cada filial, faz um laço de repeticao pelas nfiliais inicialmente
            maior = -999999; //define o maior como um valor muito pequeno inicialmente
            for (int j = 0; j < nprodutos; j++){
                if (v[i][j] > maior) //condição para pegar a maior quantidade de vendas de um determinado produto
                    maior = v[i][j];
            }
            printf("Na filial %s, a maior quantidade de um produto vendido foi %d\n", nomesfiliais[i], maior);
            printf("O(s) produto(s) que conseguiram essa quantidade: \n");
            for (int k = 0; k < nprodutos; k++){
                if (v[i][k] == maior) //imprime X produtos com a maior quantidade de vendas possiveis de uma filial i
                    printf("%s\n", nomesprodutos[k]);
            }
            printf("\n");
        }
    }
    else printf("\nAinda nao foi feita a inicializacao\n");
}

void FilialMaisVende(){
    if (verifica){
        int maior = -999999, *soma;
        soma = (int *)malloc(nfiliais * sizeof(int));
        for (int i = 0; i < nfiliais; i++)
        { // laço de repetição para descobrir a maior soma de produtos vendidos
            soma[i] = 0;
            for (int j = 0; j < nprodutos; j++){
                soma[i] += v[i][j];
            }
            if (soma[i] > maior)
                maior = soma[i];
        }
        printf("A maior quantidade de produtos vendidos em geral foi: %d\n", maior);
        printf("As filiais que conseguiram essa quantidade foram: \n");
        for (int i = 0; i < nfiliais; i++){
            if (soma[i] == maior)
                printf("%s\n", nomesfiliais[i]);
        }
    }
    else printf("\nAinda nao foi feita a inicializacao\n");
}

void FilialMaisVendeTrimestre()
{
    if (verifica){
        int t; // trimestre específico
        printf("Insira o trimestre (1,2,3,4) que deseja saber: ");
        scanf("%d", &t);
        if (t != 1 && t != 2 && t != 3 && t != 4){
            printf("\nTrimestre Inexistente\n");
        }
        else{
            int maior = -999999, *soma;
            soma = (int *)malloc(nfiliais * sizeof(int));
            for (int i = 0; i < nfiliais; i++)
            { // laço de repetição para descobrir a maior soma de produtos vendidos
                soma[i] = 0;
                for (int j = 0; j < nprodutos; j++){
                    soma[i] += m[i][j][t - 1];
                }
                if (soma[i] > maior)
                    maior = soma[i];
            }
            printf("A maior quantidade de produtos vendidos no trimestre %d em geral foi: %d\n", t, maior);
            printf("As filiais que conseguiram essa quantidade foram: \n");
            for (int i = 0; i < nfiliais; i++){
                if (soma[i] == maior)
                    printf("%s\n", nomesfiliais[i]);
            }
        }
    }
    else
    {
        printf("\nAinda nao foi feita a inicializacao\n");
    }
}

void ProdutoMaisVendido(){
    if (verifica){
        int maior = -999999, *soma;
        soma = (int *)malloc(nfiliais * sizeof(int));
        for (int i = 0; i < nprodutos; i++)
        { // laço de repetição para descobrir a quantidade de cada produto vendido
            soma[i] = 0;
            for (int j = 0; j < nfiliais; j++){
                soma[i] += v[j][i];
            }
            if (soma[i] > maior)
                maior = soma[i]; //salva a maior quantidade de vendas de um produto
        }
        printf("A maior quantidade de um produto vendido foi: %d\n", maior);
        printf("Os produtos que conseguiram essa quantidade foram: \n");
        for (int i = 0; i < nfiliais; i++){
            if (soma[i] == maior)
                printf("%s\n", nomesprodutos[i]); //imprime o nome do produto, porem pode imprimir mais de um produto caso eles possuam
                //a mesma quantidade de vendas
        }
    }
    else printf("\nAinda nao foi feita a inicializacao\n");
}

void MelhorTrimestre(){
    if (verifica){
        int maior = -999999; //como deve ser pego o maior valor, a variavel deve ser inicialmente um valor muito pequeno
        int *soma;
        soma = (int *)malloc(4 * sizeof(int));
        for (int k = 0; k < 4; k++){
            soma[k] = 0;
            for (int i = 0; i < nfiliais; i++){
                for (int j = 0; j < nprodutos; j++){
                    soma[k] += m[i][j][k];
                }
            }
            if (soma[k] > maior)
                maior = soma[k]; //salva a maior quantidade de vendas por trimestre
        }
        printf("A maior quantidade vendida em um trimestre foi: %d\n", maior);
        printf("Os trimestres que conseguiram essa quantidade foram: ");
        for (int i = 0; i < 4; i++){
            if (soma[i] == maior)
                printf("Trimestre %d ", i + 1); //imprime o indice do melhor trimestre possivel, porem pode haver mais de um com a mesma
                //quantidade de vendas
        }
        printf("\n");
    }
    else printf("\nAinda nao foi feita a inicializacao\n");
}

void PiorTrimestre(){
    if (verifica){
        int menor = 999999; //como deve ser pego o menor valor, a variavel deve ser inicialmente um valor muito grande
        int *soma;
        soma = (int *)malloc(4 * sizeof(int));
        for (int k = 0; k < 4; k++){
            soma[k] = 0;
            for (int i = 0; i < nfiliais; i++){
                for (int j = 0; j < nprodutos; j++){
                    soma[k] += m[i][j][k];
                }
            }
            if (soma[k] < menor)
                menor = soma[k]; //salva a menor quantidade de vendas por trimestre
        }
        printf("A menor quantidade vendida em um trimestre foi: %d\n", menor);
        printf("Os trimestres que conseguiram essa quantidade foram: ");
        for (int i = 0; i < 4; i++){
            if (soma[i] == menor)
                printf("Trimestre %d ", i + 1); //imprime o indice do pior trimestre possivel, porem pode haver mais de um com a mesma
                //quantidade de vendas
        }
        printf("\n");
    }
    else printf("\nAinda nao foi feita a inicializacao\n");
}

void InserirFilial(){
    if (verifica){
        int x = nfiliais;                                // variavel para guardar o valor original de nfiliais
        nfiliais++;                                      // incrementa o nfiliais
        m = (int ***)realloc(m, nfiliais * sizeof(int **)); // realoca nova filial
        v = (int **)realloc(v, sizeof(int *));             // realoca nova filial
        m[x] = (int **)malloc(nprodutos * sizeof(int *));  // insere os produtos nela
        v[x] = (int *)malloc(nprodutos * sizeof(int));   // insere os produtos nela
        for (int j = 0; j < nprodutos; j++){
            m[x][j] = (int *)malloc(4 * sizeof(int)); // insere os trimestres
            v[x][j] = 0;                              // marca o total de filial e produto como zero
            for (int k = 0; k < 4; k++){
                m[x][j][k] = 0; // marca o valor de cada trimestre como zero
            }
        }
        printf("Insira o nome da nova filial: ");
        nomesfiliais = (char **)realloc(nomesfiliais, nfiliais * sizeof(char *)); // realoca a nova filial no catalogo de filiais
        nomesfiliais[x] = (char *)malloc(100 * sizeof(char));                   // aloca o numero de letras
        getchar();
        gets(nomesfiliais[x]);
        printf("\nFilial %s inserida com sucesso\n", nomesfiliais[x]);
    }
    else printf("\nNao foi feita a inicializacao, seria melhor inicializar ao inves de inserir nova filial\n");
}
void InserirProduto(){
    if (verifica){
        int x = nprodutos; // variavel para guardar o valor original de nprodutos
        nprodutos++;       // incrementa o nprodutos
        for (int i = 0; i < nfiliais; i++){
            m[i] = (int **)realloc(m[i], nprodutos * sizeof(int *)); // aloca o numero de produtos
            v[i] = (int *)realloc(v[i], nprodutos * sizeof(int));  // aloca o numero de produtos
            m[i][x] = (int *)malloc(4 * sizeof(int));              // aloca o numero de trimestres
            v[i][x] = 0;
            
            for (int k = 0; k < 4; k++){
                m[i][x][k] = 0; // coloca tudo como zero inicialmente
            }
        }
        printf("Insira o nome do novo produto: ");
        nomesprodutos = (char **)realloc(nomesprodutos, nprodutos * sizeof(char *));
        nomesprodutos[x] = (char *)malloc(100 * sizeof(char));
        getchar();
        gets(nomesprodutos[x]);
        printf("\nProduto %s inserido com sucesso\n", nomesprodutos[x]);
    }
    else printf("\nNao foi feita a inicializacao, seria melhor inicializar ao inves de inserir novo produto\n");
}

void RemoverProduto(){
    if (verifica){
        char *pescolhido;  // produto escolhido para ser removido
        int guarda;        // guarda a posição do produto a ser removido
        int verifica2 = 0; // verifica se existe esse produto no catalogo
        getchar();
        printf("Insira o nome do produto a ser removido: ");
        pescolhido = (char *)malloc(100 * sizeof(char));
        gets(pescolhido);
        for (int i = 0; i < nprodutos; i++)
        {
            if (strcmp(pescolhido, nomesprodutos[i]) == 0)
            {
                verifica2 = 1;
                guarda = i;
            }
        }
        if (verifica2 == 0)
            printf("O produto nao esta no catalogo\n");
        else
        {
            aux = (int ***)malloc(nfiliais * sizeof(int **)); // criando a matriz auxiliar tridimensional
            nprodutos--;                                   // decrementa o numero de produtos pois um será removido
            for (int i = 0; i < nfiliais; i++){
                aux[i] = (int **)malloc(nprodutos * sizeof(int *));
                for (int j = 0; j < nprodutos; j++){
                    aux[i][j] = (int *)malloc(4 * sizeof(int));
                }
            }
            int l = 0, c = 0, t = 0; // l=linha, c=coluna, t=trimestre, variavel auxiliares para salvar os novos valores
            for (int i = 0; i < nfiliais; i++){
                for (int j = 0; j < nprodutos + 1; j++){ 
                    // tem que somar +1 para podermos acessar todas as posições da matriz original
                    for (int k = 0; k < 4; k++){
                        if (j != guarda){
                            aux[l][c][t] = m[i][j][k];
                            t++;
                        }
                    }
                    if (t == 4){
                        t = 0;
                        c++;
                    }
                }
                if (c == nprodutos){
                    c = 0;
                    l++;
                }
            }
            // Limpar a variável original
            for (int i = 0; i < nfiliais; i++){
                for (int j = 0; j < nprodutos + 1; j++){
                    free(m[i][j]); // libera a 3° dimensão
                }
                free(m[i]); // libera a 2° dimensão
                free(v[i]); // libera 2° dimensão
            }
            free(m); // libera a 1° dimensão
            free(v); // libera a 1°dimensão

            // Depois a gente cria ela novamente com o tamanho novo
            m = (int ***)malloc(nfiliais * sizeof(int **)); // aloca o numero de filiais
            v = (int **)malloc(nfiliais * sizeof(int *));  // aloca o numero de filiais
            for (int i = 0; i < nfiliais; i++){
                m[i] = (int **)malloc(nprodutos * sizeof(int *)); // aloca o numero de produtos
                v[i] = (int *)malloc(nprodutos * sizeof(int));  // aloca o numero de produtos
                for (int j = 0; j < nprodutos; j++){
                    m[i][j] = (int *)malloc(4 * sizeof(int)); // aloca o numero de trimestres
                    v[i][j] = 0;
                    for (int k = 0; k < 4; k++){
                        m[i][j][k] = aux[i][j][k]; // salvamos o valor da variável auxiliar
                        v[i][j] += m[i][j][k];     // salvamos o total na matriz v
                    }
                }
            }
            // agora temos que arrumar o catalogo;
            nomeaux = (char **)malloc(nprodutos * sizeof(char *));
            for (int i = 0; i < nprodutos; i++){
                nomeaux[i] = (char *)malloc(100 * sizeof(char));
            }
            int x = 0;
            for (int j = 0; j < nprodutos + 1; j++){
                if (guarda != j)
                { // salvamos tudo exceto o que estiver na posição guarda
                    strcpy(nomeaux[x], nomesprodutos[j]);
                    x++;
                }
            }
            // limpamos para salvar o correto depois
            for (int i = 0; i < nprodutos + 1; i++)
                free(nomesprodutos[i]);
            free(nomesprodutos);

            nomesprodutos = (char **)malloc(nprodutos * sizeof(char *));
            for (int j = 0; j < nprodutos; j++){
                nomesprodutos[j] = (char *)malloc(100 * sizeof(char));
                strcpy(nomesprodutos[j], nomeaux[j]);
                free(nomeaux[j]); // já aproveitamos o laço para começar a limpar o array nomeaux
            }
            free(nomeaux); // limpamos a 1° dimensão

            // agora faltar limpar a matriz auxiliar tridimensional
            for (int i = 0; i < nfiliais; i++){
                for (int j = 0; j < nprodutos; j++){
                    free(aux[i][j]); // libera a 3° dimensão
                }
                free(aux[i]); // libera a 2° dimensão
            }
            free(aux); // libera a 1° dimensão
            printf("\nProduto %s removido com sucesso\n", pescolhido);
            free(pescolhido);
        }
    }
    else printf("\nNao foi feita a inicializacao, entao nao ha produtos para serem removidos\n"); 
}

void PrintaMatriz(){
    printf("\nINFORMACOES PRINCIPAIS:\n");
    //a funcao percorre a matriz tridimensional m e imprime os valores mais importantes, como o nome das filiais, dos produtos, os
    //indices dos semestres e as vendas de cada um
    for (int i = 0; i < nfiliais; i++){
        for (int j = 0; j < nprodutos; j++){
            for (int k = 0; k < 4; k++){
                printf("(Filial %s) (Produto %s) (Trimestre %d): %d\n", nomesfiliais[i], nomesprodutos[j], k + 1, m[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void ProdutoMaisVendidoFilialEspecifica(){
    if(verifica){ //caso já ocorreu a inicializacao
        int guarda=-1;
        char *filialescolhida;
        printf("Digite a filial que voce deseja saber o produto mais vendido: ");
        getchar();
        filialescolhida=(char *)malloc(100 *sizeof(char));
        gets(filialescolhida);
        for(int i=0; i<nfiliais; i++){
            if(strcmp(filialescolhida,nomesfiliais[i])==0){
                guarda=i; //guarda a posicao daquela filial
            }
        }
        //se a variavel guarda ainda for -1, eh pq a filial lida nao esta no catalogo das filiais
        if(guarda==-1) printf("Nao foi encontrada essa filial no catalogo\n");
        else{ 
            int maior=-999999;
            for(int j=0; j<nprodutos; j++){
                //percorro todos os nprodutos da filial de posicao guarda, buscando qual foi o maior produto vendido, ja que esta tudo
                //salvo na matriz bidimensional v. eu salvo o valor de vendas em especifico, e nao qual foi o produto, pois pode haver
                //mais de um produto com a mesma quantidade de vendas.
                if(v[guarda][j]>maior){
                    maior=v[guarda][j];
                }
            }
            printf("A maior quantidade de um produto vendido na filial %s foi: %d\n", nomesfiliais[guarda], maior);
            printf("Os produtos que conseguiram essa quantidade foram: \n");
            for(int k=0; k<nprodutos; k++){
                if(v[guarda][k]==maior)printf("%s\n", nomesprodutos[k]); //imprimo os X produtos com venda maxima da filial especifica
            }
        }
    }
    else{
        printf("\nNao foi feita a inicializacao\n");
    }
}

int main(){
    int op; // opção escolhida
    printf("Bem vindo ao sistema da empresa Market++\n\n");
    while (1){
        printf("OPCOES\n1 para inicializar o sistema\n");
        printf("2 para inserir o catalogo de produtos\n");
        printf("3 para inserir o catalogo de filiais\n");
        printf("4 para inserir a venda de um produto em um trimestre especifico em cada uma das filiais\n");
        printf("5 para inserir a venda de um produto em uma filial especifica em todos os trimestres\n");
        printf("6 para mostrar o produto mais vendido em uma filial especifica\n");
        printf("7 para mostrar a filial que mais vendeu em um trimestre especifico\n");
        printf("8 para mostrar o produto mais vendido\n");
        printf("9 para mostrar a filial que mais vendeu no ano\n");
        printf("10 para mostrar o melhor trimestre (mais vendas feitas)\n");
        printf("11 para inserir novo produto\n");
        printf("12 para inserir nova filial\n");
        printf("13 para remover um produto\n");
        printf("14 para limpar tudo e fechar o sistema\n");        
        printf("15 para mostrar as informacoes principais\n");
        //opções adicionais	
        printf("16 para mostrar o pior trimestre (menos vendas feitas)\n");
	    printf("17 para mostrar o produto mais vendido de cada filial\n");
        printf("Escolha a opcao desejada:");
        scanf("%d", &op);
        if (op == 1)
            Inicializar(); //essa função faz a leitura do n° de produtos e de filiais
        else if (op == 2)
            NomeProdutos(); //essa função faz a leitura do nome de todos os produtos
        else if (op == 3)
            NomeFiliais(); //essa função faz a leitura do nome de todas as filiais
        else if (op == 4)
            ProdutoTrimestre(); //essa função faz a leitura de um trimestre especifico, de um produto, e quanto foi solicitado das vendas
            //daquele produto para todas as filiais
        else if (op == 5)
            ProdutoFilial(); //essa função faz a leitura de uma filial especifica, de um produto, e quanto foi solicitado das vendas
            //daquele produto em todos os 4 trimestres
        else if (op == 6)
            ProdutoMaisVendidoFilialEspecifica(); //chama a função que faz a leitura de uma filial específica e o sistema retorna o produto mais
            //vendido dela (soma dos 4 trimestres)
        else if (op == 7)
            FilialMaisVendeTrimestre(); //chama a função para mostrar a filial que mais vendeu em um trimestre específico
        else if (op == 8)
            ProdutoMaisVendido(); //chama a função para mostrar o produto mais vendido
        else if (op == 9)
            FilialMaisVende(); //chama a função para mostrar a filial que mais vendeu produtos no ano
        else if (op == 10)
            MelhorTrimestre(); //chama a função para mostrar o melhor trimestre, em que foram feitas mais vendas
        else if (op == 11)
            InserirProduto(); //chama função para inserir novo produto
        else if (op == 12)
            InserirFilial(); //chama a função para inserir nova filial
        else if (op == 13)
            RemoverProduto(); //chama função para remover produto
        else if (op == 14){
            FecharSistema(); //chama a função de fechamento do programa
            return 0;
        }
        else if (op == 15)
            PrintaMatriz(); //chama a função que mostra a matriz tridimensional com os valores e informações
        //opções adicionais
	    else if (op == 16)
            PiorTrimestre(); //chama a função para mostrar o pior trimestre, em que foram feitas menos vendas
	    else if (op == 17)
	        ProdutoMaisVendidoFilial(); //chama a função para printar o produto mais vendido de cada filial
	    else
            printf("Opcao inexistente, digite outro!!!\n");
        printf("\n\n\n");
    }
}
