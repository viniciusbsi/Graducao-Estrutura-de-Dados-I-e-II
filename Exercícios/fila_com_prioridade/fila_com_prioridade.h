
typedef struct elemento{
    float valor;
    int codigo;
    struct elemento *p_prox;
    //é criado essa var elemento para que no inicio essa struct aponte para ela mesma

}Elemento;

typedef struct{
    Elemento *p_inicio;
    Elemento *p_fim_fila;
    Elemento *p_fim_prioridade;
}Fila;

Fila* inicializar();
void enfileirar(Fila*, int, float);
void desenfileirar(Fila*);
void mostrarProximo(Fila*);
void percorrer(Fila*);
Elemento* criarElemento(int, float);
