#include <stdio.h>

/* Programma che chiede di inserire un intero positivo 
 * da tastiera e stampa tutti gli interi dispari minori 
 * o uguali all'intero inserito */

int main(){
	int num, i;
	printf("Dammi un intero positivo: ");
	scanf("%d", &num);

	for(i=1; i<=num; i+=2){
		printf("%d  ", i);
	}
}