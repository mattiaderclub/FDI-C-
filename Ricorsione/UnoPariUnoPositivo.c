#include <stdio.h>

int recPariPositivo(int seq[], int lung);

int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un array di interi\n");
	printf("e sfrutta una funzione ricorsiva per controllare l'esistenza\n");
	printf("di una coppia contenente un intero pari e l'altro positivo.\n\n");
	int lunghezza;			// Numero di elementi dell'array
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	/* Assegno i valori all'array */
	int array[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Intero della sequenza di indice %d: ", i);
		scanf("%d", &array[i]);
	}

	/* Output */
	int coppia = recPariPositivo(array, lunghezza);
	if(coppia)
		printf("\nEsiste una coppia che contiene un intero pari e l'altro positivo.\n");
	else
		printf("\nNessuna coppia contiene un intero pari e l'altro positivo.\n");

}

int recPariPositivo(int seq[], int lung){
	int esiste;

	if(lung<2)
		esiste = 0;
	else{
		esiste = (((seq[lung-1]%2==0 && seq[lung-2]>0) || (seq[lung-1]>0 && seq[lung-2]%2==0)) 
					|| recPariPositivo(seq, lung-1));

	}
	return esiste;
}