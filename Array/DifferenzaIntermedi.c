/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) sequenza di interi
 * Pre-condizione: n>=0
 * Output: valore booleano esiste
 * Post-condizione: esiste vale 1 se esiste una tripla di consecutivi nella sequenza tale
 					che il valore dell' elemento intermedio è pari alla differenza tra il
 					suo precedente e il suo successivo o viceversa, 0 altrimenti

 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

/* Funzione ausiliaria */
int differenzaIntermedi(int seq[], int lung);

/* Funzione principale */
int main(){
	int lunghezza;			// Dimensione array
	int i;					// Per scandire sequenza
	int esiste;				// Variabile booleana (output)

	/* INPUT */
	printf("\nQuanti numeri devo leggere?\n");
	scanf("%d", &lunghezza);
	printf("\n");
	// Dichiaro sequenza di interi
	int interi[lunghezza];
	/* Ciclo per inserire valori nell'array */
	for(i=0; i<lunghezza; i++){
		printf("Elemento della sequenza di indice %d ha valore ", i);
		scanf("%d", &interi[i]);
	}

	/* Memorizzo il valore di ritorno della funzione (richiamandola) nel valore
	 * booleano che riceverò in output attraverso una funzione di stampa*/
	esiste=differenzaIntermedi(interi, lunghezza);
	/* OUTPUT */
	if(esiste){
		printf("\nEsiste una tripla di consecutivi della sequenza tale che la differenza\n");
		printf("tra il primo e il terzo elemento o viceversa %c pari al valore del secondo\n", 138);
	}
	else{
		printf("\nNon esiste una tripla di consecutivi che verifica la propriet%c\n", 133);
	}
}

/* Funzione che verifica se esiste una tripla di consecutivi nella sequenza tale
 * che il valore dell' elemento intermedio è pari alla differenza tra il suo
 * precedente e il suo successivo o viceversa */
int differenzaIntermedi(int seq[], int lung){
	// Pre: lung>=0
	int ugualeDiff=0;			// Variabile booleana inizializzata a falso
	int i;						// Contatore per scandire sequenza

	/* "Sfoglio" l'array */
	for(i=0; i<lung-2 && !ugualeDiff; i++){
		/* L'elemento intermedio della tripla è pari alla differenza tra il primo
		 * e il terzo o tra il terzo e il primo elemento??*/
		if(seq[i+1]==seq[i]-seq[i+2] || seq[i+1]==seq[i+2]-seq[i])
			ugualeDiff=1;		// Se sì cambio il valore della variabile booleana
	}
	return ugualeDiff;			// Valore di ritorno

}