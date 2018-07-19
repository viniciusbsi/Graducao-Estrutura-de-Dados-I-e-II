#include<stdio.h>
#include<stdlib.h>
int menu(void);

int main(){
    int op; //variável de opção de menu
    float valor1, valor2, resultado;
    op = menu();
    while (op != 0){
        printf("%d", op);
        printf("Informe o valor 1: ");
        scanf("%f", &valor1);

        printf("Informe o valor 2: ");
        scanf("%f", &valor2);
        
        switch(op){
            case 1:
                printf("Soma");
                resultado = valor1 + valor2;
                printf("A soma é: %f", resultado);
                break;
                
            case 2:
                printf("Subtração");
                resultado = valor1 - valor2;
                printf("A subtração é: %f", resultado);
                break;
                
            case 3:
                printf("Multiplicação");
                resultado = valor1 * valor2;
                printf("A multiplicação é: %f", resultado);
                break;
                
            case 4:
                printf("Divisão");
                resultado = valor1 / valor2;
                printf("A divisão é: %f", resultado);
                break;
            default:
                printf("Digitou a opção errada");
                break;
        }
        getchar();
        op = menu();
    }
    return 0;
}

int menu(){
        system("clear");
        int opcao;
        opcao = 0;
        printf("\n=======================\n");
        printf("1 - Soma\n");
        printf("2 - Subtração\n");
        printf("3 - Multiplicação\n");
        printf("4 - Divisão\n");
        printf("0 - sair\n");
        printf("\n\n Opção -->");
        scanf("%d", &opcao);
        return opcao;
        
    
}
