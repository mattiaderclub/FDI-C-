/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0 (n è la lunghezza dell'array), (x1, x2, ..., xn) sequenza di interi
 * Output: intero piuLunga
 * Post-condizione: piuLunga rappresenta la lunghezza della sottosequenza più lunga crescente
 					di interi dove per "sotto-sequenza" si intende una sequenza 
 					di interi che appaiono consecutivamente nella sequenza

 * TIPO DI PROBLEMA: Massimo */

#include <stdio.h>
/* Array 14 */
/* Funzione di supporto */
int crescentePiuLunga(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	int i;					// Contatore
	int piuLunga;			// Lunghezza sottosequenza più lunga
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e ritorna\n");
	printf("la lunghezza della sottosequenza crescente piu' lunga all'interno della sequenza di partenza.\n");
	int lunghezza;			// Dimensione sequenza
	printf("\nIntanto introduci la lunghezza della sequenza: "),
	scanf("%d", &lunghezza);
	printf("\n");

	/* Input valori nell'array */
	int interi[lunghezza];
	for(i=0; i<lunghezza; i++){
		printf("Elemento di indice %d ha valore ", i);
		scanf("%d", &interi[i]);
	}

	/* Richiamo la funzione crescentePiuLunga e memorizzo il valore
	 * di ritorno all'interno della variabile piuLunga */
	piuLunga = crescentePiuLunga(interi, lunghezza);
	/* Output */
	printf("\nLa sottosequenza crescente di interi piu' lunga della sequenza ha lunghezza pari a %d.\n", piuLunga);
}

/* Funzione che riceve come parametro un array di interi e la sua lunghezza e trova
 * la sottosequenza crescente di interi più lunga della sequenza. Ne ritorna la lunghezza. */
int crescentePiuLunga(int seq[], int lung){
	int i;					// Per scandire la sequenza
	int contatore = 1;		// Conta la lunghezza di ogni nuova sottosequenza
	int max = 1;			// Variabile massimo

	/* Controllo l'array fino all'ultimo intero */
	for(i=0; i<lung-1; i++){
		/* La sotto-sequenza è crescente? 
		 * Se sì, incremento il contatore 
		 * Altrimenti, lo resetto a 1 */
		if(seq[i]<seq[i+1]){
			contatore++;
			/* Controllo se il contatore è più grande del massimo */
			if(max<contatore)
				max = contatore;
		}
		else
			contatore = 1;		
	}
	return max;				// Valore di ritorno
}