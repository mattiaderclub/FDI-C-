/* Applicazione della ricorsione che nel main legge una sequenza di interi da tastiera e, attraverso
 * una funzione ricorsiva, verifica se all'interno dell'array ricevuto come parametro esiste un elemento
 * che è il cubo dell'elemento precedente o successivo */

#include <stdio.h>

/* Dichiarazione delle funzioni secondarie */
int cuboPrecSucc(int s[], int lung);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e indica se");
	printf("\nesiste un elemento che %c il cubo dell'elemento precedente o successivo.\n", 138);

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
	int esiste = cuboPrecSucc(array, n);

	/* Output */
	if (esiste)
		printf("\nEsiste un elemento nella sequenza che %c il cubo del precedente o del successivo.\n", 138);
	else
		printf("\nNessun elemento nell'array %c il cubo del precedente o del successivo.\n", 138);

	/* Chiudo il programma */
	printf("\nChiusura del programma...\n");
}

/* Definizione funzioni secondarie */

/* Funzione ricorsiva che riceve come parametri una sequenza di interi e la sua lunghezza. Verifica
 * l'esistenza di un elemento che è il cubo dell'elemento precedente o successivo */
int cuboPrecSucc(int s[], int lung) {
	int esiste;				// Variabile booleana

	/* Passo base 1 : ho un solo elemento nella sequenza */
	if (lung < 2)
		esiste = 0;
	/* Passo base 2 : la sequenza è esattamente lunga 2, controllo se uno dei due è cubo dell'altro */
	else if (lung == 2)
		esiste = (s[lung-1] == s[lung-2]*s[lung-2]*s[lung-2] || s[lung-2] == s[lung-1]*s[lung-1]*s[lung-1]);
	/* Passo ricorsivo */
	else
		esiste = (s[lung-2] == s[lung-3]*s[lung-3]*s[lung-3] || s[lung-2] == s[lung-1]*s[lung-1]*s[lung-1]) || cuboPrecSucc(s, lung-1);
	return esiste;			// Valore di ritorno
}