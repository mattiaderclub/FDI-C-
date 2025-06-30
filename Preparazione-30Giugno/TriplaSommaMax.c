#include <stdio.h>

/* Funzioni di supporto */
int sommaMax(int seq[], int l);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e ritorna il valore della somma massima");
	printf("\ndi tre interi adiacenti all'interno dell'array.\n");

	printf("\nIntroduci un numero lunghezza : ");
	int lung;
	scanf("%d", &lung);

	int array[lung];

	for (int i = 0; i < lung; i++) {
		printf("Nuovo valore : ");
		scanf("%d", &array[i]);
	}

	printf("\nSomma massima di triple : %d\n", sommaMax(array, lung));
}

int sommaMax(int seq[], int l) {
	int somma = seq[l-1] + seq[l-2] + seq[l-3];

	if (l < 3)
		somma = 0;
	else {
		if (somma < sommaMax(seq, l-1))
			somma = sommaMax(seq, l-1);
	}
	return somma;
}