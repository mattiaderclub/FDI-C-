/* Applicazione della ricorsione che legge una sequenza di interi da tastiera e conta attraverso una funzione ricorsiva 
 * quante coppie di interi adiacenti uguali sono presenti nell'array. Ad esempio, l'istanza [1, 1, 2, 3, 3, 3, 3] 
 * del problema ha soluzione 4, in quanto fra le coppie di interi adiacenti nell'array (ovvero [1, 1], [1, 2], [2, 3], [3, 3],
 * [3, 3], [3, 3]) ce ne sono 4 composte fra interi tra loro uguali. */

#include <stdio.h>
#include <stdlib.h>

/* Dichiarazione funzioni di supporto */
int numeroCoppieUguali(int s[], int lung);
void leggiDaBin(int s[], int lung);
void salvaSuBin(int s[], int lung);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e conta il numero di coppie di interi");
	printf("\nadiacenti uguali all'interno della sequenza sfruttando il meccanismo della ricorsione.\n");

	/* Input dimensione */
	int dim;
	printf("\nNumero di elementi dell'array : ");
	scanf("%d", &dim);
	printf("\n");

	/* Input valori array */
	int sequenza[dim];
	for (int i = 0; i < dim; i++) {
		printf("Elemento di posto %d = ", i);
		scanf("%d", &sequenza[i]);
	}
	/* Memorizzo numero di coppie contate dalla funzione invocata in una variabile */
	int quante = numeroCoppieUguali(sequenza, dim);

	/* Output */
	printf("\nAll'interno della sequenza (");
	for (int j = 0; j < dim - 1; j++)
		printf("%d,", sequenza[j]);
	printf("%d) si contano %d coppie di interi adiacenti uguali.\n", sequenza[dim-1], quante);

	/* Salvataggio su file */
	salvaSuBin(sequenza, dim);
	/* Chiusura programma */
	printf("Chiusura programma...\n");
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione ricorsiva che riceve due parametri : una sequenza di interi e la sua lunghezza. Conta quante sono le coppie
 * di interi consecutivi uguali all'interno della sequenza */
int numeroCoppieUguali(int s[], int lung) {
	// Lung è la lunghezza dell'array
	int conta = 0;			// Variabile che conta il numero di coppie

	/* Passo base */
	if (lung < 2)
		conta = 0;
	/* Passo ricorsivo */
	else {
		conta = (s[lung-1] == s[lung-2]) + numeroCoppieUguali(s, lung-1);
	}
	return conta;			// Valore di ritorno
}

/* Funzione che legge il contenuto di un file binario e lo scrive in una sequenza */
void leggiDaBin(int s[], int lung) {
	/* Apro file in lettura */
	FILE *leggi = fopen("CoppieUguali.dat", "rb");

	/* Controllo apertura del file */
	if (salva == NULL)
		printf("\nFile inesistente...\n");
	else {
		int numero; 		// Variabile d'appoggio per la lettura

		/* Leggo dal file gli interi memorizzati */
		for (int i = 0; i < lung; i++) {
			fread(&numero, sizeof(int), 1, leggi);
			s[i] = numero;
		}
		printf("\nLettura effettuata correttamente...\n");
		/* Chiusura del file */
		fclose(leggi);
	}
}

/* Funzione che salva una sequenza di interi su un file binario */
void salvaSuBin(int s[], int lung) {
	/* Apro file binario in scrittura */
	FILE *salva = fopen("CoppieUguali.dat", "wb");

	/* Controllo apertura del file */
	if (salva == NULL)
		printf("\nApertura file fallita...\n");
	else {
		/* Scrivo sul file gli interi della sequenza */
		for (int i = 0; i < lung; i++)
			fwrite(&s[i], sizeof(int), 1, salva);
		printf("\nSalvataggio effettuato correttamente...\n");
		/* Chiudo il file */
		fclose(salva);
	}
}