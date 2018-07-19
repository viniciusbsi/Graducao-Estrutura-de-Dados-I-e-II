#include <stdio.h>
#include <stdlib.h>
#include "trabalho.h"

int menu();

int main() {
	Tree* minhaArvore;
	array* estrutura;
	Pilha* minhaPilha;
	int elementoPilha;
	Lista* minhalista;
	
	int valor, valor_aleatorio, valor_aleatorio_busca, valor_lista, elemento_arvore, valor_aleatorio_remocao, valor_aleatorio_lista;
        do {
		switch ( menu() ){
			case 0:
				return 1;
				break;
			case 1:
				estrutura = inicializarVetor();
				minhaPilha = inicializarPilha();
				minhalista = inicializar();
				minhaArvore = inicializarArvore();
				printf("Vetor inicializado com 10 posições...\n");
				break;
                
            case 2:
				for(int i = 1; i <= 150; i++){
					valor_aleatorio = rand() % 1000;
					//~ printf("valor rand %d\n", valor_aleatorio);
					inserirVetor(estrutura, valor_aleatorio);
					minhaArvore->raiz = inserirArvore(minhaArvore->raiz, valor_aleatorio);
				}
				//~ inOrder(minhaArvore->raiz);
				break;
			
			case 3:
				valor_aleatorio_busca = rand() % 150;
				valor_lista = buscaSequencial(estrutura, valor_aleatorio_busca);
				printf("valor correspondente ao índice %d é %d", valor_aleatorio_busca, valor_lista);
				if (valor_lista != -1){
					elemento_arvore = buscaElemento(minhaArvore->raiz, valor_lista);
					empilhar(minhaPilha, valor_lista);
				}
				break;
			
			case 4:
				elementoPilha = apresentarTopo(minhaPilha);
				break;
			
			case 5:
				apresentarElementosPilha(minhaPilha);
				break;
				
			case 6:
				;
				valor_lista = buscaAleatorio(estrutura);
				if (valor_lista != -1){
					printf("Elemento a ser removido da árvore e inserido da lista encadeada: %d\n\n\n", valor_lista);
					remover(minhaArvore->raiz, valor_lista);
					inOrder(minhaArvore->raiz);
					inserirInicio(minhalista, valor_lista);
				}
				else{
					printf("Elemento gerado não está presente na árvore\n");
				}
				break;
			
			case 7:
				valor_aleatorio_lista = procurar(minhalista);
				if(valor_aleatorio_lista != -1){
					minhaArvore->raiz = inserirArvore(minhaArvore->raiz, valor_aleatorio_lista);
					inOrder(minhaArvore->raiz);
					removerLista(minhalista, valor_aleatorio_lista);
				}
				else
					printf("Lista vazia\n"); 
				break;
            
            case 8:
                preOrder(minhaArvore->raiz);
				break;

			case 9:
                inOrder(minhaArvore->raiz);
				break;
				
			case 10:
                posOrder(minhaArvore->raiz);
				break;
			
			default:
				break;
		}
	}while (1 == 1);
}

int menu() {
	int op;
	printf("\n\nÁRVORE\n");
	printf("1 - Inicializar vetor\n");
	printf("2 - Gera valor aleatório e insere na árvore\n");
	printf("3 - Busca Elemento\n");
	printf("4 - Apresentar topo da pilha\n");
	printf("5 - Apresentar todos elementos da pilha\n");
	printf("6 - Remover elemento da árvore\n");
	printf("7 - Reinserir elemento na árvore\n");
	printf("8 - Pré - Ordem\n");
	printf("9 - Em Ordem\n");
	printf("10 - Pós Ordem\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
