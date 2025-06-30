#include <stdio.h>

int main(){
	int n, i;
	int fib = 0;
	int fib_prec = 1;
	int fib_succ = 1;

	printf("Quanti valori della sequenza di Fibonacci vuoi? ");
	scanf("%d", &n);
	printf("Primi %d interi della sequenza di Fibonacci:\n", n);

	for(i=1; i<=n; i+=3){

		printf("%d  ", fib_prec);
		printf("%d  ", fib_succ);
		
		fib = fib_prec + fib_succ;
		printf("%d  ", fib);
		
		fib_prec = fib_succ + fib;
		fib_succ = fib_prec + fib; 
		
		
	}
	printf("\n");
}