#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int menu();

int main() {
	Elemento* ponto;
	Pilha* minhaPilha;
	int cod, qtd, codigoPesquisa;
	float valor, novoValor;
    int valorPesquisa, posicao, op;
        do {
		switch (menu() ){
			case 0:
				return 1;
			case 1:
				minhaPilha = inicializar();
                printf("Pilha inicializada...\n");
				break;
                
            case 2:
                printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o valor: ");
				scanf("%f", &valor);
                empilhar(minhaPilha, cod, valor);
				break;
            case 3:
                desimpilhar(minhaPilha);
				break;

			case 4:
				apresentarTopo(minhaPilha);
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
	printf("Lista PONTA SIMPLES\n");
	printf("1 - Inicializar / Popular\n");
	printf("2 - Empilhar\n");
	printf("3 - Desimpilhar\n");
	printf("4 - Apresentar o topo\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
