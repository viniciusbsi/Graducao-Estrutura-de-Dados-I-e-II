#include <stdio.h>
#include <stdlib.h>
#include "fila_sem_prioridade.h"

Fila* inicializar(){
    Fila* minhaFila;
    minhaFila = (Fila*) malloc(sizeof(minhaFila));
    minhaFila->p_inicio = NULL;
    //~ for(int i = 30;  i > 0; i--){
        //~ inserirInicio(minhaLista, i, i*10.0);
    //~ }
    //~ for(int i = 25; i > 0; i=i-5){
        //~ inserirMeio(minhaLista, i, 1000.00);
    //~ }
    //~ for(int i = 5; i > 0; i--){
        //~ inserirFinal(minhaLista, i, 2000.00);
    //~ }	
    //~ inserirFinal(minhaLista, 33, 3333333);
    return minhaFila;
}

void enfileirar(Fila* fila, float val){
    Elemento* novoElemento = criarElemento(val);
    if(fila->p_inicio == NULL){
        fila->p_inicio = novoElemento;
        novoElemento->p_prox = NULL;
    }
    else{
        Elemento *p_aux = fila->p_inicio;
        while(p_aux->p_prox != NULL){
            p_aux = p_aux->p_prox;
        }
        novoElemento->p_prox = NULL;
        p_aux->p_prox = novoElemento;
    }
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}

void desenfileirar(Fila *fila){
    if(fila->p_inicio->p_prox == NULL){
        printf("Há somente um elemento na fila\n");
    }
    else{
        fila->p_inicio = fila->p_inicio->p_prox;
    }
}

void mostrarProximo(Fila* fila){
    if (fila->p_inicio == NULL)
        printf("Fila vazia...\n");
    if (fila->p_inicio->p_prox == NULL){
        printf("Há somente um elemento na fila\n");
        printf("VALOR: %.2f \t \n", fila->p_inicio->valor);
    }
    else{
        printf("VALOR: %.2f \t PRÓXIMO: %.2f\n", fila->p_inicio->valor, fila->p_inicio->p_prox->valor);
    }
    printf("=========##=========\n");
}

Elemento* criarElemento(float val){
    Elemento* novoElemento;
    novoElemento = (Elemento*) malloc (sizeof(Elemento));
    novoElemento->valor = val;
    novoElemento->p_prox = NULL;
    return novoElemento;
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;    
}

// Inicio das funcoes
// Fim das funcoes
