
typedef struct elemento{
    int codigo;
    float valor;
    struct elemento *p_prox;
    //é criado essa var elemento para que no inicio essa struct aponte para ela mesma

}Elemento;

typedef struct{
    Elemento *p_inicio;
}Pilha;

typedef struct{
    Elemento *p_inicio;
}Fila;

Pilha* inicializar();
void empilhar(Pilha*, int, float);
void desimpilhar(Pilha*);
void apresentarTopo(Pilha*);
Elemento* criarElemento(int, float);
