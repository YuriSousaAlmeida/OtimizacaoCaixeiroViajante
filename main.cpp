#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"

using namespace std;

int main()
{
    char arquivo[50];
    strcpy(arquivo, "toy.txt");

    ler_instancia(arquivo);

    imprimirDadosIniciais(&num_cidade);
    //printf("%d\n", num_cidade);

    for(int i=0;i<num_cidade;i++){
        for(int j=0;j<num_cidade;j++){
            printf("%.2f ", mat_custo[i][j]);
        }printf("\n");
    }

    return 0;
}

void ler_instancia(char *arq){
    FILE *f;
    f=fopen(arq,"r");

    fscanf(f, "%d", &num_cidade);
    for(int i=0;i<num_cidade;i++){
        for(int j=0;j<num_cidade;j++){
            fscanf(f, "%f", &mat_custo[i][j]);
        }
    }

    fclose(f);
}

void imprimirDadosIniciais(int *inteiro){
    printf("%d\n", num_cidade);
}
