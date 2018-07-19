#include <stdio.h>
#include <stdlib.h>
#include "fila_com_prioridade.h"

Fila* inicializar(){
    Fila* minhaFila;
    minhaFila = (Fila*) malloc(sizeof(minhaFila));
    minhaFila->p_inicio = NULL;
    minhaFila->p_fim_fila = NULL;
    minhaFila->p_fim_prioridade = NULL;
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

void enfileirar(Fila* fila, int cod, float val){
    Elemento* novoElemento = criarElemento(cod, val);
    if(fila->p_inicio == NULL){
        fila->p_inicio = novoElemento;
        fila->p_fim_fila = novoElemento;
        if(cod == 1){
			fila->p_fim_prioridade = novoElemento;
			//~ fila->p_fim_fila = novoElemento;
		}
    }
    else{
        if(cod == 2){
			printf("no if");
			Elemento *p_aux = fila->p_inicio;
			while(p_aux->p_prox != NULL){
				p_aux = p_aux->p_prox;
			}
			novoElemento->p_prox = NULL;
			p_aux->p_prox = novoElemento;
		}
        if(cod == 1){
			novoElemento->p_prox = fila->p_fim_prioridade->p_prox;
			fila->p_fim_prioridade->p_prox = novoElemento;
			fila->p_fim_prioridade = novoElemento;
        }
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

void percorrer(Fila* fila){
	printf("=========##=========\n");
    if (fila->p_inicio == NULL)
        printf("Lista vazia...\n");
    else{
        Elemento *p_aux;
        p_aux = fila->p_inicio;
        while(p_aux != NULL){
            printf("CODIGO : %d \t VALOR: %.2f \t	PRÓximo: %p \n", p_aux->codigo, p_aux->valor, p_aux->p_prox);
            p_aux = p_aux->p_prox;
        }
    }
    printf("=========##=========\n");
}

Elemento* criarElemento(int cod, float val){
    Elemento* novoElemento;
    novoElemento = (Elemento*) malloc (sizeof(Elemento));
    novoElemento->valor = val;
    novoElemento->codigo = cod;
    novoElemento->p_prox = NULL;
    return novoElemento;
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;    
}

// Inicio das funcoes
// Fim das funcoes
