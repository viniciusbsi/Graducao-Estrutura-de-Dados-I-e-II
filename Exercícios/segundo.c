/*
 * Programa que soma 2 valores inteiros
 */
 #include<stdio.h>
int main(){
    int valor1, valor2, soma;
    // Se as variáveis não forem iniciadas com 0, caso algum dos valores não forem digitados, o C vai somar com o vaor já presente no endereço daquela memória (lixo de memória)
    valor1 = 0;
    valor2 = 0;
    
    printf("Informe o valor 1: ");
    // Como ler a variável: deve ser usado o "&" para que ele leia o valor, transforme em inteiro e jogue no endereço daquela memória "pegue o valor inserido e jegue no endereço valor1"
    scanf("%d", &valor1);
    
    printf("Informe o valor 2: ");
    scanf("%d", &valor2);
    
    soma = valor1 + valor2;
    printf("\n A soma dos valores é: %d \n", soma);
    return 0;
    
}
