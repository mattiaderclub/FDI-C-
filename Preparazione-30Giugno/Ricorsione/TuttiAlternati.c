#include <stdio.h>
#include <stdlib.h>

/* Dichiarazione funzioni di supporto */
int tuttiAlternati(int *seq, int lunghezza);
int quantiNumeri();
void leggiNumeri(int* sequenza, int lunghezza);
void scriviNumeri(int* sequenza, int lunghezza);

/* Corpo del programma */
int main() {
    int lunghezza; 			// Numero elementi dell'array
	int scelta;				// Scelta dell'utente

    /* Acquisizione dati e lettura dell'array da input */
    printf("\nVuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* Introduzione sequenza da input */
	if(scelta==1) {
		/* Determina la lunghezza della sequenza */
		printf("\nIntroduci la lunghezza della sequenza: ");
		scanf("%d",&lunghezza);

		/* Crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("\nScrivi %d elementi\n",lunghezza);
		for(int i=0;i<lunghezza;i++) {
			printf("\nNuovo valore : ");
			scanf("%d",&array[i]);
		}

		/* Invoca la funzione ricorsiva e stampa il risultato */
		if(tuttiAlternati(array,lunghezza))
			printf("\nPositivi e negativi si alternano\n");
		else
			printf("\nEsiste una coppia di positivi o negativi adiacenti\n");

		/* Salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* Recupero sequenza da file */
	else {
		/* Determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/* Crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("\nEcco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* Invoca la funzione ricorsiva e stampa il risultato */
		if(tuttiAlternati(array,lunghezza))
			printf("\nPositivi e negativi si alternano\n");
		else
			printf("\nEsiste una coppia di positivi o negativi adiacenti\n");

		/* Salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}

/* Funzione ricorsiva che verifica se i numeri positivi e negativi si alternano nella sequenza */
int tuttiAlternati(int *seq, int lunghezza){
	int ris;

	if (lunghezza <= 1)
		ris = 1;
	else {
		ris = ((seq[lunghezza-1] > 0 && seq[lunghezza-2] < 0) || (seq[lunghezza-1] < 0 && seq[lunghezza-2] > 0))
				&& tuttiAlternati(seq, lunghezza-1);
	}
	return ris;
}

/* Funzione che conta quanti numeri sono contenuti in un file binario */
int quantiNumeri() {
	int quanti = 0;
	FILE *conta = fopen("Alternati.dat", "rb");

	if (conta != NULL) {
		int numero;
		while (fread(&numero, sizeof(int), 1, conta) > 0)
			quanti++;
		printf("\nHo letto %d numeri.\n", quanti);
		fclose(conta);
	}
	return quanti;
}

/* Funzione che legge gli interi salvati all'interno di un file e li inserisci in una sequenza */
void leggiNumeri(int* sequenza, int lunghezza) {
	FILE *leggi = fopen("Alternati.dat", "rb");

	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		int numero;
		for (int i = 0; i < lunghezza; i++) {
			fread(&numero, sizeof(int), 1, leggi);
			sequenza[i] = numero;
		}
		printf("\nLettura effettuata...\n");
		fclose(leggi);
	}
}

/* Funzione che scrive gli interi di una sequenza all'interno di un file */
void scriviNumeri(int* sequenza, int lunghezza) {
	FILE *salva = fopen("Alternati.dat", "wb");

	if (salva == NULL)
		printf("\nApertura file non riuscita...\n");
	else {
		for (int i = 0; i < lunghezza; i++)
			fwrite(&sequenza[i], sizeof(int), 1, salva);
		printf("\nSalvataggio effettuato...\n");
		fclose(salva);
	}
}