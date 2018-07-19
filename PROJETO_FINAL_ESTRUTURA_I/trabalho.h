//VETOR
typedef struct {
	int codigo;
	int valor;
}vetor;

typedef struct {
	int capacidade;		// Capacidade total de armazenamento do array
	int quantidade;		// Numeros de elementos no array
	vetor *elementos;
}array;

array* inicializarVetor();
vetor* realocar(array*, int);
void inserirVetor(array*, int);
int buscaSequencial(array*, int);
int buscaAleatorio(array*);


//ÁRVORE
typedef struct node {
	int id;
	struct node* pMenor;
	struct node* pMaior;
	struct node* pPai;
}Node;

typedef struct {
	Node* raiz;
}Tree;

Tree* inicializarArvore();
Node* inserirArvore(Node*, int);
int buscaElemento(Node*, int);
Node* buscarPai(Node*, int);
//~ void inserirRandom(Node*, array*);
Node* removerSubRaiz(Node*);
Node* remover(Node*, int);
void inOrder(Node*);
void preOrder(Node*);
void posOrder(Node*);


//PILHA
typedef struct elemento{
    int codigo;
    struct elemento *p_prox;

}Elemento;

typedef struct{
    Elemento *p_inicio;
}Pilha;

Pilha* inicializarPilha();
void empilhar(Pilha*, int);
void desimpilhar(Pilha*);
int apresentarTopo(Pilha*);
Elemento* criarElemento(int);
void apresentarElementosPilha(Pilha*);


//LISTA ENCADEADA

typedef struct{
    Elemento *p_inicio;
    int tamanho_lista;
}Lista;

Lista* inicializar();
void removerLista(Lista*, int);
void percorrer(Lista*);
void inserirInicio(Lista*, int);
int procurar(Lista*);
