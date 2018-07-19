#include<stdio.h>
//comentário teste
/*.h é o arquivo onde são criadas as funções, .c é o arquivo onde essas funções são usadas 
geralmente o C funciona em várias máquinas mas deve ser compilados em todas essas antes de ser usado, não adianta usar só o arquivo executável 
*/
//void main() - void informa que a função não tem retorno
//abaixo é como se tivesse dado def de uma função que retornará um INTEIRO
int main(){
    printf("Olá mundo.\n");
    return 0;
}
/*
Para compilar:
* gcc 1.c -o primeiroCompilado
* ./primeiroCompilado
*/
