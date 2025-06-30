#include <stdio.h>
 
 /* Programma che chiede di inserire un intero n positivo
  * e stampa i primi n interi positivi dispari */

int main(){
	int numero, i;
	printf("Utente, dammi un intero positivo: ");
	scanf("%d", &numero);

	for(i=1; i<(numero*2); i+=2){
		printf("%d  ", i);
	}
}