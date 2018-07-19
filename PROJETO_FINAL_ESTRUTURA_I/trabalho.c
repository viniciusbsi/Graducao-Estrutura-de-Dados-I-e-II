#include <stdio.h>
#include <stdlib.h>
#include "trabalho.h"


	//======================= VETOR NO QUAL SÃO ARMAZENADOS OS ELEMENTOS QUE SÃO INSERIDOS NA ÁRVORE =======================
array* inicializarVetor() {
	array* novoArray;
	novoArray = (array*) malloc(sizeof(array));
	novoArray->capacidade = 10;
	novoArray->quantidade = 0;
	novoArray->elementos = (vetor*) malloc(sizeof(vetor) * 10);
	return novoArray;	
}


void inserirVetor(array* estrutura, int valor) {
	int pos = estrutura->quantidade;
	if(estrutura->quantidade < estrutura->capacidade){
		estrutura->elementos[pos].codigo = pos;
		estrutura->elementos[pos].valor = valor;
		estrutura->quantidade++;
		pos++;
	}
	else{
		realocar(estrutura, estrutura->capacidade);
	}
}

vetor* realocar(array* estrutura, int quantidade){
	estrutura->elementos = (vetor*) realloc(estrutura->elementos, sizeof(vetor) * (estrutura->capacidade * quantidade));
	estrutura->capacidade = estrutura->capacidade + quantidade;
	printf("\nRealloc - nova capacidade: %d\n", estrutura->capacidade);
    return(estrutura->elementos);
}

int buscaSequencial(array* vetor, int codigo) {
	int pos = 0;
   	while (pos < vetor->quantidade){
		if(vetor->elementos[pos].codigo == codigo){
			printf("\nElemento encontrado\n");
			return vetor->elementos[pos].valor;
		}
		pos++; 
	} 
	printf("\nElemento não encontrado\n");
   	return -1;
}

int buscaAleatorio(array* vetor) {
	int pos = 0;
	int posicao_aleatoria_remocao = rand() % 145;
	printf("posicao aleatória%d\n", posicao_aleatoria_remocao);
	while (pos < vetor->quantidade){
		if(pos == posicao_aleatoria_remocao){
			printf("\nElemento encontrado\n");
			return vetor->elementos[pos].valor;
		}
		pos++; 
	} 
	printf("\nElemento não encontrado\n");
   	return -1;
}


		//=======================   ÁRVORE   =======================

Tree* inicializarArvore() {
	Tree* pAux;
	pAux = (Tree*) malloc (sizeof(Tree));
	pAux->raiz = NULL;
	return pAux;
}



Node* inserirArvore(Node* subRaiz, int id){
	if (subRaiz == NULL) {
		Node* pNovoNo;
		pNovoNo = (Node*) malloc (sizeof(Node));
		pNovoNo->id = id;
		pNovoNo->pMaior = NULL;
		pNovoNo->pMenor = NULL;
		pNovoNo->pPai = NULL;
		return pNovoNo;
	}
	if (subRaiz->id > id) {
		subRaiz->pMenor = inserirArvore(subRaiz->pMenor, id);
		subRaiz->pMenor->pPai = subRaiz;
	} else {
		subRaiz->pMaior = inserirArvore(subRaiz->pMaior, id);
		subRaiz->pMaior->pPai = subRaiz;
	}
	return subRaiz;
}

void inOrder(Node* subRaiz){
	if (subRaiz != NULL) {
		inOrder(subRaiz->pMenor);
		printf("%d ", subRaiz->id);
		inOrder(subRaiz->pMaior);
	}
}

void posOrder(Node* subRaiz){
	if (subRaiz != NULL) {
		posOrder(subRaiz->pMenor);
		posOrder(subRaiz->pMaior);
		printf("%d ", subRaiz->id);
	}
}

void preOrder(Node* subRaiz){
	if (subRaiz != NULL) {
		printf("%d ", subRaiz->id);
		preOrder(subRaiz->pMenor);
		preOrder(subRaiz->pMaior);
	}
}

Node* removerSubRaiz(Node* subRaiz) {  
    //~ printf("remover subraiz\n\n");
    Node *pAux1, *pNovaSubRaiz;
    if (subRaiz->pMenor == NULL) {
       pNovaSubRaiz = subRaiz->pMaior;
    } else {
    	pAux1 = subRaiz; 
    	pNovaSubRaiz = subRaiz->pMenor;
    	while (pNovaSubRaiz->pMaior != NULL) {
       		pAux1 = pNovaSubRaiz; 
       		pNovaSubRaiz = pNovaSubRaiz->pMaior;
    	}
    	if (pAux1 != subRaiz) {
       		pAux1->pMaior = pNovaSubRaiz->pMenor;
       		pNovaSubRaiz->pMenor = subRaiz->pMenor;
    	}
    	pNovaSubRaiz->pMaior = subRaiz->pMaior;
	}
    free (subRaiz);
    return pNovaSubRaiz;
}

Node* buscarPai(Node* subRaiz, int id) {
    //~ printf("busca pai\n\n");
    if (subRaiz == NULL || subRaiz->id == id){
		//~ printf("encontrou pai\n\n\n");
		return subRaiz->pPai;
	}
    if (subRaiz->id > id)
		return buscarPai (subRaiz->pMenor, id);
    else
		return buscarPai (subRaiz->pMaior, id);
}

