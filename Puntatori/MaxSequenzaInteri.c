#include <stdio.h>
#include <stdlib.h>
/* ESERCITAZIONE 7 */
/* Programma che legge una sequenza di interi da tastiera e calcola e stampa il massimo nella sequenza */

/* Funzioni di supporto da definire */
int massimo(int *sequenza, int lunghezza);

/* Funzione principale */
/* Gestisce l'interazione con l'utente: inizialmente alloca memoria usando una funzione apposita.
 * La quantità di memoria da allocare è decisa dall'utente. Vengono quindi letti gli interi senza
 * chiederne la quantità da introdurre ma se se ne vuole inserire un altro dopo ogni lettura.
 * Se si supera la quantità di memoria allocata, questa può essere incrementata. */
int main(){
	/* Allocazione memoria */
	int *interi = (int *)malloc(10 * (sizeof(int)));

	/* Verifica che l'allocazione sia andata a buon fine */
	if (interi==NULL) {
		printf("\nNon c'%c memoria.\nRIPROVARE.\n", 138);
	}

	/* Allocazione andata a buon fine */
	else {
		/* Input */
		printf("\nCiao utente, sono un programma che legge una sequenza di interi da tastiera,\n");
		printf("calcola e ne stampa il massimo sfruttando la meccanica degli array dinamici.\n");

		/* Lettura elementi dell'array dinamico sfruttando l'interazione computer - utente */
		int i = 0;
		char risposta;
		/* Inserimento interi nell'array dinamico */
		do {
			/* Devo introdurre un altro intero */
			printf("\nHai intenzione di introdurre un intero?\n");			
			printf("N --> NO   |   S --> SI  : ");
			scanf("%c", &risposta);

			/* Introduco il prossimo intero */
			if(risposta != 'N') {
				scanf("%d%*c", interi + i);
				i++;
			}
		}
		while (i < 10 && risposta != 'N');
		
		/* Ho superato la memoria e voglio ancora aggiungere elementi all'array */
		if (i == 10 && risposta != 'N') {
			/* Inserimento variabile di incremento della memoria */
			int upgrade;
			printf("\nNon hai piu' memoria. Di quanto hai intenzione di incrementarla?\n");
			printf("Introduci un intero positivo: ");
			scanf("%d", &upgrade);

			/* Incremento della memoria tramite la funzione realloc */
			interi = (int *)realloc(interi, (10 + upgrade) * (sizeof(int)));

			/* Verifica che l'allocazione sia andata a buon fine */
			if (interi == NULL) {
				printf("\nNon c'%c memoria.\nRIPROVARE.\n");
			}

			/* Allocazione andata a buon fine */
			else {
				while(i < 10 + upgrade) {
					printf("\nNuovo intero = ");
					scanf("%d", interi + i);
					i++;
				}
			}
		}
		/* Output */
		int max = massimo(interi, i);

		printf("\nIl valore massimo dell'array {");
		for(int j = 0; j < i-1; j++) {
			printf("%d,", *(interi + j));
		}
		printf("%d} %c %d.\n", *(interi + (i-1)), 138, max);
	}
	/* Libera l'area di memoria */
	free(interi);
}

/* Funzione che, terminata la lettura della sequenza di interi nel main,
 * calcola e restituisce il massimo della sequenza che verrà poi stampato */
int massimo(int *sequenza, int lunghezza){
	int max = *sequenza;

	/* Controllo l'array fino all'ultimo elemento */
	for(int i = 1; i < lunghezza; i++) {

		/* Verifico se il valore controllato supera il massimo:
		 * in caso affermativo lo memorizzo */
		if (*(sequenza + i) > max)
			max = *(sequenza + i);
	}
	return max;			// Valore di ritorno
}
