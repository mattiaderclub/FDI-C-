#include <stdio.h>
/* Applicazione della ricorsione che legge una sequenza di interi e
 * calcola la somma massima di tre interi consecutivi nella sequenza */
/* Funzione ausiliaria */
int maxSomma(int s[], int n);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e\n");
	printf("calcola la somma massima di tre interi consecutivi nella sequenza.\n");
	int lunghezza;
	printf("\nIntroduci la lunghezza della sequenza: ");
	scanf("%d", &lunghezza);
	printf("\n");

	/* Dichiaro array e assegno i valori ai suoi elementi */
	int interi[lunghezza];
	for (int i = 0; i < lunghezza; i++) {
		printf("Indice %d, memorizzo il numero ", i);
		scanf("%d", &interi[i]);
	}

	/* Output */
	printf("\nNell'array {");
	for (int j = 0; j < lunghezza-1; j++) {
		printf("%d,", interi[j]);
	}
	printf("%d} ", interi[lunghezza-1]);

	printf("la somma massima tra tre elementi adiacenti %d.\n", maxSomma(interi, lunghezza));
}

/* Funzione che riceve come parametri una sequenza di interi e la sua lunghezza.
 * Sfrutta la ricorsione per calcola la somma massima di una tripla di consecutivi nell'array */
int maxSomma(int s[], int n) {

	int maxS = s[n-1] + s[n-2] + s[n-3];

	if (n<3) {
		maxS = 0;
	}
	else if (n==3) {
		/* Passo base: ho l'ultima tripla da controllare o la sequenza ha meno di 4 elementi */
		if (maxS < s[0] + s[1] + s[2])
			maxS = s[0] + s[1] + s[2];
	}
	else {
		/* Passo ricorsivo: controllo se la somma della tripla supera il massimo */
		/* Se sì memorizzo il nuovo massimo */
		if (maxS < maxSomma(s, n-1))
			maxS = maxSomma(s, n-1);
	}
	return maxS;
}