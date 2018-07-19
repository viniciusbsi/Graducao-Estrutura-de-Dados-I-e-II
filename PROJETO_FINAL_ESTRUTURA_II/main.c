#include "grafo.h"
#include "fila_heap.h"

int main(){
	grafo_t* grafo_no = criaGrafo(10);
	//~ for (int i = 0; i < 419; i++){
		//~ insere_arco_grafo(grafo_no, vet_inicial[i][0], vet_inicial[i][1], vet_inicial[i][2]);
	//~ }
	insere_arco_grafo(grafo_no, 1,2,3);
	insere_arco_grafo(grafo_no, 1,3,6);
	insere_arco_grafo(grafo_no, 2,3,2);
	insere_arco_grafo(grafo_no, 3,2,4);
	int pred[grafo_no->num_vertices];
	int custo[grafo_no->num_vertices];
	dijkstra(grafo_no, 1, pred, custo);
	//~ mostraGRAFO(grafo_no);
	return 0;
}

