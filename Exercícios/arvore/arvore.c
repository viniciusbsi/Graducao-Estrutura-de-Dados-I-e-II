#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//~ int main() {
	//~ Tree* minhaArvore;
	//~ minhaArvore = inicializar();
	//~ printf("Inserir 50...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 50);
	//~ printf("Inserir 25...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 25);
	//~ printf("Inserir 75...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 75);
	//~ printf("Inserir 40...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 40);
	//~ printf("Inserir 15...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 15);
	//~ printf("Inserir 55...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 55);
	//~ printf("Inserir 60...\n");
	//~ minhaArvore->raiz = inserir(minhaArvore->raiz, 60);
	//~ inOrder(minhaArvore->raiz);
	//~ printf("\n");
//~ }

Tree* inicializar() {
	Tree* pAux;
	pAux = (Tree*) malloc (sizeof(Tree));
	pAux->raiz = NULL;
	return pAux;
}

Node* inserir(Node* subRaiz, int id){
	if (subRaiz == NULL) {
		Node* pNovoNo;
		pNovoNo = (Node*) malloc (sizeof(Node));
		pNovoNo->id = id;
		pNovoNo->pMaior = NULL;
		pNovoNo->pMenor = NULL;
		return pNovoNo;
	}
	if (subRaiz->id > id)
		subRaiz->pMenor = inserir(subRaiz->pMenor, id);
	else
		subRaiz->pMaior = inserir(subRaiz->pMaior, id);
	return subRaiz;
}

void inOrder(Node* subRaiz){
	if (subRaiz != NULL) {
		inOrder(subRaiz->pMenor);
		printf("%d ", subRaiz->id);
		inOrder(subRaiz->pMaior);
	}
}

//~ Tree* removerRaiz(Node* subRaiz, int id, Tree** minhaArvore){
	//~ printf("removendo a raiz\n\n\n");
	//~ Node* toRemove;
	//~ Node* elemento;
	//~ Node* paiElemento;
	//~ if(subRaiz->pMenor){
		//~ toRemove = subRaiz->pMenor;
	//~ }
	//~ paiElemento = maiorDoMenor(toRemove);
	//~ if(paiElemento->pMaior != NULL){
		//~ elemento = paiElemento->pMaior;
		//~ paiElemento->pMaior = NULL;
	//~ } 
	//~ else{
		//~ elemento = paiElemento;
	//~ }
	//~ if(elemento != toRemove->pMenor)
		//~ elemento->pMenor = toRemove->pMenor;
	//~ elemento->pMaior = toRemove->pMaior;
	//~ minhaArvore->raiz = elemento;
	//~ return minhaArvore;
//~ }


Node* remover(Node* subRaiz, int id){
	
	//Removendo...
	if ((subRaiz->pMaior && subRaiz->pMaior->id == id) || (subRaiz->pMenor && subRaiz->pMenor->id == id)){
		Node* toRemove;
		Node* elemento;
		Node* paiElemento;
		if(subRaiz->pMaior && subRaiz->pMaior->id == id)
            toRemove = subRaiz->pMaior;
		if(subRaiz->pMenor && subRaiz->pMenor->id == id)
            toRemove = subRaiz->pMenor;
		if(toRemove->pMenor && toRemove->pMaior){
			printf("2.1\n\n\n\n\n");
			paiElemento = maiorDoMenor(toRemove->pMenor);
			elemento = paiElemento->pMaior;
            if(elemento->pMenor)
                paiElemento->pMaior = elemento->pMenor;
            else
                paiElemento->pMaior = NULL;
			if(elemento != toRemove->pMenor)
				elemento->pMenor = toRemove->pMenor;
				elemento->pMaior = toRemove->pMaior;
			subRaiz->pMaior = elemento;
			return elemento;
		}
		if(toRemove->pMaior){
			printf("2.2\n");
			paiElemento = menorDoMaior(toRemove->pMaior);
            printf("%d\n\n\n", paiElemento->id);
            elemento = paiElemento->pMenor;
            if(elemento->pMaior)
                paiElemento->pMenor = elemento->pMaior;
			else
                paiElemento->pMenor = NULL;
            if(elemento != toRemove->pMaior)
				elemento->pMaior = toRemove->pMaior;
			subRaiz->pMenor = elemento;
			return elemento;
		}
		if(toRemove->pMenor){
			printf("2.3\n");
			paiElemento = maiorDoMenor(toRemove->pMenor);
            elemento = paiElemento->pMaior;
            if(elemento->pMenor)
                paiElemento->pMaior = elemento->pMenor;
			else
                paiElemento->pMaior = NULL;
			if(elemento != toRemove->pMenor)
				elemento->pMenor = toRemove->pMenor;
			subRaiz->pMaior = elemento;
			return elemento;
		}
		if(toRemove->pMenor == NULL && toRemove->pMaior == NULL){
			printf("2.4\n");
			if(subRaiz->pMaior && subRaiz->pMaior->id == id)
				subRaiz->pMaior = NULL;
			if(subRaiz->pMenor && subRaiz->pMenor->id == id)
				subRaiz->pMenor = NULL;
			return elemento;
		}
	}
	
	//~ ======= PROCURANDO OS ELEMENTOS =========
	if (subRaiz->id > id)
		remover(subRaiz->pMenor, id);
	if (subRaiz->id < id)
		remover(subRaiz->pMaior, id);
	return subRaiz;	
}

Node* maiorDoMenor(Node* subRaiz){
	if(subRaiz->pMaior == NULL){
		return subRaiz;
	}
	if (subRaiz->pMaior->pMaior == NULL){
		return subRaiz;
	}
	else{
		maiorDoMenor(subRaiz->pMaior);
	}
}

Node* menorDoMaior(Node* subRaiz){
	if(subRaiz->pMenor == NULL){
		return subRaiz;
	}
	if (subRaiz->pMenor->pMenor == NULL){
		return subRaiz;
	}
	else{
		maiorDoMenor(subRaiz->pMenor);
	}
}

Node* reordena(Node* elemento, Node* subRaiz, int id){
	if (subRaiz->pMaior->id == id){
		elemento->pMenor = subRaiz->pMaior->pMenor;
		subRaiz->pMaior = elemento;
		return subRaiz;
	}
	if (subRaiz->pMenor->id == id){
		return subRaiz;
	}
	else{
		reordena(elemento, subRaiz, id);
	}
}
