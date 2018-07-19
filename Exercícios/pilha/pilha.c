#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* inicializar(){
    Pilha* minhaPilha;
    minhaPilha = (Pilha*) malloc(sizeof(minhaPilha));
    minhaPilha->p_inicio = NULL;
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
    return minhaPilha;
}

void empilhar(Pilha* pilha, int cod, float val){
    Elemento* novoElemento = criarElemento(cod, val);
    novoElemento->p_prox = pilha->p_inicio;
    pilha->p_inicio = novoElemento;
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}

void desimpilhar(Pilha *pilha){
    Elemento *p_aux;
    p_aux = pilha->p_inicio;
    pilha->p_inicio = p_aux->p_prox;
}

void apresentarTopo(Pilha* pilha){
    if (pilha->p_inicio == NULL)
        printf("Lista vazia...\n");
    else{
        printf("CODIGO : %d \t VALOR: %.2f \t POSICAO: %p \t PRÓXIMO: %p\n", pilha->p_inicio->codigo, pilha->p_inicio->valor, pilha->p_inicio, pilha->p_inicio->p_prox);
    }
    printf("=========##=========\n");
}

Elemento* criarElemento(int cod, float val){
    Elemento* novoElemento;
    novoElemento = (Elemento*) malloc (sizeof(Elemento));
    novoElemento->codigo = cod;
    novoElemento->valor = val;
    novoElemento->p_prox = NULL;
    return novoElemento;
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;    
}

// Inicio das funcoes
// Fim das funcoes
