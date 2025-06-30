/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0, (x1, x2, ..., xn) sequenza di interi
 * Output: valore booleano esiste
 * Post-condizione: esiste vale 1 se è presente nella sequenza di interi una tripla
 					di interi consecutivi che contiene esattamente due interi dispari,
 					0 altrimenti

 * TIPO DI PROBLEMA : verifica esistenziale */

#include <stdio.h>

/* Esonero 2019 C */

/* Funzione ausiliaria */
int tripleDueDisp(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	int dimensione;			// Dimensione array
	int i;					// Contatore
	int esiste;				// Variabile booleana
	printf("\nCiao utente, sono un programma che legge un array di interi e restitusice\n");
	printf("un valore booleano tra 1 e 0 se esiste o meno almeno una tripla di interi consecutivi\n");
	printf("che contiene esattamente due interi dispari.\n\n");
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
	 * all'interno della variabile esiste */
	esiste = tripleDueDisp(array, dimensione);

	/* Output */
	if(esiste)
		printf("Esiste una tripla che soddisfa la propriet%c.\n", 133);
	else
		printf("Non esiste una tripla che soddisfa la propriet%c.\n", 133);
}

int tripleDueDisp(int seq[], int lung){
	int i;					// Contatore
	int dueDisp = 0;		// Variabile booleana

	/* Controllo l'array fino al terzultimo elemento (controllo le triple) */
	for(i=0; i<lung-2 && !dueDisp; i++){
		/* Sono presenti all'interno della tripla esattamente due interi dispari? */
		if((seq[i]%2!=0 && seq[i+1]%2!=0 && seq[i+2]%2==0) ||
			(seq[i]%2!=0 && seq[i+1]%2==0 && seq[i+2]%2!=0) ||
			(seq[i]%2==0 && seq[i+1]%2!=0 && seq[i+2]%2!=0)){
			dueDisp = 1;
		}
	}
	return dueDisp;			// Valore di ritorno
}

