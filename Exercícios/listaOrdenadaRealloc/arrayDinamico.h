// Definicoes de estruturas
typedef struct {
	int codigo;
	float valor;
}vetor;

typedef struct {
	int capacidade;		// Capacidade total de armazenamento do array
	int quantidade;		// Numeros de elementos no array
	vetor *elementos;
}array;

//Prototipacao de funcoes
array* inicializar();
void inserir(array*, int, float);
int buscaSequencial(array*, int);
int buscaBinaria(array*, int);
void removeElemento(array*, int);
vetor* realocar(array*, int);
