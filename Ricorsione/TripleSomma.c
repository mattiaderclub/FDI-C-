#include <stdio.h>
/* Applicazione della ricorsione che legge una sequenza di interi e determina se ogni tre
 * elementi consecutivi del vettore sono tali che uno è pari alla somma degli atri due */
/* Funzione di supporto */
int sommaTriple(int s[], int n);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e determina\n");
	printf("se ogni tripla di elementi consecutivi uno %c pari alla somma degli altri due.\n", 138);
	int lunghezza;				// Numero degli elementi dell'array
	printf("\nIntroduci la dimensione del vettore: ");
	scanf("%d", &lunghezza);
	printf("\n");

	/* Dichiaro array e assegno i valori ai suoi elementi */
	int array[lunghezza];
	for (int i = 0; i < lunghezza; i++) {
		printf("Indice %d, aggiungi un valore: ", i);
		scanf("%d", &array[i]);
	}

	/* Output */
	printf("\nNell'array {");
	for (int j = 0; j < lunghezza-1; j++)
		printf("%d,", array[j]);
	printf("%d} ", array[lunghezza-1]);
	
	if(sommaTriple(array, lunghezza))
		printf("ogni tripla di consecutivi %c tale che un elemento %c pari alla somma degli altri due.\n", 138, 138);
	else
		printf("esiste almeno una tripla di consecutivi che non soddisfa la propriet%c.\n", 133);
}

/* Funzione che riceve come parametri una sequenza di interi e una lunghezza.
 * Controlla se in ogni tripla di consecutivi esiste un elementi pari alla somma
 * degli altri due sfruttando il meccanismo della ricorsione */
int sommaTriple(int s[], int n) {
	int ris;

	if (n<3)
		/* Passo base: se ho meno di due elementi 
		 * essendo verifica universale ritorno true */
		ris = 1;
	else {
		/* Passo ricorsivo: controllo se viene soddisfatta la proprietà e torno indietro */
		ris = ((s[n-1] == s[n-2] + s[n-3]) || (s[n-2] == s[n-1] + s[n-3]) || 
				(s[n-3] == s[n-1] + s[n-2])) && sommaTriple(s, n-1);
	}
	return ris;		// Valore di ritorno
}
