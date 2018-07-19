#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int menu();

int main() {
	Tree* minhaArvore;
	int valor;
        do {
		switch (menu() ){
			case 0:
				return 1;
			case 1:
				minhaArvore = inicializar();
				printf("Arvore criada inicializada...\n");
				break;
                
            case 2:
				printf("Informe o valor: ");
				scanf("%d", &valor);
                minhaArvore->raiz = inserir(minhaArvore->raiz, valor);
				break;
            case 3:
                inOrder(minhaArvore->raiz);
				break;

			case 4:
				printf("Informe o valor: ");
				scanf("%d", &valor);
                remover(minhaArvore->raiz, valor);
				break;
				
			case 9:
				minhaArvore->raiz = inserir(minhaArvore->raiz, 50);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 75);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 55);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 60);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 57);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 70);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 59);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 58);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 65);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 63);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 64);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 67);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 66);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 69);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 10);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 25);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 15);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 13);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 14);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 18);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 20);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 40);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 35);
				minhaArvore->raiz = inserir(minhaArvore->raiz, 45);
                minhaArvore->raiz = inserir(minhaArvore->raiz, 67);
				break;
			default:
				break;
		}
	}while (1 == 1);
}
// Fim do programa principal



// Inicio das funcoes
int menu() {
	int op;
	printf("\n\nÁRVORE\n");
	printf("1 - Inicializar\n");
	printf("2 - Adicionar Elemento\n");
	printf("3 - Apresentar valores\n");
	printf("4 - Remover\n");
	printf("9 - Popular\n");
	//~ printf("3 - Desenfileirar\n");
	//~ printf("4 - Mostrar pŕoximo\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
