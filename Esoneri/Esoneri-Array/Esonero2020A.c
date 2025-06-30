/* Programma che data una sequenza di interi verifica se esiste un elemento
 * nella sequenza che è il quadrato del successivo o del precedente.
 * Esempio di istanza positiva: [7,4,2-3] o [-3,9,2,3]
 * Esempio di istanza negativa: [7,5,12,4]

/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) sequenza di interi
 * Pre-condizione: n>=0
 * Output: valore booleano esisteElQuadrato
 * Post-condizione: esisteElQuadrato vale 1 se esiste un elemento nella
 					sequenza che è il quadrato dell' elemento successivo
 					o di quello precedente, 0 altrimenti

 * TIPO DI PROBLEMA: verifica esistenziale */
#include <stdio.h>

/* Funzione ausiliaria */
int quadratoPrecSucc(int seq[], int lung);

int main(){
	int lunghezza;			//lunghezza array
	int i;					//contatore cicli for

	/* INPUT: dimensione */
	printf("\nQuanti interi devo leggere?\n");
	scanf("%d", &lunghezza);
	printf("\n");
	// Dichiarazione sequenza interi
	int interi[lunghezza];
	/* INPUT: interi */
	for(i=0; i<lunghezza; i++){
		printf("Elemento della sequenza di indirizzo %d e indice %d: ", &interi[i], i);
		scanf("%d", &interi[i]);
	}
	printf("\n");

	/* OUTPUT */
	if(quadratoPrecSucc(interi, lunghezza))
		printf("Esiste un elemento che %c il quadrato del precedente o del successivo.\n", 138);
	else
		printf("Non esiste elemento nella sequenza che soddisfa la propriet%c.\n", 133);
}

int quadratoPrecSucc(int seq[], int lung){
	//pre: lung>=0
	int esiste=0;			//valore booleano
	int i;
	/* Ciclo for per controllare la sequenza di interi.
	 * i parte da 1 in quanto il primo elemento dell'array 
	 * (i=0) non ha un elemento precedente da controllare */
	for(i=1; i<lung-1 && !esiste; i++){
		// Controllo: elemento è quadrato del precedente o del successivo
		if(seq[i]==seq[i+1]*seq[i+1] || seq[i]==seq[i+2]*seq[i+2]){
			esiste=1;
		}
	}
	return esiste;			//valore di ritorno
}