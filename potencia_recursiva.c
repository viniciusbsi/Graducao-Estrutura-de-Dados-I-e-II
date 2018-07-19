#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int potencia_recursiva(int x, int n){
    if (n == 0)
		return 1;
	if (n > 0)
		return x * potencia_recursiva(x, n-1);
}

int main(){
	printf("%d\n", potencia_recursiva(4,3));
}
