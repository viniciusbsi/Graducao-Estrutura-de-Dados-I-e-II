#include "arraySequencial.h" //é um arquivo, por isso entre aspas, é o caminho absoluto.... usa <> nas outros pq está na biclioteca
#include<stdlib.h>

//Aqui estão as funções relacionadas com o array


//Neste código não tem interação com o usuário, então não precisa do stdio

arraySeq* inicializar(){
    //novoArray é um ponteiro para um arraySeq
    arraySeq* novoArray; //ponteiro temporário
    
    //Alocou um espaço para o array
    novoArray = (arraySeq*) malloc(sizeof(arraySeq));
    
    //como é um ponteiro, usa a flecha para acessar os elementos de um ponteiro
    //Aqui é criado é passado os valore [2, 0, ponteiro para um vetor que pode armazenar 2 pontos]
    novoArray->capacidade = 2;
    novoArray->quantidade = 0;
    novoArray->pontos = (ponto*) malloc(sizeof(ponto) *2);
    
    return novoArray;
}

//Recebe um ponteiro para o arraySeq e chama ele de 'array'
//Passagem de parâmetro por referência de memória, não é duplicado esse valor, mas sim, é passado o endereço de memória 
int getCapacidade(arraySeq* array){
    return array->capacidade;
}

int getQuantidade(arraySeq* array){
    return array->quantidade;
}

void adicionaCoordenada(arraySeq* array, int pontoX, int pontoY){
    
    //array na posição pontos tem um ponteiro para um ponto(x,y)
    //então pontos[array->quantidade] é a posição onde eu vou adicionar, no inicio é 0
    //então para esse ponto eu passo os valores de x e y
    array->pontos[array->quantidade].x=pontoX;
    array->pontos[array->quantidade].y=pontoY;
    array->quantidade++;
}

int getUltimoX(arraySeq* array){
    return array->pontos[array->quantidade-1].x;
}

int getUltimoY(arraySeq* array){
    return array->pontos[array->quantidade-1].y;
}
