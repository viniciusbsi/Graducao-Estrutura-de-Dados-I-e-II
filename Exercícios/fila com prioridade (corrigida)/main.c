#include <stdio.h>
#include <stdlib.h>
#include "fila_com_prioridade.h"

int menu();

int main() {
	Elemento* ponto;
	Fila* minhaFila;
	int cod, qtd, codigoPesquisa;
	float valor, novoValor;
    int valorPesquisa, posicao, op;
        do {
		switch (menu() ){
			case 0:
				return 1;
			case 1:
				minhaFila = inicializar();
                printf("Fila inicializada...\n");
				break;
                
            case 2:
				printf("Informe o código de prioridade: ");
				scanf("%d", &cod);
                printf("Informe o valor: ");
				scanf("%f", &valor);
                enfileirar(minhaFila, cod, valor);
				break;
            case 3:
                desenfileirar(minhaFila);
				break;

			case 4:
				mostrarProximo(minhaFila);
				break;

            case 5:
            	percorrer(minhaFila);
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
	printf("Fila COM PRIORIDADE\n");
	printf("1 - Inicializar / Popular\n");
	printf("2 - Enfileirar\n");
	printf("3 - Desenfileirar\n");
	printf("4 - Mostrar pŕoximo\n");
	printf("5 - Percorrer\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
