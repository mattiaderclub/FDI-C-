#include <stdio.h>

/* Funzione di supporto */
int consecUguali(int interi[], int n);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un array di interi e controlla se\n");
	printf("esistono due interi consecutivi uguali sfruttando il meccanismo di ricorsione.\n");
	int lunghezza;
	printf("Da quanti interi %c composto l'array? ", 138);
	scanf("%d", &lunghezza);

	/* Dichiaro e assegno i valori all'array */
	int array[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Intero di indice %d = ", i);
		scanf("%d", &array[i]);
	}

	/* Output */
	if(consecUguali(array, lunghezza))
		printf("\nEsistono due interi consecutivi uguali nella sequenza.\n");
	else
		printf("\nNon esistono due interi consecutivi uguali nella sequenza.\n");
}

/* Funzione che riceve come parametri un array di interi e la sua lunghezza.
 * Controlla se esistono due interi consecutivi uguali nella sequenza */
int consecUguali(int interi[], int n){
	int esistono;

	if(n<2)
		esistono = 0;
	else
		esistono = ((interi[n-1] == interi[n-2]) || consecUguali(interi, n-1));
	return esistono;
}