/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) sequenza di interi
 * Pre-condizone: n>=0
 * Output: intero contatore
 * Post-condizione: contatore rappresenta il numero di tripla di consecutivi
 					la cui somma è pari a 0

 * TIPO DI PROBLEMA: conteggio */

#include <stdio.h>

/* Funzione di supporto */
int triplaSommaZero(int seq[], int lung);

/* Funzione principale */
int main(){
	int lunghezza;			// Dimensione array
	int i;					// Per scandire la sequenza
	int contatore;			// Output

	/* INPUT */
	printf("\nQuanti interi devo leggere?\n");
	scanf("%d", &lunghezza);
	printf("\n");

	// Dichiaro array
	int array[lunghezza];
	/* Inserisco valori nell'array */
	for(i=0; i<lunghezza; i++){
		printf("Elemento della sequenza di indice %d: ", i);
		scanf("%d", &array[i]);
	}

	// Richiamo funzione e memorizzo il valore ritornato nella variabile di output
	contatore=triplaSommaZero(array, lunghezza);
	/* OUTPUT */
	printf("\nNumero di triple di consecutivi la cui somma %c 0: %d\n", 138, contatore);

}

/* Funzione che riceve come parametri una sequenza di interi e la sua lunghezza
 * e restituisce il numero di triple di consecutivi della sequenza la cui somma
 * è pari a 0 */
int triplaSommaZero(int seq[], int lung){
	int quante=0;				// Variabile contatore inizializzata a zero
	int i;						// Per ciclo for

	/* "Sfoglio" la sequenza */
	for(i=0; i<lung-2; i++){
		/* Se somma degli elementi pari a 0 allora incremento il contatore */
		if(seq[i]+seq[i+1]+seq[i+2]==0){
			quante++;
		}
	}
	return quante;				// Valore di ritorno
}
