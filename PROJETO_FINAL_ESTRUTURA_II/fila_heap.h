#include <stdio.h>
#include <stdlib.h>
typedef struct elemento{
    int valor;
    int ordem;
}Elemento;

typedef struct{
    Elemento*vetor;
    int quantidade;
    int capacidade;
}Fila;

Fila* inicializarFila();
void enfileirar(Fila*, int, int);
int desenfileirar(Fila*);
Elemento criarElementoFila(int, int);
void criaheap(Fila*, int, int);
void heap(Fila*);
