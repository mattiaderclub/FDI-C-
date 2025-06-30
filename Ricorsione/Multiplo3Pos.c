#include <stdio.h>

/* Funzione di supporto */
int multiplo3Pos(int seq[], int n);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e sfrutta la ricorsione\n");
	printf("per verificare l'esistenza di un intero positivio e multiplo di 3 all'interno della sequenza.\n");
	int dimensione;
	printf("Introduci la dimensione della sequenza: ");
	scanf("%d", &dimensione);

	/* Dichiaro e assegno i valori agli elementi dell'array */
	int array[dimensione];
	for(int j=0; j<dimensione; j++){
		printf("Aggiungi un valore all'indice %d dell'array: ", j);
		scanf("%d", &array[j]);
	}

	/* Output */
	if(multiplo3Pos(array, dimensione))
		printf("\nEsiste un intero nella sequenza sia positivo sia multiplo di 3.\n");
	else
		printf("\nNon esiste un intero nella sequenza sia positivo sia multiplo di 3.\n");
}

/* Funzione che riceve come parametri un array di interi e la sua lunghezza.
 * Verifica l'esistenza di un intero positivo e multiplo di 3 nella sequenza */
int multiplo3Pos(int seq[], int n){
	int esiste;

	if(n==0)
		esiste = 0;
	else
		esiste = ((seq[n-1]>0 && seq[n-1]%3==0) || multiplo3Pos(seq, n-1));
	return esiste;
}