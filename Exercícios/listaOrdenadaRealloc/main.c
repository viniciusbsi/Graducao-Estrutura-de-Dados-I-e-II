#include <stdio.h>
#include <stdlib.h>
#include "arrayDinamico.h"

// Prototipacoes de funcao
int menu();

int main() {
	array* estrutura;
	int cod, qtd, valor_busca, indice_busca, quantidade;
	float valor;
	do {
		switch (menu() ){
			case 0:
				return 1;
			case 1:
				estrutura = inicializar();
				printf("Coordenadas inicializadas...\n");
				break;
			case 2:
				printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o valor: ");
				scanf("%f", &valor);
				inserir(estrutura, cod, valor);
				break;
			case 3:
				qtd = estrutura->quantidade;
				for (int i = 0; i < qtd; i++) {
					printf("(%d, %.2f) ", estrutura->elementos[i].codigo, estrutura->elementos[i].valor);
				}
				printf("\n.... %d elementos na estrutura....\n", qtd);
				break;
			case 4:
				printf("\nCódigo para busca: ");
				scanf("%d", &valor_busca);
				indice_busca = buscaSequencial(estrutura,valor_busca);
				if (indice_busca == -1) {
					printf("Elemento não encontrado.\n");
				} else {
					printf("Elemento na posição %d\n", indice_busca);
					printf("Valor: %.2f\n\n", estrutura->elementos[indice_busca].valor);
				}
                break;
			case 5:
				printf("\nCódigo para busca: ");
				scanf("%d", &valor_busca);
				indice_busca = buscaBinaria(estrutura,valor_busca);
				if (indice_busca == -1) {
					printf("Elemento não encontrado.\n");
				} else {
					printf("Elemento na posição %d\n", indice_busca);
					printf("Valor: %.2f\n\n", estrutura->elementos[indice_busca].valor);
				}
                break;
			case 6:
				printf("Informe o código: ");
				scanf("%d", &cod);
				removeElemento(estrutura, cod);
                break;
			case 7:
				printf("Informe a quantidade de elementos a ser realocado: ");
				scanf("%d", &quantidade);
				realocar(estrutura, quantidade);
				printf("Nova quantidade %d\n", estrutura->capacidade);
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
	printf("1 - Inicializar\n");
	printf("2 - Adicionar Elemento\n");
	printf("3 - Percorrer\n");
	printf("4 - Busca Sequencial\n");
	printf("5 - Busca Binária\n");
	printf("6 - Remove Elemento\n");
	printf("7 - Realocar espaço\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
