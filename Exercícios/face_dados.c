#include<stdio.h>
#define TAM 6
#include<stdlib.h>
#include<time.h>


int main(){
    
    int vetor[TAM], valor, i, qtd;
    srand(time(NULL));
    
    vetor[0] = 0;
    vetor[1] = 0;
    vetor[2] = 0;
    vetor[3] = 0;
    vetor[4] = 0;
    vetor[5] = 0;
    
    printf("Informe a quantidade de vezes que o dado será arremessado: ");
    scanf("%d", &qtd);
    
    //For em uma linha só
    /* for(i=0; i<6; vetor[i++] = 0 ); */
    
    for(i=0; i<qtd; i++){
//        valor = (rand() %6);
//        printf("Tentativa %d; Face %d\n", i+1, valor+1);
//        vetor[valor] += 1;
        vetor[rand() % 6]++;
    }

    printf("Mostrando a quantidade de vezes que as faces foram selecionadas");
    for (i=0; i<=5; i++) {
        printf("\n\%d ocorrências da face %d  -- %.2f%%.\n", vetor[i], i+1, ((float)vetor[i]/qtd)*100);
    }
    
    return 0;
    
}
