
typedef struct elemento{
    float valor;
    struct elemento *p_prox;
    //é criado essa var elemento para que no inicio essa struct aponte para ela mesma

}Elemento;

typedef struct{
    Elemento *p_inicio;
    //~ Elemento *p_fim;
}Fila;

Fila* inicializar();
void enfileirar(Fila*, float);
void desenfileirar(Fila*);
void mostrarProximo(Fila*);
Elemento* criarElemento(float);
