#include<stdio.h>
#include<stdlib.h>

int menu(){
    int op;
    printf("1 - Alocar Memória\n ");
    printf("2 - Alocar Memória\n ");
    printf("\n0 - Sair\n ");
    printf("Opção: ");
    scanf("%d", &op);
    return(op);
}


int main(){
        //o asterisco informa que o vetor vai ser um ponteiro para um endereço de memória do tipo inteira 
        int tam, *vetor;
        do {
            switch(menu()){
                case 1:
                    vetor = alocar();
                    printf("Alocar\n");
                    break;
                case 2:
                    printf("Adicionar\n");
                    break;
                case 0:
                    return 0;
                
            }
        } while (1=1);

        /*for(int i=0; i<tam; vetor[i++]=i);
        for(int i=0; i<tam; i++){
            printf("\nPos %d: valor %d", i, vetor[i]);
        }
        */
        //return 0;
}

int* alocar(){
    int tam, *vetor;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    //Malloc é uma alocação de memória a partir do ponteiro criado pela variável "vetor", o número digitado vezes um tamanho de um inteiro
    vetor = (int*) * malloc(sizeof(int)*tam);
    //retorna o conteúdo do vetor
    return(vetor);
}

int* realocar(){
    int tam, *vetor;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    //Realloc já tem um tamanho de 50, e eu quero um de 200 e o programa não tem espaço de memória na sequencia, ele cria um de 200, move elemente por elemento e depois apaga o de 200 antigo;
    
    vetor = (int*) * realloc(vetor, sizeof(int)*tam);
    //retorna o conteúdo do vetor
    return(vetor);
}


/*printf("Tamanho de um INT: %li\n", sizeof(int));
        printf("End de memória do ponteiro vetor: %p\n", vetor);
        printf("End de memória para onde ele está apontando: %p é o mesmo que o end para onde ele está apontando \n", vetor);
        printf("End de memória vetor na posição [0]: %p\n", &vetor[0]);
        printf("End de memória vetor na posição [2]: %p\n", &vetor[2]);
        printf("End de memória vetor na posição [4]: %p\n", &vetor[4]);*/
