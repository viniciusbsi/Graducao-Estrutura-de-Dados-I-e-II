#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>


unsigned long long int fibonacci(int n){
    if (n == 0)
		return 0;
	else
		if (n == 1)
			return 1;
		else
			return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	time_t t_inicial, t_final;
	t_inicial = time( NULL );
	long long unsigned int n = 50;
	printf("valor %llu\n", fibonacci(n));
	t_final = time( NULL );
	printf("Tempo = %f \n", difftime(t_final, t_inicial));
}
