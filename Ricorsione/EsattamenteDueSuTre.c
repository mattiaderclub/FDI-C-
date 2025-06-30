#include <stdio.h>

/* Dichiarazione funzioni di supporto */
int esattamenteDue(int *seq, int lung);

/* Corpo del programma */
int main() {
	int lung;
	printf("\nIntroduci la lunghezza della sequenza : ");
	scanf("%d", &lung);
	printf("\n");

	int array[lung];

	for (int i = 0; i < lung; i++) {
		printf("Nuovo valore : ");
		scanf("%d", &array[i]);
	}
	int tutte = esattamenteDue(array, lung);
	if (tutte)
		printf("\nOgni tripla di elementi adiacenti %c tale che esattamente due elementi della tripla sono positivi.\n", 138);
	else
		printf("\nEsiste almeno una tripla di elementi adiacenti tale che non esistono esattamente due interi positivi al suo interno.\n");
	printf("\nChiusura programma...\n");
}

int esattamenteDue(int *seq, int lung) {
	int ris;

	if (lung <= 2)
		ris = 1;
	else {
		ris = ((seq[lung - 1] > 0 && seq[lung - 2] > 0 && seq[lung - 3] <= 0) ||
				(seq[lung - 1] > 0 && seq[lung - 3] > 0 && seq[lung - 2] <= 0) ||
				(seq[lung - 2] > 0 && seq[lung - 3] > 0 && seq[lung - 1] <= 0)) && esattamenteDue(seq, lung - 1);
	}
	return ris;
}