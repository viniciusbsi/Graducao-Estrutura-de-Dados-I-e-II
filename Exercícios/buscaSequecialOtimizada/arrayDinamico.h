// Definicoes de estruturas
typedef struct {
	int codigo;
	float valor;
}vetor;

typedef struct {
	int valor;
}vetorInteiros;

typedef struct {
	int capacidade;		// Capacidade total de armazenamento do array
	int quantidade;		// Numeros de elementos no array
	vetor *elementos;
}array;

typedef struct {
	int capacidade;		// Capacidade total de armazenamento do array
	int quantidade;		// Numeros de elementos no array
	vetorInteiros *elementos;
}Inteiros;

//Prototipacao de funcoes
array* inicializar();
Inteiros* inicializarInteiros();
void inserir(array*, int, float);
void inserirValores(Inteiros*, int);
int buscaSequencial(Inteiros*, int);
int buscaOtimizada(array*, int);
