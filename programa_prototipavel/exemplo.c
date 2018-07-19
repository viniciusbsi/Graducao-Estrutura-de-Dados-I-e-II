#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int nome;
	int matricula;
}alunos;

alunos* inicializa(){
	alunos* aluno;
    aluno = malloc(sizeof(alunos)*10);
    for(int i = 0; i < 10; i++){
		aluno[i].nome = NULL;
		aluno[i].matricula = NULL;
	}
	return aluno;
}

void preenche(alunos* aluno, int posicao){
	int matricula;
	int nome;
	printf("Nome: ");
	scanf("%d", &nome);
	printf("Matricula: ");
	scanf("%d", &matricula);
	aluno[posicao].nome = nome;
	aluno[posicao].matricula = matricula;
}

void organiza(alunos* aluno, int p1, int p2){
	char aux_nome;
	int aux_matricula;
	if(aluno[p1].matricula > aluno[p2].matricula){
		aux_nome = aluno[p2].nome;
		aux_matricula = aluno[p2].matricula;
		aluno[p2].matricula = aluno[p1].matricula;
		aluno[p2].nome = aluno[p1].nome;
		aluno[p1].matricula = aux_matricula;
		aluno[p1].nome = aux_nome;
	}
	return;
}

int main(){
	alunos* cadastro;
	cadastro = inicializa();
	preenche(cadastro, 0);
	printf("\nPosição %d", 0);
	printf("\nNome: %d", cadastro[0].nome);
	printf("\nMatricula: %d \n", cadastro[0].matricula);
	preenche(cadastro, 1);
	organiza(cadastro, 0, 1);
	
}