int buscaElemento(Node* subRaiz, int id){
    printf("\n%d\n", subRaiz->id);
    if (subRaiz == NULL || subRaiz->id == id)
       return subRaiz->id;
    if (subRaiz->id > id)
       return buscaElemento(subRaiz->pMenor, id);
    else
       return buscaElemento(subRaiz->pMaior, id);
}


Node* remover(Node* subRaiz, int id) {
	//~ printf("remover\n\n");
	Node* pai = buscarPai(subRaiz, id);
	if (pai == NULL) {
		subRaiz = removerSubRaiz(subRaiz);
	}
	else if ((pai->pMenor) && (pai->pMenor->id == id))
		pai->pMenor = removerSubRaiz (pai->pMenor);
	else 
		pai->pMaior = removerSubRaiz (pai->pMaior);
	return subRaiz;
}


	//=======================   PILHA   =======================
	
Pilha* inicializarPilha(){
    Pilha* minhaPilha;
    minhaPilha = (Pilha*) malloc(sizeof(minhaPilha));
    minhaPilha->p_inicio = NULL;
    return minhaPilha;
}

void empilhar(Pilha* pilha, int cod){
    Elemento* novoElemento = criarElemento(cod);
    novoElemento->p_prox = pilha->p_inicio;
    pilha->p_inicio = novoElemento;
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}

void desimpilhar(Pilha *pilha){
    if (pilha->p_inicio == NULL)
        printf("\nPilha vazia...\n");
    else{
		Elemento *p_aux;
		p_aux = pilha->p_inicio;
		pilha->p_inicio = p_aux->p_prox;
	}
}

void apresentarElementosPilha(Pilha* pilha){
	if(apresentarTopo(pilha) == 1){
		desimpilhar(pilha);
		apresentarElementosPilha(pilha);
	}
}

int apresentarTopo(Pilha* pilha){
	if (pilha->p_inicio == NULL){
        printf("\nPilha vazia...\n");
        return 0;
	}
    else{
        printf("\nElemento: %d\n", pilha->p_inicio->codigo);
        return(1); 
    }
    printf("=========##=========\n");
}

Elemento* criarElemento(int cod){
    Elemento* novoElemento;
    novoElemento = (Elemento*) malloc (sizeof(Elemento));
    novoElemento->codigo = cod;
    novoElemento->p_prox = NULL;
    return novoElemento;
    //novoElemento->p_prox = NULL;
    //não pode apontar para nulo pq se não vai perder o primeiro elemento quando for inserido o segundo
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;    
}

	//=======================   LISTA ENCADEADA   =======================
	
Lista* inicializar() {
    Lista* minhaLista;
    minhaLista = (Lista*) malloc(sizeof(Lista));
    minhaLista->p_inicio = NULL;
    minhaLista->tamanho_lista = 0;
    return minhaLista;
}

void inserirInicio(Lista* lista, int cod){
    Elemento* novoElemento = criarElemento(cod);
    novoElemento->p_prox = lista->p_inicio;
    lista->p_inicio = novoElemento;
    lista->tamanho_lista = lista->tamanho_lista +1;
    if (lista->p_inicio == NULL)
        printf("Lista encadeada vazia...\n");
    else{
		Elemento *p_aux_2;
        p_aux_2 = lista->p_inicio;
        while(p_aux_2 != NULL){
            printf("\nCODIGO : %d\n", p_aux_2->codigo);
            p_aux_2 = p_aux_2->p_prox;
        }
    }
    //o inicio aponta para o elemento inicial, ele deve apontar para uma struct do tipo Elemento*;
}

int procurar(Lista* lista){
	if(lista->tamanho_lista > 0){
		Elemento *p_aux;
		p_aux = lista->p_inicio;
		int elemento_aleatorio, posicao_aleatorio, i;
		i = -1;
		if(lista->tamanho_lista > 1){
			posicao_aleatorio = rand() % (lista->tamanho_lista-1);
			while(i < posicao_aleatorio){
				elemento_aleatorio = p_aux->codigo;
				p_aux = p_aux->p_prox;
				i++;
			}
		}
		else{
			elemento_aleatorio = lista->p_inicio->codigo; 
		}
		
		printf("Elemento %d da lista de removidos será reinserido na árvore\n\n", elemento_aleatorio);
		return elemento_aleatorio;
	}
	return -1; 
	
}

void removerLista(Lista *lista, int cod){
    Elemento *p_aux;
    p_aux = lista->p_inicio;
    if(p_aux->p_prox == NULL){
		lista->p_inicio = NULL;
		lista->tamanho_lista = 0;
		return;
	}
    while(p_aux->p_prox != NULL){
		if(p_aux->codigo == cod){
			lista->p_inicio = p_aux->p_prox;
			lista->tamanho_lista = lista->tamanho_lista-1;
            return;
		} 
        else if(p_aux->p_prox->codigo == cod){
            Elemento *p_remover = p_aux->p_prox;
            p_aux->p_prox = p_remover->p_prox;
            free(p_remover);
            lista->tamanho_lista = lista->tamanho_lista-1;
            return;
        }
        p_aux = p_aux->p_prox;
    }
}
