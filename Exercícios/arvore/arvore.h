typedef struct node {
	int id;
	struct node* pMenor;
	struct node* pMaior;
}Node;

typedef struct {
	Node* raiz;
}Tree;

Tree* inicializar();
Node* inserir(Node*, int);
Node* remover(Node*, int);
Node* maiorDoMenor(Node*);
Node* menorDoMaior(Node*);
void inOrder(Node*);
