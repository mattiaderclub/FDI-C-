/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0, (x1, x2, ..., xn) sequenza di interi
 * Output: valore booleano tutte
 * Post-condizione: tutte vale 1 se ogni tripla di numeri consecutivi della sequenza 
 					contiene almeno un intero pari e uno dispari, 0 altrimenti

 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

/* Funzione ausiliaria:
 * Restituisce 1 se ogni tripla di numeri consecutivi della sequenza 
 * contiene almeno un intero pari e uno dispari, 0 altrimenti */
int triplePariDispari(int seq[], int n);

/* Funzione principale */
int main(){
	/* Input */
	int lunghezza;					// Dimensione array
	int i;							// Per scandire la sequenza
	int tutte;						// Variabile booleana
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e restituisce\n");
	printf("1 se ogni tripla di consecutivi contiene almeno un intero pari e uno dispari, 0 altrimenti.\n");
	printf("\nQuanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	printf("\n");

	/* Dichiaro l'array una volta nota la dimensione */
	/* Input valori array */
	int interi[lunghezza];
	for(i=0; i<lunghezza; i++){
		printf("Elemento di indice %d ha valore: ", i);
		scanf("%d", &interi[i]);
	}

	/* Richiamo la funzione e assegno il suo valore di ritorno (booleano) alla variabile booleana */
	tutte = triplePariDispari(interi, lunghezza);
	/* Output */
	if(tutte)
		printf("\nTutte le triple di interi consecutivi della sequenza contengono almeno un intero pari e uno dispari.\n");
	else
		printf("\nEsiste almeno una tripla di interi consecutivi della sequenza che non contiene un intero dispari o uno pari.\n");
}

int triplePariDispari(int seq[], int n){
	int i;						// Contatori
	int pariDispari = 1;		// Variabile booleana

	/* Controllo l'array fino al terzoultimo elemento in quanto devo controllare le triple */
	for(i=0; i<n-2 && pariDispari; i++){
		/* Si verifica la proprietà? */
		if(!((seq[i]%2==0 || seq[i+1]%2==0 || seq[i+2]%2==0) &&
			(seq[i]%2!=0 || seq[i+1]%2!=0 || seq[i+2]%2!=0))){
			pariDispari = 0;
		}
	}
	return pariDispari;			// Valore di ritorno (booleano)
}