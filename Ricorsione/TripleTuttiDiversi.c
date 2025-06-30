#include <stdio.h>
/* Applicazione della ricorsione che legge una sequenza di interi e verifica se
 * ogni tripla di interi consecutivi è composta da interi tutti diversi tra loro */
/* Funzione ausiliaria */
int tuttiDiversi(int s[], int n);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e controlla\n");
	printf("se ogni tripla di interi consecutivi contiene interi tutti diversi tra loro.\n");
	int dimensione;
	printf("\nIntroduci la dimensione del vettore: ");
	scanf("%d", &dimensione);
	printf("\n");

	/* Dichiaro array e assegno i valori ai suoi elementi */
	int sequenza[dimensione];
	for (int i = 0; i < dimensione; i++) {
		printf("Indice %d, aggiungi un numero: ", i);
		scanf("%d", &sequenza[i]);
	}

	/* Output */
	printf("\nNell'array {");
	for (int j = 0; j < dimensione-1; j++) {
		printf("%d,", sequenza[j]);
	}
	printf("%d} ", sequenza[dimensione-1]);

	if(tuttiDiversi(sequenza, dimensione))
		printf("ogni tripla di elementi consecutivi contiene tutti elementi diversi tra loro.\n");
	else
		printf("esiste almeno una tripla di elementi consecutivi dove almeno due elementi sono uguali tra loro.\n");
}

/* Funzione che riceve in input una sequenza di interi e la sua lunghezza e sfrutta la ricorsione
 * per controllare se ogni tripla di consecutivi contiene tutti elementi diversi tra loro */
int tuttiDiversi(int s[], int n) {
	// Pre: n>=0
	int ris;			// Variabile booleana

	if (n<3)
		/* Passo base: ho meno di tre elementi quindi torno 1 (verifica universale) */
		ris = 1;
	else {
		/* Passo ricorsivo: verifico la proprietà per la tripla e richiamo la funzione
		 * per controllare la prossima */
		ris = ((s[n-1] != s[n-2]) && (s[n-1] != s[n-3]) && 
				(s[n-2] != s[n-3])) && (tuttiDiversi(s, n-1));
	}
	return ris;			// Valore di ritorno
}