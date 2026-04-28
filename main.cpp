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
    Solucao sol;
    sol.fo=0;

    ler_instancia(arquivo);

    sol.cidadesVisitadas[0]=0;
    sol.cidadesVisitadas[1]=3;
    sol.cidadesVisitadas[2]=4;
    sol.cidadesVisitadas[3]=3;
    sol.cidadesVisitadas[4]=1;

    sol.qtdVisitas[0]=1;
    sol.qtdVisitas[1]=1;
    sol.qtdVisitas[2]=0; //multa por não visitar
    sol.qtdVisitas[3]=2; //multa por excesso de visita
    sol.qtdVisitas[4]=1;

    imprimirDadosIniciais(num_cidade,mat_custo);
    calcularFo(sol);
    imprimirNaTela(sol);
    imprimirNoArquivo(sol, "SaidaTela.txt");




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

//Para teste dos dados de entrada
void imprimirDadosIniciais(int inteiro, float matriz[MAX_CIDADE][MAX_CIDADE]) {
    printf("%d\n", num_cidade);
    for(int i=0;i<num_cidade;i++){
        for(int j=0;j<num_cidade;j++){
            printf("%.2f ", mat_custo[i][j]);
        }printf("\n");
    }
    printf("\n");
}

void imprimirNaTela(Solucao &sol){
    printf("FO: %.2f\n", sol.fo);
    printf("Cidades percorridas: Iniciando na cidade ");
    for(int i=0; i<num_cidade;i++){
        printf("[->]:%d   ", sol.cidadesVisitadas[i]);
    }printf("[->]:%d\n", sol.cidadesVisitadas[0]);
    printf("Quantidade p/ cidade: ");
    for(int i=0; i<num_cidade;i++){
        printf("[%d]:%d   ",i , sol.qtdVisitas[i]);
    }printf("\n");
}

void imprimirNoArquivo(Solucao &sol, char *nomeArq){
    FILE *f;
    f=fopen(nomeArq, "w");
    fprintf(f,"FO: %.2f\n", sol.fo);
    fprintf(f,"Cidades percorridas: Iniciando na cidade ");
    for(int i=0; i<num_cidade;i++){
        fprintf(f,"[->]:%d   ", sol.cidadesVisitadas[i]);
    }fprintf(f,"[->]:%d\n", sol.cidadesVisitadas[0]);
    fprintf(f,"Quantidade p/ cidade: ");
    for(int i=0; i<num_cidade;i++){
        fprintf(f,"[%d]:%d   ",i , sol.qtdVisitas[i]);
    }fprintf(f,"\n");
    fclose(f);
}

//automatizar o processo da contagem de cidades visitadas
void calcularFo(Solucao &sol){
    for(int i=0;i<num_cidade-1;i++){
            sol.fo+=mat_custo[sol.cidadesVisitadas[i]][sol.cidadesVisitadas[i+1]];
    }sol.fo+=mat_custo[sol.cidadesVisitadas[num_cidade-1]][sol.cidadesVisitadas[0]];
    for(int j=0;j<num_cidade;j++){
        if(sol.qtdVisitas[j]==0) sol.fo+=alfa;
        else if(sol.qtdVisitas[j]>1) sol.fo+=(alfa*(sol.qtdVisitas[j]-1));
    }
}
