/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0, (x1, x2, ..., xn) sequenza di interi
 * Output: intero almenoMeta
 * Post-condizione: almenoMeta vale 1 se almeno la metà degli interi dell'array
 					sono interi positivi, 0 altrimenti

 * TIPO DI PROBLEMA: Conteggio */

#include <stdio.h>

/* Array 3 */

/* Funzione ausiliaria */
int percentualePos(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	int dimensione;			// Dimensione array
	int i;					// Contatore
	int almenoMeta;			// Variabile booleana
	printf("\nCiao utente, sono un programma che legge un array di interi e restitusice\n");
	printf("un valore booleano tra 1 e 0 se almeno la met%c degli interi della sequenza\n", 133);
	printf("sono interi positivi o meno\n\n");
	printf("Da quanti interi %c composto l'array?\n", 138);
	scanf("%d", &dimensione);
	printf("\n");

	/* Dichiaro l'array di interi e inserisco i valori attraverso un for */
	int array[dimensione];
	for(i=0; i<dimensione; i++){
		printf("Elemento della sequenza di indice %d ha valore: ", i);
		scanf("%d", &array[i]);
	}

	/* Richiamo la funzione e inserisco il valore di ritorno
	 * all'interno della variabile almenoMetà */
	almenoMeta = percentualePos(array, dimensione);

	/* Output */
	if(almenoMeta){
		printf("\nAlmeno la met%c degli interi dell'array ", 133);
		for(i=0; i<dimensione; i++){
			printf("%d ", array[i]);
		}
		printf("sono interi positivi.\n");
	}
	else{
		printf("\nAlmeno la met%c degli interi dell'array ", 133);
		for(i=0; i<dimensione; i++){
			printf("%d ", array[i]);
		}
		printf("non sono interi positivi.\n");
	}
}

int percentualePos(int seq[], int lung){
	int i;				// Per scandire l'array
	int contatore = 0;	// Contatore positivi
	int almenoMeta;		// Variabile booleana
	int metaSequenza = lung/2;

	/* Setto il limite da superare affinchè venga restituito
	 * 1 oppure 0 (valore di ritorno) alla fine del for */
	if(metaSequenza%2!=0)
		metaSequenza++;

	/* Controllo l'intero array fino all'ultimo elemento */
	for(i=0; i<lung; i++){
		if(seq[i]>0)
			contatore++;
	}
	/* Almeno metà degli interi sono positivi? */
	if(contatore>=metaSequenza)
		almenoMeta = 1;
	else
		almenoMeta = 0;

	return almenoMeta;		// Valore di ritorno
}