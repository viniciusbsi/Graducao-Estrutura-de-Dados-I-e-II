#include<stdio.h>
#include<stdlib.h>
#include "arraySequencial.h"

//Isso é uma boa prática, prototipar
int menu();

//Aqui inicia o programa, até então era inicializadas as estruturas;
int main(){
    //Um ponteiro 'coordenadas' para um array 
    arraySeq* coordenadas;
    
    do {
        int x, y;
        switch(menu()){
            case 0:
                return 1;
            case 1:
                coordenadas = inicializar();
                printf("Inicializar...\n");
                break;
            case 2:
                printf("Capaciade total é de %d.\n", getCapacidade(coordenadas) );
                break;
            case 3:
                printf("Quantidade de elementos %d.\n ", getQuantidade(coordenadas) );
                break;
            case 4:
                printf("Informe coordenadas: " );
                scanf("%d", &x);
                scanf("%d", &y);
                //coordenadas é um ponteiro para arraySeq
                //essa função é definida no .h
                adicionaCoordenada(coordenadas, x, y);
                break;
                
            case 5:
                x = getUltimoX(coordenadas);
                y = getUltimoY(coordenadas);
                printf("Ultimo x: %d; ultimo y: %d \n", x, y);
                break;
                
            default:
                break;
        }
    }while (1 == 1);   
}

int menu() {
    int op;
    printf("1 - Inicializar\n ");
    printf("2 - Capacidade\n");
    printf("3 - Quantidade\n ");
    printf("4 - Adicionar Coordenada\n ");
    printf("5 - Última coordenada\n ");
    printf("0 - Sair\n ");
    printf("Opção: ");
    scanf("%d", &op);
    return(op);
}

/*
 * PARA EXECUTAR O PROGRAMA: gcc arraySequencial.c main.c -o menuCompilado
 * Não pode incluir o .c nesse programa, deve ser compilado os dois ao mesmo tempo, até pode, MAS NÃO SE FAZ
 * */


/*
 * Explicação
 * foi criado dois typedef, ponto e arraySeq
 * 
 * arraySeq tem três elementos, capacidade (aponta para um inteiro), quantiade(aponta para um inteiro) e um ponteiro para pontos (que aponta para um vetor);
 *  
 * depois é criado uma variável 'coordenadas' no case 1 do switch, a capacidade é o tamanho do vetor de pontos;
 * 
 * Ex: coordenadas (7,0, null) - [...] 
 * Ex: coordenadas (7,1, ponto (endereço de memória para a primeira posição do vetor de pontos)) - [(0,0)] 
 * Ex: coordenadas (7,2, ponto) - [(0,0), (0,1)] 
 * Ex: coordenadas (7,3, ponto) - [(0,0), (0,1), (0,2)] 
 * Ex: coordenadas (7,4, ponto) - [(0,0), (0,1), (0,2), (0,3)] 
 * .
 * .
 * .
 * cresce até coordenadas (7,7, ponto), onde devará ser feito um realloc
 * Coordenada nada mais é que uma variável única que gerencia todas as coordenadas;
 * 
 * */
