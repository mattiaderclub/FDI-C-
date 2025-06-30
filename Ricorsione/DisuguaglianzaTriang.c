/* Applicazione che contiene una funzione ricorsiva che verifica all'interno di un array di intero ricevuto come parametro */

/* Realizzare un'applicazione DisuguaglianzaTriangolare definita come segue :
 * L'applicazione sfrutta la ricorsione per verifica l'esistenza all'interno di un array di interi di una terna di consecutivi che
 * soddisfa la disuguaglianza triangolare (ovvero ciascuno degli interi della terna è minore della somma degli altri due).
 * Ad esempio, se l’array è [2, 4, 10, 7, 1], la funzione deve restituire 1, in quanto la tripla [4, 10, 7] è tale che 4<10+7, 10<4+7 e 7<4+10.
 * Se l’array è [1, 3, 1], la funzione deve restituire 0, poiché nell’unica tripla [1, 3, 1] non è vero che 3<1+1.
 * L'utente sceglie se all'inizio dell'esecuzione leggere gli interi da file o se inserirli lui stesso. 
 * Alla fine dell'esecuzione la sequenza di interi viene salvata su un file. */

#include <stdio.h>
#include <stdlib.h>

/* Dichiarazione funzioni di supporto */
int disuguaglianzaTri(int *seq, int l);
int quantiNumeri();
void leggiNumeri(int *sequenza, int lunghezza);
void scriviNumeri(int *sequenza, int lunghezza);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che sfrutta la ricorsione per verifica all'interno di una sequenza di interi");
	printf("\nl'esistenza di una terna di interi consecutivi che soddisfa la disuguaglianza triangolare (ovvero ciascuno degli interi");
	printf("\n%c minore della somma degli altri due.\n", 138);

	/* Input */
	int scelta;
	printf("\nVuoi leggere da file (introduci un numero pari)");
	printf("\nO inserire per conto tuo gli interi in sequenza (introduci un numero dispari) ?\n");
	scanf("%d", &scelta);

	int lunghezza;						// Numero di elementi dell'array
	/* Se scelta è un intero pari leggi array di interi da file */
	if (scelta%2 == 0) {
		lunghezza = quantiNumeri();		// Numero interi nel file

		/* Input */
		int array[lunghezza];
		leggiNumeri(array, lunghezza);			// Leggi interi

		/* Output */
		if (disuguaglianzaTri(array, lunghezza))
			printf("\nEsiste una terna di consecutivi che verifica la disuguaglianza triangolare.");
		else
			printf("\nNessuna terna di consecutivi verifica la disuguaglianza triangolare.");		
	}
	/* Se è intero dispari inserisci te gli interi in sequenza */
	else {	
		/* Input */
		printf("\nIntroduci la lunghezza della sequenza : ");
		scanf("%d", &lunghezza);
		int interi[lunghezza];					// Sequenza di interi

		/* Lettura degli interi da inserire nella sequenza */
		for (int i = 0; i < lunghezza; i++) {
			printf("Valore di indice %d della sequenza : ", i);
			scanf("%d", &interi[i]);			// Leggi il prossimo elemento
		}
		/* Output */
		if (disuguaglianzaTri(interi, lunghezza))
			printf("\nEsiste una terna di consecutivi che verifica la disuguaglianza triangolare.");
		else
			printf("\nNessuna terna di consecutivi verifica la disuguaglianza triangolare.");

		/* Salva la sequenza su file */
		scriviNumeri(interi, lunghezza);
	}
	/* Output */
	printf("\nChiusura programma...\n");
}

/* Funzione ricorsiva che riceve in input una sequenza di interi e la sua lunghezza e restituisce un intero booleano.
 * Verifica se esiste una tripla di consecutivi della sequenza tale che è verificata la disuguaglianza triangolare :
 * la disuguaglianza triangolare tra 3 numeri è verificata se e solo se ogni numero è minore della somma degli altri 2 */
int disuguaglianzaTri(int *seq, int l) {
	int risultato;				// Per il risultato
	/* Caso base */
	if (l <= 2)
		risultato = 0;
	/* Passo ricorsivo */
	else {
		risultato = ((seq[l-1] < seq[l-2] + seq[l-3]) && (seq[l-2] < seq[l-1] + seq[l-3])
					 && (seq[l-3] < seq[l-2] + seq[l-1])) || disuguaglianzaTri(seq, l - 1);
	}
	return risultato;			// Valore di ritorno
}

/* Funzione che torna il numero di interi letti da file */
int quantiNumeri() {
	/* Apro file testuale in lettura */
	FILE *fpconta = fopen("Interi.txt", "r");

	/* File vuoto */
	if (fpconta == NULL)
		printf("\nApertura file fallita...\n");
	/* Ci stanno interi nel file */
	else {
		int numero;					// Variabile di lettura
		int lunghezza = 0;			// Numero interi contenuti nel file
		/* Leggo finchè non raggiungo la fine del file */
		while (fscanf(fpconta, "%d", &numero) > 0)
			lunghezza++;			// Un numero in più

		/* Non c'è contenuto nel file */
		if (lunghezza == 0)
			printf("\nFile vuoto...\n");

		/* Chiudo file per la lettura */
		fclose(fpconta);
		return lunghezza;			// Valore di ritorno
	}
}

/* Funzione che legge gli interi all'interno di un file e li inserisce in un array */
void leggiNumeri(int *sequenza, int lunghezza) {
	// Nel main in lunghezza abbiamo memorizzato il valore di quantiNumeri
	/* Apro file testuale in lettura */
	FILE *fpin = fopen("Interi.txt", "r");

	/* File non esistente o apertura fallita */
	if (fpin == NULL)
		printf("\nApertura file fallita o file non esistente...\n");
	else {
		/* Leggo tanti interi quanti ce ne sono nel file */
		for (int i = 0; i < lunghezza; i++)
			fscanf(fpin, "%d", &sequenza[i]);		// Leggo intero contenuto nel file
		/* Chiusura file di lettura */
		fclose(fpin);
		printf("\nLettura effettuata...\n");	
	}
}

/* Funzione che salva un array di interi su un file testuale */
void scriviNumeri(int *sequenza, int lunghezza) {
	/* Apro file testuale in scrittura */
	FILE *fpout = fopen("Interi.txt", "w");

	/* Apertura file non riuscita */
	if (fpout == NULL)
		printf("\nApertura file fallita...\n");
	else {
		/* Stampo interi nel file */
		for (int i = 0; i < lunghezza; i++)
			fprintf(fpout, "%d ", sequenza[i]);			// Stampo sequenza nel file
		/* Chiusura file di scrittura */
		fclose(fpout);		// Va chiuso nell'else e non fuori perchè se restituisce
							// NULL significa che il file non è proprio stato aperto
		printf("\nSalvataggio effettuato...\n");	
	}
}
