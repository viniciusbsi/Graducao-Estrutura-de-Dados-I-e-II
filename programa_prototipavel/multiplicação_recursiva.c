#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int multiplicacao_recursiva(int x, int n){
    if (n == 1)
		return x;
	if (n > 0)
		return x + multiplicacao_recursiva(x, n-1);
}

int main(){
	printf("%d\n", multiplicacao_recursiva(4,3));
	printf("%d\n", multiplicacao_recursiva(5,5));
	printf("%d\n", multiplicacao_recursiva(3,7));
}
