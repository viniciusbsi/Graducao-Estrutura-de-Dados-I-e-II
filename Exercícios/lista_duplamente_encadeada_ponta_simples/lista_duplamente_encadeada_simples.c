#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada_simples.h"

Lista* inicializar() {
    Lista* minhaLista;
    minhaLista = (Lista*) malloc(sizeof(Lista));
    minhaLista->p_inicio = NULL;
    for(int i = 30;  i > 0; i--){
        inserirInicio(minhaLista, i, i*10.0);
    }
    //~ for(int i = 25; i > 0; i=i-5){
        //~ inserirMeio(minhaLista, i, 1000.00);
    //~ }
    //~ for(int i = 5; i > 0; i--){
        //~ inserirFinal(minhaLista, i, 2000.00);
    //~ }	
    inserirFinal(minhaLista, 33, 3333333);
}

void inserirInicio(Lista* lista, int cod, float val){
    Elemento* novoElemento = criarElemento(cod, val);
    novoElemento->p_prox = lista->p_inicio;
    lista->p_inicio = novoElemento;
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}

void percorrer(Lista* lista){
    if (lista->p_inicio == NULL)
        printf("Lista vazia...\n");
    else{
        Elemento *p_aux;
        p_aux = lista->p_inicio;
        while(p_aux != NULL){
            printf("CODIGO : %d \t VALOR: %.2f \t POSICAO: %p \t PRÓXIMO: %p\n", p_aux->codigo, p_aux->valor, p_aux, p_aux->p_prox);
            p_aux = p_aux->p_prox;
        }
    }
    printf("=========##=========\n");
}

void procurar(Lista* lista, int cod, int opcao){
    if(opcao == 1){
        Elemento *p_aux;
        p_aux = lista->p_inicio;
        while(p_aux != NULL){
            if(p_aux->codigo == cod){
                printf("VALOR DA POSIÇÃO %d: %.2f \t POSICAO DE MEMORIA: %p \t \n", p_aux->codigo, p_aux->valor, p_aux);
            }
            p_aux = p_aux->p_prox;
        }
        printf("=========##=========\n");    
    }
    if(opcao == 2){
        Elemento *p_aux;
        p_aux = lista->p_inicio;
        while(p_aux != NULL){
            if(p_aux->valor == cod){
                printf("VALOR DA POSIÇÃO %d: %.2f \t POSICAO DE MEMORIA: %p \t \n", p_aux->codigo, p_aux->valor, p_aux);
            }
            p_aux = p_aux->p_prox;
        }
        printf("=========##=========\n");    
    }
}

void inserirFinal(Lista* lista, int cod, float val){
    if(lista->p_inicio == NULL){
        inserirInicio(lista, cod, val);
    }
    else{
        Elemento* novoElemento = criarElemento(cod, val);
        Elemento *p_aux = lista->p_inicio;
        while(p_aux->p_prox != NULL){
            p_aux = p_aux->p_prox;
        }
        novoElemento->p_prox = NULL;
        p_aux->p_prox = novoElemento;
        printf("CODIGO : %d \t VALOR: %.2f \t POSICAO: %p \t PRÓXIMO: %p \n", p_aux->codigo, p_aux->valor, p_aux, p_aux->p_prox);
        printf("CODIGO : %d \t VALOR: %.2f \t POSICAO: %p \t PRÓXIMO: %p \n", novoElemento->codigo, novoElemento->valor, novoElemento, novoElemento->p_prox);
    }
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}


void remover(Lista *lista, int cod){
    Elemento *p_aux;
    p_aux = lista->p_inicio;
    while(p_aux->p_prox != NULL){
        if(p_aux->p_prox->codigo == cod){
            Elemento *p_remover = p_aux->p_prox;
            p_aux->p_prox = p_remover->p_prox;
            free(p_remover);
            printf("Removido...\n");
            return;
        }
        p_aux = p_aux->p_prox;
    }
}

void inserirMeio(Lista* lista, int cod, float val){
    if(lista->p_inicio == NULL){
        inserirInicio(lista, cod, val);
    }
    else{
        Elemento* novoElemento = criarElemento(cod, val);
        Elemento *p_aux;
        p_aux = lista->p_inicio;
        while(p_aux->p_prox != NULL){ //enquanto não for o último elemento
           if(p_aux->codigo == cod){
                novoElemento->p_prox = p_aux->p_prox;
                p_aux->p_prox = novoElemento;
                return;
            }
            p_aux = p_aux->p_prox;
        }
    }
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}

void alterarElemento(Lista* lista, int cod, float novoValor){
    Elemento *p_aux;
    p_aux = lista->p_inicio;
    while(p_aux != NULL){
        if(p_aux->codigo == cod){
            p_aux->valor = novoValor;
            printf("VALOR DA POSIÇÃO %d: %.2f \t POSICAO DE MEMORIA: %p \n", cod, p_aux->valor, p_aux);
        }
        p_aux = p_aux->p_prox;
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
