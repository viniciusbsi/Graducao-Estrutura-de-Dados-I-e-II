//Aqui são definidos os tipos e as definições das estruturas



//é como se fosse uma classe ponto em python, que quando for inicializada recebe valores para x e y
//typedef struct{
//    int x;
//    int y;
//}ponto;

typedef struct{
    int cod;
    float valor;
}cod_valor;


//é como se fosse uma classe ponto em python, que quando é inicializada recebe valores para capaciade e quantidade, e uma def "addPontos" que passa valores x e y para a classe "ponto" 
typedef struct{
    int capacidade; // capacidade total de armazenamento do array
    int quantidade; // número de elementos no array
    cod_valor *pontos;
}arraySeq;


// Inicio das prototipações de função
arraySeq* inicializar();
int getCapacidade(arraySeq*);
int getQuantidade(arraySeq*);
void adicionaCoordenada(arraySeq*, int, int);
void adicionaCoordenadaK(arraySeq*, int, int, int);
void adicionaCoordenadaOrdenada(arraySeq*, int, float);
arraySeq* removeElemento(arraySeq*,int);
int getUltimoX(arraySeq*);
int getUltimoY(arraySeq*);
