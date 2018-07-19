int particiona(int vet[], int inicio, int fim){
	int x,i,j,auxiliar;
	x = vet[inicio];
	i = inicio - 1;
	j = fim + 1;
	for(;;){
		do{ j--; }while(vet[j] > x);
		do{ i++; }while(vet[i] < x);
		if (i < j){
			auxiliar = vet[i];
			vet[i] = vet[j];
			vet[j] = auxiliar;
		}
		else{
			return j;
		}
	} 
}
