/*
 * Programa que soma 2 valores inteiros
 */
 #include<stdio.h>
int main(){
    int valor1, valor2, soma;
    // Se as variáveis não forem iniciadas com 0, caso algum dos valores não forem digitados, o C vai somar com o vaor já presente no endereço daquela memória (lixo de memória)
    valor1 = 0;
    valor2 = 0;
    
    printf("Informe dois valores: ");
    scanf("%d", &valor1);
    scanf("%d", &valor2);
    //Usando dois scans, ele separa os valores por espaços e os soma;
    
    soma = valor1 + valor2;
    printf("\n A soma dos valores é: %d \n", soma);
    return 0;
    
}
