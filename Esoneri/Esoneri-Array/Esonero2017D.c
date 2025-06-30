/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) interi
 * Pre-condizione: n>=0
 * Output: valore booleano esiste
 * Post-condizione: esiste vale 1 se esiste una tripla di elementi consecutivi della
 					sequenza tale che la somma o il prodotto dei primi due è pari al valore
 					del terzo elemento, 0 altrimenti

 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

/* Funzione che riceve come parametro un array di interi e la sua lunghezza
 * e restituisce se esiste una tripla di elementi consecutivi della
 * sequenza tale che la somma o il prodotto dei primi due è pari al valore
 * del terzo elemento, 0 altrimenti */
int sommaProdotto(int seq[], int lung);

/* Funzione principale */
int main(){
	int dimensione;			// Dimensione array
	int i;					// Per scandire la sequenza
	int esiste;

	/* INPUT dimensione */
	printf("\nQuanti interi devo leggere?\n");
	scanf("%d", &dimensione);
	printf("\n");

	int array[dimensione];	// Dichiaro la sequenza di interi
	/* INPUT valori */
	for(i=0; i<dimensione; i++){
		printf("Elemento della sequenza di indice %d ha valore: ", i);
		scanf("%d", &array[i]);
	}

	esiste=sommaProdotto(array, dimensione);
	/* OUTPUT */
	if(esiste){
		printf("\nEsiste una tripla di elementi di elementi consecutivi in cui\n");
		printf("la somma o il prodotto dei primi due %c pari al valore del terzo.\n", 138);
	}
	else{
		printf("\nNon esiste tripla di elementi di elementi consecutivi in cui\n");
		printf("la somma o il prodotto dei primi due %c pari al valore del terzo.\n", 138);
	}
}

int sommaProdotto(int seq[], int lung){
	int verifica=0;	// Valore booleano
	int i;			// Per scandire i cicli for

	/* Sfoglio l'array */
	for(i=0; i<lung-2 && !verifica; i++){
		/* Controllo se la somma o il prodotto dei primi due elementi di una tripla
		 * è pari al valore del terzo elemento */
		if(seq[i]+seq[i+1]==seq[i+2] || seq[i]*seq[i+1]==seq[i+2]){
			/* Cambio il valore di verità della variabile booleano */
			verifica=1;
		}
	}
	return verifica;			// Valore di ritorno
}

