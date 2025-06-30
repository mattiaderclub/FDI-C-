/* Programma che legge un array di interi e stampa in output la massima somma di tre interi adiacenti nell'array.
 * All'avvio dell'esecuzione del programma l'utente può scegliere se recuperare la sequenza da file o se inserirla da tastiera */

#include <stdio.h>
#include <stdlib.h>

/* Dichiarazione funzioni di supporto */
int sommaMaxTripla(int s[], int l);
int quantiNumeri();
void recupero(int seq[], int lung);
void salvataggio(int seq[], int lung);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e ritorna il valore");
	printf("\ndella massima somma degli elementi di una tripla di elementi consecutivi del vettore\n");

	int recupera;				// Scelta dell'utente
	printf("\nPreferisci recuperare il vettore da file o preferisci inserirlo da tastiera ? ");
	scanf("%d", &recupera);

	/* Recupero da file */
	if (recupera%2 != 0) {
		int lung = quantiNumeri();			// Numero elementi dell'array recuperato da file
		int array[lung];					// Sequenza di interi
		/* Recupero la sequenza da file */
		recupero(array, lung);

		/* Stampo la sequenza recuperata */
		printf("Ho recuperato %d numeri: ");
		for (int i = 0; i < lung; i++) {
			printf("%d ", array[i]);
		}

		/* Output */
		printf("\nSomma massima triple di consecutivi = %d\n", sommaMaxTripla(array, lung));
		/* Salvo su file */
		salvataggio(array, lung);
	}
	/* Inserimento da tastiera */
	else {
		/* Input */
		int dim;
		printf("\nNumero elementi dell'array : ");
		scanf("%d", &dim);
		printf("\n");
		int interi[dim];

		/* Lettura valori array */
		for (int j = 0; j < dim; j++) {
			printf("%d%c valore = ", j, 167);
			scanf("%d", &interi[j]);
		}

		/* Output */
		printf("\nSomma massima triple di consecutivi = %d\n", sommaMaxTripla(interi, dim));
		/* Salvo su file */
		salvataggio(interi, dim);
	}
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione delle funzioni di supporto <----- */

/* Funzione che riceve un array di interi e la sua lunghezza (l) e ritorna il valore della massima somma tra i tre elementi
 * di una tripla di interi consecutivi all'interno della sequenza. La funzione è ricorsiva */
int sommaMaxTripla(int s[], int l) {
	int somma = s[l-1] + s[l-2] + s[l-3];

	/* Passo base */
	if (l < 3)
		somma = 0;
	/* Passo ricorsivo */
	else {
		if (somma < sommaMaxTripla(s, l-1))
			somma = sommaMaxTripla(s, l-1);
	}
	return somma;
}

/* Funzione che apre un file binario in lettura e conta quanti numeri sono salvati all'interno di esso */
int quantiNumeri() {
	int quanti = 0;				// Conta i numeri nel file
	FILE *conta = fopen("MaxSomma.dat", "rb");

	if (conta == NULL)
		printf("\nFile inesistente...\n"); 
	else {
		int numero;				// Appoggio per lettura
		/* Incremento il contatore finchè ho numeri da leggere nel file */

		while (fread(&numero, sizeof(int), 1, conta) > 0)
			quanti++;
		/* Chiusura file di lettura */
		fclose(conta);
	}
	return quanti;				// Valore di ritorno
}

/* Funzione che legge gli interi memorizzati in un file e li inserisce all'interno di un array */
void recupero(int seq[], int lung) {
	FILE *inserisci = fopen("MaxSomma.dat", "rb");

	int numero;				// Appoggio lettura su file
	for (int i = 0; i < lung; i++) {
		/* Leggo un numero dal file e lo memorizzo in ordine nella sequenza */
		fread(&numero, sizeof(int), 1, inserisci);
		seq[i] = numero;
	}
	printf("\nDati recuperati...\n");
	fclose(inserisci);
}

/* Funzione che salva gli interi di un array all'interno di un file */
void salvataggio(int seq[], int lung) {
	FILE *scrivi = fopen("MaxSomma.dat", "wb");

	if (scrivi == NULL)
		printf("\nSalvataggio dati fallito...\n");
	/* File aperto */
	else {
		for (int i = 0; i < lung; i++) {
			/* Scrittura su file */
			fwrite(&seq[i], sizeof(int), 1, scrivi);
		}
		printf("\nSalvataggio effettuato...");
		/* Chiusura file di scrittura */
		fclose(scrivi);
	}
}

