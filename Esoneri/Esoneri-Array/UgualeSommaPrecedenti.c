/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0, (x1, x2, ..., xn) sequenza di interi
 * Output: valore booleano esiste
 * Post-condizione: esiste vale 1 se nella sequenza compare un numero uguale alla somma
 					degli elementi precedenti, 0 altrimenti

 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>
/* Array 10 */
/* Funzioni di supporto */
int ugualeSommaPrecedenti(int seq[], int n);

/* Funzione principale */
int main(){
	/* Input */
	int i;				// Contatore per scandire ciclo for
	int esiste;			// Variabile booleana
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e restituisce\n");
	printf("1 o 0 se esiste un intero che %c pari alla somma di tutti gli elementi precedenti.\n", 138);
	int lunghezza;		// Lunghezza array
	printf("\nIntroduci la lunghezza della sequenza da leggere: ");
	scanf("%d", &lunghezza);
	printf("\n");

	/* Input valori array */
	int interi[lunghezza];			// Array di interi
	for(i=0; i<lunghezza; i++){
		printf("Elemento di indice %d ha valore: ", i);
		scanf("%d", &interi[i]);
	}

	/* Invoca la funzione e inserisce il valore di ritorno nella variabile booleana */
	esiste = ugualeSommaPrecedenti(interi, lunghezza);
	/* Output */
	if(esiste)
		printf("\nEsiste intero pari alla somma di tutti i suoi elementi precedenti.\n");
	else
		printf("\nNon esiste intero pari alla somma di tutti i suoi elementi precedenti.\n");
}

/* Funzione che riceve come parametro un array e la sua dimensione e restituisce
 * un valore booleano: 1 se nella sequenza compare un numero uguale alla somma
 * degli elementi precedenti, 0 altrimenti */
int ugualeSommaPrecedenti(int seq[], int n){
	int i, j;					// Contatori
	int numeroControllato;		// Per memorizzare valore controllato a ogni passo del for
	int sommaPrec = 0;			// Variabile booleana
	int somma = 0;				// Per memorizzare somma precedenti

	/* Controllo l'array fino all'ultimo carattere tranne il primo elemento: 
	 * non ha elementi che lo precedono */
	for(i=1; i<n && !sommaPrec; i++){
		/* Memorizzo il prossimo valore dell'array */
		numeroControllato = seq[i];
		/* Sommo gli elementi precedenti */
		for(j=0; j<i; j++){
			somma += seq[j];
		}
		/* La somma dei precedenti è uguale all'intero? */
		if(somma==seq[i])
			sommaPrec = 1;
		somma = 0;				// Resetto il valore della somma
	}
	return sommaPrec;			// Valore di ritorno

}