#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

int menu();

int main() {
	Elemento* ponto;
	Lista* minhalista;
	int cod, qtd, codigoPesquisa;
	float valor, novoValor;
    int valorPesquisa, posicao, op;
        do {
		switch (menu() ){
			case 0:
				return 1;
			case 1:
				minhalista = inicializar();
                printf("Lista inicializada...\n");
				break;
                
            case 2:
                printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o valor: ");
				scanf("%f", &valor);
                inserirInicio(minhalista, cod, valor);
				break;
            case 3:
                printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o valor: ");
				scanf("%f", &valor);
                inserirMeio(minhalista, cod, valor);
				break;

			case 4:
				printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o valor: ");
				scanf("%f", &valor);
                inserirFinal(minhalista, cod, valor);
				break;
                
			case 5:
                percorrer(minhalista);
                break;
                
			case 6:
                printf("1 - Por código\n");
                printf("2 - Por valor\n");
                printf("Opção: ");
                scanf("%d", &op);
                if(op == 1){
                    printf("Informe o código: ");
                    scanf("%d", &valorPesquisa);
                    procurar(minhalista, valorPesquisa, 1);
                    break;
                }
                if(op == 2){
                    printf("Informe o valor: ");
                    scanf("%d", &valorPesquisa);
                    procurar(minhalista, valorPesquisa, 2);
                    break;
                }
                break;
                
                
            case 7:
                printf("Informe o valor: ");
				scanf("%d", &valorPesquisa);
                remover(minhalista, valorPesquisa);
                break;
                
            case 8:
                printf("Informe o código: ");
				scanf("%d", &cod);
				printf("Informe o novo valor: ");
				scanf("%f", &novoValor);
                alterarElemento(minhalista, cod, novoValor);
				break;
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
	printf("1 - Inicializar / Popular\n");
	printf("2 - Inserir no Início\n");
	printf("3 - Inserir em posição específica\n");
	printf("4 - Inserir no Fim\n");
	printf("5 - Percorrer\n");
	printf("6 - Procurar\n");
	printf("7 - Remover\n");
	printf("8 - Alterar Elemento\n");
	printf("\n0 - Sair\n");
	printf("Opção: ");
	scanf("%d", &op);
	return(op);
}
// Fim das funcoes
