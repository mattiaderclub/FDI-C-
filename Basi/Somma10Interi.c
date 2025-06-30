#include <stdio.h>

int main(){
	int numero, somma;
	int i;
	
	somma=0;

	for(i=1; i<=10; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &numero);

		somma+=numero;

	}
	printf("La somma dei dieci interi %c pari a: %d", 138, somma);
}