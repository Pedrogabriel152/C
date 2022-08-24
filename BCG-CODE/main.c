#include <stdio.h>
#include <stdlib.h>

int main(){

    //funcao verifaca inicio do programa

    //funcao impprimir na tela
    void imprimir(char programa[1000]);

    //ponteiro apontando para o arquivo
    FILE *file;
    file = fopen("bcg.txt", "r");

    char programa[1000];

    //Caso o caminho do arquivo nao exista o programa ira apresentar erro
    if(file == NULL){
        printf("ERRO! Arquivo nao foi encontrado para compilaçao.\n");
        return 1;
    }

    //testa a quantidade de caracter do arquivo
    while(fgets(programa, 1000, file) != NULL){
        printf("%s", programa);
    };

    //verifica o inicio do programa



    //Aplicacao da funcao de imprimir na tela
    imprimir(programa);
    fclose(file);

    printf("\n");
    system("pause");
return 0;
}

void imprimir(char programa[1000]){
    int i, j=0,z=0,n;
    char aux[5] = {"view'"}, imp[1000], aux2[1] = {"'"};

    for(i=0;i<1000;i++){
        if(programa[i] == aux[j]){
            j++;
        }else{
            j = 0;
        }

        if(programa[i] == aux2[0]){
            imp[z] = programa[i];
            z++;
        }
    }

        printf("%s",imp);
}

void alocarNaMemoria(char programa[1000]){
    int i, j=0,z=0,n;
    char aux[5] = {"read'"}, imp[1000], aux2[1] = {"'"};

    for(i=0;i<1000;i++){
        if(programa[i] == aux[j]){
            j++;
        }else{
            j = 0;
        }

        if(programa[i] == aux2[0]){
            scanf("%s",imp[z]);
            z++;
        }
    }
}
