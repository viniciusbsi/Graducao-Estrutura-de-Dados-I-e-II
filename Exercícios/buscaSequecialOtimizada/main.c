    #include <stdio.h>
#include <stdlib.h>
#include "arrayDinamico.h"

// Prototipacoes de funcao
int menu();

int main() {
	array* estrutura;
	Inteiros* intVetor;
	int cod, qtd, codigoPesquisa;
	float valor;
        int valorPesquisa, posicao;
        do {
		switch (menu() ){
			case 0:
				return 1;
			case 1:
				estrutura = inicializar();
                intVetor = inicializarInteiros();
				printf("Coordenadas inicializadas...\n");
				break;
            case 2:
                printf("Informe o valor: ");
				scanf("%f", &valor);
				inserirValores(intVetor, valor);
                break;
			case 3:
				printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o valor: ");
				scanf("%f", &valor);
				inserir(estrutura, cod, valor);
				break;
			case 4:
				qtd = estrutura->quantidade;
				for (int i = 0; i < qtd; i++) {
					printf("(%d, %.2f) ", estrutura->elementos[i].codigo, estrutura->elementos[i].valor);
				}
				printf("\n.... %d elementos na estrutura....\n", qtd);
				break;
			case 5:
                printf("Informe o valor: ");
				scanf("%d", &valorPesquisa);
				posicao = buscaSequencial(intVetor, valorPesquisa);
                printf("Posição do elemento: %d\n", posicao);
            case 6:
                printf("Informe o código: ");
				scanf("%d", &codigoPesquisa);
				posicao = buscaOtimizada(estrutura, codigoPesquisa);
                printf("Posição do elemento com busca otimizada: %d\n", posicao);
            default:
				break;
		}
	}while (1 == 1);
}
// Fim do programa principal



// Inicio das funcoes
int menu() {
	int op;
	printf("1 - Inicializar\n");
	printf("2 - Adicionar Elemento\n");
	printf("3 - Adicionar Elemento Ordenado\n");
	printf("4 - Percorrer\n");
	printf("5 - Busca Sequencial\n");
	printf("6 - Busca Otimizada\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
