/* Applicazione della ricorsione che legge una sequenza di interi da tastiera e verifica attraverso una funzione ricorsiva
 * se all'interno dell'array ricevuto come parametro per ogni tripla di elementi consecutivi la somma del primo e del secondo
 * elemento della tripla è uguale alla differenza tra il terzo e il secondo elemento della tripla.
 *
 * Ad esempio, la funzione deve restituire 1 se l'array parametro è [3, 5, 13, 31, 75], in quanto 3+5 = 13-5 per la prima tripla,
 * 5+13 = 31-13 per la seconda e 13+31 = 75-31. Se l'array parametro è [3, 5, 10, 25] la funzione deve resistuire 0 perchè
 * 3+5 != 10-5. */

/* Aggiungere commenti e riscrivere descrizione programma */

#include <stdio.h>

/* Funzioni di supporto */
int uniSommaDiff(int s[], int l);
int esiSommaDiff(int s[], int l);
int quantiNumeri();
void leggiNumeri(int seq[], int n);
void salvaNumeri(int seq[], int n);

/* Corpo del programma */
int main() {
	int scelta;
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e verifica attraverso la ricorsione se");
	printf("\nper ogni tripla di elementi consecutivi della sequenza la somma del primo e del secondo elemento %c uguale", 138);
	printf("\nalla differenza tra il terzo e il secondo elemento della tripla.\n");
	printf("\nVuoi recuperare la sequenza di interi da file o preferisci inserirla da tastiera ? ");
	scanf("%d", &scelta);

	if (scelta %2 == 0) {
		printf("\nRecupero della sequenza in corso...\n");
		int lung = quantiNumeri();

		int interi[lung];
		leggiNumeri(interi, lung);
		printf("\n%d numeri recuperati : (", lung);
		for (int i = 0; i < lung - 1; i++) {
			printf("%d,", interi[i]);
		}
		printf("%d)\n", interi[lung - 1]);

		if (esiSommaDiff(interi, lung)) {
			if (uniSommaDiff(interi, lung))
				printf("\nPer ogni tripla di consecutivi la somma tra il primo e il secondo %c\nuguale alla differenza tra il terzo e il secondo.\n", 138);
			else
				printf("\nEsiste almeno una tripla di consecutivi per cui la somma tra il primo e il secondo %c\nuguale alla differenza tra il terzo e il secondo.\n", 138);
		}
		else {
			printf("\nNessuna tripla di elementi consecutivi della sequenza verifica la propriet%c.\n", 133);
		}
		/* Salvo su file */
		salvaNumeri(interi, lung);
	}
	else {
		int lung;
		printf("\nInserisci un valore lunghezza : ");
		scanf("%d", &lung);
		printf("Scrivi %d interi.\n\n", lung);

		int array[lung];
		for (int j = 0; j < lung; j++) {
			printf("Elemento di posto %d = ", j);
			scanf("%d", &array[j]);
		}
		if (esiSommaDiff(array, lung)) {
			if (uniSommaDiff(array, lung))
				printf("\nPer ogni tripla di consecutivi la somma tra il primo e il secondo %c\nuguale alla differenza tra il terzo e il secondo.\n", 138);
			else
				printf("\nEsiste almeno una tripla di consecutivi per cui la somma tra il primo e il secondo %c\nuguale alla differenza tra il terzo e il secondo.\n", 138);
		}
		else {
			printf("\nNessuna tripla di elementi consecutivi della sequenza verifica la propriet%c.\n", 133);
		}
		/* Salvo su file */
		salvaNumeri(array, lung);
	}
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

int uniSommaDiff(int s[], int l) {
	int ris;

	if (l < 3)
		ris = 1;
	else
		ris = (s[l-3] + s[l-2] == s[l-1] - s[l-2]) && uniSommaDiff(s, l-1);
}

int esiSommaDiff(int s[], int l) {
	int ris;

	if (l < 3)
		ris = 0;
	else
		ris = (s[l-3] + s[l-2] == s[l-1] - s[l-2]) || uniSommaDiff(s, l-1);
}

int quantiNumeri() {
	FILE *conta = fopen("Successione.dat", "rb");
	int quanti = 0;

	if (conta == NULL)
		printf("\nFile inesistente...\n");
	else {
		int numero;
		while (fread(&numero, sizeof(int), 1, conta) > 0)
			quanti++;
		fclose(conta);
	}
	return quanti;
}

void leggiNumeri(int seq[], int n) {
	FILE *leggi = fopen("Successione.dat", "rb");

	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		int numero;
		for (int i = 0; i < n; i++) {
			fread(&numero, sizeof(int), 1, leggi);
			seq[i] = numero;
		}
		printf("\nLettura riuscita...\n");
		fclose(leggi);
	}
}

void salvaNumeri(int seq[], int n) {
	FILE *salva = fopen("Successione.dat", "wb");

	if (salva == NULL)
		printf("\nApertura file fallita...\n");
	else {
		for (int i = 0; i < n; i++)
			fwrite(&seq[i], sizeof(int), 1, salva);
		printf("\nSalvataggio riuscito...\n");
		fclose(salva);
	}
}
