#include <stdio.h>

int main(){
	int n, intero;
	int i, min;

	min=1;

	printf("Quanti valori devo controllare? ");
	scanf("%d", &n);

	for(i=1; i<=n; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &intero);
		if(intero<min)
			min=intero;
	}

	if(min<1)
		printf("Esiste un valore negativo\n");
	else
		printf("Tutti i valori sono positivi\n");
	printf("Alla prossima\n\n");
}