
typedef struct elemento{
    int codigo;
    float valor;
    struct elemento *p_prox;
    struct elemento *p_anterior;
    //é criado essa var elemento para que no inicio essa struct aponte para ela mesma

}Elemento;

typedef struct{
    Elemento *p_inicio;
    Elemento *p_fim;
}Lista;

Lista* inicializar();
void remover(Lista*, int);
void alterarElemento(Lista*, int, float);
void percorrer(Lista*);
void inserirInicio(Lista*, int, float);
void inserirMeio(Lista*, int, float);
void inserirFinal(Lista*, int, float);
Elemento* criarElemento(int, float);
void procurar(Lista*, int, int); //mostrar valor do código correspondente;
