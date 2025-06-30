#include <stdio.h>

/* Funzione ausiliaria */
int ArrayToNumero(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	int conversione;
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e lo converte\n");
	printf("in un intero composto dalle cifre degli array. La cifra piu' significativa ha indice 0.\n");
	int lunghezza;
	printf("\nDa quanti interi %c composto l'array?\n", 138);
	scanf("%d", &lunghezza);
	printf("\n");

	/* Assegno i valori agli indici dell'array */
	int interi[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Nuovo valore di indice %d della sequenza: ", i);
		scanf("%d", &interi[i]);
	}

	/* Invoca funzione che converte l'array e memorizza 
	 * il numero convertito in una variabile */
	conversione = ArrayToNumero(interi, lunghezza);
	/* Output */
	printf("\nArray: (");
	for(int j=0; j<lunghezza-1; j++){
		printf("%d,", interi[j]);
	}
	printf("%d)", interi[lunghezza-1]);
	printf("\nNumero: %d\n", conversione);
}

int ArrayToNumero(int seq[], int lung){
	int somma;

	if(lung==1)
		somma = seq[0];
	else
		somma = ArrayToNumero(seq, lung-1)*10 + seq[lung-1];
	return somma;
}