#include <stdio.h>

/* Sempre inizializzare il massimo 
 * quando si usa do while */

int main(){
	int numero;
	int massimo = 0;
	int somma = 0;

	do{
		printf("Inserisci un valore positivo: ");
		scanf("%d", &numero);
		if(numero>0){
			somma += numero;
			if(numero>massimo){
				massimo = numero;
			}
		}
	}
	while(numero>0);
	if(massimo>0)
		printf("La somma %c pari a %d, il massimo %c %d\n", 
			138, somma, 138, massimo);
	else
		printf("Mi servono valori positivi\n");
}