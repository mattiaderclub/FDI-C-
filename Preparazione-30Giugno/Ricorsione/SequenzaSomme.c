/* Applicazione della ricorsione che nel main legge una sequenza di interi da tastiera e, attraverso
 * una funzione ricorsiva, verifica se all'interno dell'array ricevuto come parametro ogni tripla
 * di elementi consecutivi la somma del primo e del secondo elemento è uguale al valore del terzo. */

#include <stdio.h>

/* Dichiarazione delle funzioni secondarie */
int sommaPrimiDue(int s[], int lung);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e indica se per ogni tripla");
	printf("\ndi consecutivi la somma del primo e del secondo %c uguale al valore del terzo.\n", 138);

	/* Input */
	int n;
	printf("\nNumero elementi dell'array : ");
	scanf("%d", &n);
	printf("Scrivi %d elementi\n\n", n);

	/* Dichiaro l'array e effettuo la lettura dei suoi elementi */
	int array[n];
	for (int i = 0; i < n; i++) {
		printf("Elemento di posto %d = ", i);
		scanf("%d", &array[i]);
	}

	/* Chiamo la funzione ricorsiva e assegno il valore ritornato a una variabile intera */
	int tutte = sommaPrimiDue(array, n);

	/* Output */
	if (tutte)
		printf("\nPer ogni tripla di consecutivi la somma del primo e del secondo elemento %c uguale al valore del terzo.\n", 138);
	else
		printf("\nEsiste almeno una tripla di consecutivi per cui la somma dei primi due elementi non %c uguale al terzo.\n", 138);
	/* Chiudo il programma */
	printf("\nChiusura del programma...\n");
}

/* Definizione funzioni secondarie */

/* Funzione che riceve un array di interi e la sua lunghezza come parametro e verifica se per ogni tripla di
 * elementi adiacenti la somma dei primi due elementi è pari al valore del terzo elemento */
 int sommaPrimiDue(int s[], int lung) {
 	int ris;			// Variabile booleana

 	/* Passo base */
 	if (lung < 3)
 		ris = 1;
 	/* Passo ricorsivo */
 	else
 		ris = (s[lung-2] + s[lung-3] == s[lung-1]) && sommaPrimiDue(s, lung - 1);
 	return ris;			// Valore di ritorno
 }