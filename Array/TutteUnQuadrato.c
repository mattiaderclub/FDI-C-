/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) sequenza di interi
 * Pre-condizione: n>=0
 * Output: valore booleano tutteQuad
 * Post-condizione: tutteQuad vale 1 se tutte le triple di interi consecutivi della
 					sequenza sono tali che uno degli elementi della tripla sia il
 					quadrato di uno tra gli altri due elementi, 0 altrimenti

 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

int tutteUnQuadrato(int seq[], int lung);

/* Funzione principale */
int main(){
	int dimensione;			// Dimensione array
	int i;					// Per scandire sequenza
	int tutteQuad;			// Variabile booleana (output)

	/* INPUT */
	printf("\nQuanti numeri devo leggere?\n");
	scanf("%d", &dimensione);
	printf("\n");
	// Dichiaro sequenza di interi
	int interi[dimensione];
	/* Ciclo per inserire valori nell'array */
	for(i=0; i<dimensione; i++){
		printf("E0lemento della sequenza di indice %d ha valore ", i);
		scanf("%d", &interi[i]);
	}
	tutteQuad=tutteUnQuadrato(interi, dimensione);	// Assegno a variabile booleana
													// valore in uscita dalla funzione
	/* OUTPUT */
	if(tutteQuad){
		printf("\nTutte le triple di consecutivi hanno un elemento che %c al quadrato\n", 138);
		printf("di uno degli altri due elementi.\n");
	}
	else{
		printf("\nEsiste una tripla di consecutivi tali che non esiste elemento\n");
		printf("che rispetta la propriet%c.\n", 133);
	}

}

/* Funzione che riceve un array di interi e la sua lunghezza e restituisce un
 * valore booleano diverso a seconda del verificarsi o meno di una condizione */
int tutteUnQuadrato(int seq[], int lung){
	// Dichiarazione variabili
	// Pre: lung>=0
	int tutte=1;				// Valore booleano (di ritorno)
	int i;						// Per scandire l'array

	/* Ciclo for per "sfogliare" l'array */ // Lung-2 in quanto controllo triple di consecutivi
	for(i=0; i<lung-2 && tutte; i++){
		/* Uno degli elementi della tripla è pari al quadrato di uno degli altri due? */
		if(!((seq[i]==seq[i+1]*seq[i+1] || seq[i]==seq[i+2]*seq[i+2]) ||
			(seq[i+1]==seq[i]*seq[i] || seq[i+1]==seq[i+2]*seq[i+2]) ||
			(seq[i+2]==seq[i+1]*seq[i+1] || seq[i+2]==seq[i]*seq[i]))){

			tutte=0;				// Se non si verifica cambio il valore di verità
		}
	}
	return tutte;	
}