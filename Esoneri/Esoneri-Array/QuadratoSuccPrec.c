/* SPECIFICA
 * Input: (x1, x2, ..., xn) e intero n
 * Pre-condizione: n>=0 (n è a lunghezza dell'array) e (x1, x2, ..., xn) sono interi
 * Output: valore booleano esiste
 * Post-condizione: esiste vale true se esiste un elemento nella sequenza che è
 					il quadrato del successivo o del precedente, false altrimenti

 * TIPO DI PROBLEMA: Verifica esistenziale */
#include <stdio.h>

/* Funzioni di supporto */
int quadrato(int seq[], int n);

/* Funzione principale */
int main(){
	/* Input */
	int i;					// Contatore
	int dimensione;			// Lunghezza array
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera\n");
	printf("e restituisce 1 o 0 se esiste un alemento nella sequenza che %c\nil quadrato del successivo o del precendente,\n", 138);
	printf("\nIntanto introduci la lunghezza della sequenza: ");
	scanf("%d", &dimensione);
	printf("\n");

	int array[dimensione];	// Array interi
	for(i=0; i<dimensione; i++){
		printf("Nuovo valore di indice %d = ", i);
		scanf("%d", &array[i]);	
	}

	/* Output */
	if(quadrato(array, dimensione))
		printf("\nEsiste nella sequenza un elemento che %c il quadrato del successivo o del precendente.\n", 138);
	else
		printf("\nNon esiste nella sequenza elemento che %c il quadrato del successivo o del precendente.\n", 138);
}	

/* Funzione che riceve come parametri un array di interi e la sua lunghezza
 * e controlla se esiste elemento che è pari al quadrato del suo precedente o successivo */
int quadrato(int seq[], int n){
	int quad = 0;				// Variabile booleana
	int i;						// Contatore for

	/* Controllo primo e ultimo carattere dell'array che non hanno
	 * rispettivamente un precedente e un successivo */
	if(seq[0] == seq[1]*seq[1] || seq[n-1] == seq[n-2]*seq[n-2])
		quad = 1;

	/* Controllo l'array dal secondo al penultimo carattere */
	/* Se quad = 1 dall'if precedente non entro nemmeno nel for e ritorno subito il valore */
	for(i=1; i<n-2 && !quad; i++){
		/* L'intero è pari al quadrato del precedente o del successivo? */
		if(seq[i] == seq[i+1]*seq[i+1] || seq[i] == seq[i-1]*seq[i-1])
			quad = 1;			// In caso affermativo aggiorno la variabile booleana
	}
	
	return quad;				// Valore di ritorno
}