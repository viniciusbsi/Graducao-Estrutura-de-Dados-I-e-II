#include <stdio.h>
#include <stdlib.h>


typedef struct elemento{
    int codigo;
    float valor;
    struct elemento *p_prox;
    //é criado essa var elemento para que no inicio essa struct aponte para ela mesma
}Elemento;

typedef struct{
    Elemento *p_inicio;
}Lista;

void remover(Lista*, int);
void percorrer(Lista*);
void inserirInicio(Lista*, int, float);
void inserirFinal(Lista*, int, float);
Elemento* criarElemento(int, float);
void procurar(Lista*, int); //mostrar valor do códifo correspondente;

int main(){
    Lista* minhaLista;
    minhaLista = (Lista*) malloc(sizeof(Lista));
    minhaLista->p_inicio = NULL;
    for(int i = 30; i > 0; i--){
        inserirInicio(minhaLista, i, i*10.0);
    }
    remover(minhaLista, 214);
    percorrer(minhaLista);
    procurar(minhaLista, 7);
    inserirFinal(minhaLista, 100, 200.0);
    remover(minhaLista, 5);
    percorrer(minhaLista);
}

void percorrer(Lista* lista){
    if (lista->p_inicio == NULL)
        printf("Lista vazia...\n");
    else{
        Elemento *p_aux;
        p_aux = lista->p_inicio;
        while(p_aux != NULL){
            printf("CODIGO : %d \t VALOR: %.2f \t POSICAO: %p \n", p_aux->codigo, p_aux->valor, p_aux);
            p_aux = p_aux->p_prox;
        }
    }
}

void procurar(Lista* lista, int cod){
    Elemento *p_aux;
    p_aux = lista->p_inicio;
    while(p_aux != NULL){
        if(p_aux->codigo == cod){
            printf("VALOR DA POSIÇÃO 7: %.2f \t POSICAO DE MEMORIA: %p \n", p_aux->valor, p_aux);
        }
        p_aux = p_aux->p_prox;
    }
}

void inserirInicio(Lista* lista, int cod, float val){
    Elemento* novoElemento = criarElemento(cod, val);
    novoElemento->p_prox = lista->p_inicio;
    lista->p_inicio = novoElemento;
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
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
        p_aux->p_prox = novoElemento;
    }
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
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
