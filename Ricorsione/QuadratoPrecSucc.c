#include <stdio.h>
/* Applicazione della ricorsione che legge una sequenza di interi e verifica se nella
 * sequenza esiste un elemento che è pari al quadrato del precedente o del successivo */
/* Funzione ausiliaria */
int esisteQuadrato(int s[], int n);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e verifica\n");
	printf("l'esistenza di un elemento pari al quadrato del suo precedente o successivo.\n");
	int lunghezza;
	printf("\nNumero elementi dell'array: ");
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

	if(esisteQuadrato(interi, lunghezza))
		printf("esiste un elemento pari al quadrato del precedente o del successivo.\n");
	else
		printf("non esiste un elemento che verifica la propriet%c.\n", 133);
}

/* Funzione che riceve in input due parametri: una sequenza di interi e la sua lunghezza.
 * Sfrutta la ricorsione per verifica l'esistenza di un elementi pari al quadrato
 * del precedente o del successivo */
int esisteQuadrato(int s[], int n) {
	int esiste;

	if (n < 2)
		esiste = 0;
	else if (n == 2) 
		esiste = (s[0] == s[1]*s[1] || s[1] == s[0]*s[0]);
	else {
		esiste = ((s[n-2] == s[n-3]*s[n-3]) || (s[n-2] == s[n-1]*s[n-1])) || 
					esisteQuadrato(s, n-1);
	}
	return esiste;
}
