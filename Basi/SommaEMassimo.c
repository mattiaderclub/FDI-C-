#include <stdio.h>

int main(){
	int numero;
	int max = 0;
	int somma = 0;
	int prodotto = 1;

	printf("Introduci un valore positivo: ");
	scanf("%d", &numero);

	while(numero>0){

		if(numero>0){
			somma += numero;
			prodotto *= numero;
			if(numero>max){
				max = numero;
			}
		}
		printf("Introduci un valore positivo: ");
		scanf("%d", &numero);
	}
	printf("Somma pari a: %d\n", somma);
	printf("Massimo pari a: %d\n", max);
	printf("Prodotto pari a: %d\n", prodotto);
}