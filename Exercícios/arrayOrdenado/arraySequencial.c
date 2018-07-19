#include "arraySequencial.h" //é um arquivo, por isso entre aspas, é o caminho absoluto.... usa <> nas outros pq está na biclioteca
#include<stdlib.h>
#include<stdio.h>

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
    novoArray->pontos = (cod_valor*) malloc(sizeof(cod_valor) *2);
    
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

/*void adicionaCoordenada(arraySeq* array, int pontoX, int pontoY){
    
    //array na posição pontos tem um ponteiro para um ponto(x,y)
    //então pontos[array->quantidade] é a posição onde eu vou adicionar, no inicio é 0
    //então para esse ponto eu passo os valores de x e y
    array->pontos[array->quantidade].x=pontoX;
    array->pontos[array->quantidade].y=pontoY;
    array->quantidade++;
}*/ 

/*void adicionaCoordenadaK(arraySeq* array, int pontoX, int pontoY, int pos){
    if (pos >= array->quantidade){
        adicionaCoordenada(array, pontoX, pontoY);
    }
    else{
        for (int i = array->quantidade; i > pos; i--){
            array->pontos[i] = array->pontos[i-1];
        }
        array->pontos[pos].x = pontoX;
        array->pontos[pos].y = pontoY;
        array->quantidade++;
    }
}*/

void adicionaCoordenadaOrdenada(arraySeq* array, int cod, float valor){
    if (array->quantidade == 0){
        array->pontos[array->quantidade].cod = cod;
        array->pontos[array->quantidade].valor = valor;
        array->quantidade++;
    }
    else{
        int i;
        i = array->quantidade;
        while(array->pontos[i-1].cod > cod){
            i--;
            array->pontos[i+1] = array->pontos[i];
        }
        if (i == -1){
            array->pontos[0].cod = cod;
            array->pontos[0].valor = valor;
            array->quantidade++;
        }
        else{
            array->pontos[i].cod = cod;
            array->pontos[i].valor = valor;
            array->quantidade++;
        }
    }
}

arraySeq* removeElemento(arraySeq* array, int cod){
	arraySeq* arrayBackup;
	arrayBackup = inicializar();
	int qtd, i;
	i = 0;
	qtd = array->quantidade;
	while(i < qtd){
		if(array->pontos[i].cod != cod){
			arrayBackup->pontos[i].cod = array->pontos[i].cod;
			arrayBackup->pontos[i].valor = array->pontos[i].valor;
			arrayBackup->quantidade++;  
		}
		else{
			arrayBackup->pontos[i].cod = array->pontos[i+1].cod;
			arrayBackup->pontos[i].valor = array->pontos[i+1].valor;
		}
		i++;
	}
	return arrayBackup;
}

/*int getUltimoX(arraySeq* array){
    return array->pontos[array->quantidade-1].cod;
}

int getUltimoY(arraySeq* array){
    return array->pontos[array->quantidade-1].cod;
}*/




/*
void adicionaCoordenadaOrdenada(arraySeq* array, int cod, float valor){
    if (array->quantidade == 0){
        array->pontos[array->quantidade].cod = cod;
        array->pontos[array->quantidade].valor = valor;
        array->quantidade++;
    }
    else{
        int i;
        i = array->quantidade;
        while(array->pontos[i-1].cod >= cod){
            i--;
        }
        if (i == -1){
            for (int qtd = array->quantidade; qtd > i; qtd--){
                array->pontos[qtd] = array->pontos[qtd-1];
            }
            array->pontos[0].cod = cod;
            array->pontos[0].valor = valor;
            array->quantidade++;
        }
        else{
            for (int qtd = array->quantidade; qtd > i; qtd--){
                array->pontos[qtd] = array->pontos[qtd-1];
            }
            array->pontos[i].cod = cod;
            array->pontos[i].valor = valor;
            array->quantidade++;
        }
    }
}
*/
