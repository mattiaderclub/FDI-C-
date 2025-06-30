#include <stdio.h>

/* Programma che legge una sequenza di interi introdotta dall'utente e rimpiazza
 * ogni elemento della sequenza con il suo valore assoluto. Stampa quindi la nuova
 * sequenza. Fa uso di due funzioni ma se ne possono definire altre a piacimento */

/* Funzioni di supporto */
void cambiaSegno(int arr[], int n);
int controlloNegativo(int valore);

/* Funzione principale */
int main(){
	int lunghezza;			// Dimensione array
	int i;					// Per scandire la sequenza

	/* INPUT */
	printf("\nDa quanti interi %c composta la tua sequenza?\n", 138);
	scanf("%d", &lunghezza);
	printf("\n");

	// Dichiarazione array
	int sequenza[lunghezza];
	/* INPUT valori */
	for(i=0; i<lunghezza; i++){
		printf("Nuovo valore di posto %d: ", i);
		scanf("%d", &sequenza[i]);
	}

	/* OUTPUT */
	// Stampa prima la sequenza inserita in output
	printf("\nSequenza di partenza: ");
	for(i=0; i<lunghezza; i++){
		printf("%d ", sequenza[i]);
	}
	// Stampa infine la sequenza con i soli valori assoluti
	printf("\nSequenza modificata: ");
	cambiaSegno(sequenza, lunghezza);
	printf("\n");
}

/* Funzione che riceve un array di interi e la sua dimensione e rimpiazza
 * ogni elemento dell'array con il suo valore assoluto. Infine stampa la nuova sequenza*/
void cambiaSegno(int arr[], int n){		// Void: non mi torna alcun valore
	int i;						// Contatore cicli
	int numero;					// Numero controllato
	int nuovaSequenza[n];		// Sequenza valori assoluti	

	/* Controllo l'array */
	for(i=0; i<n; i++){
		numero=arr[i];			// Memorizzo il prossimo elemento della sequenza
		/* Controllo se il numero ha segno negativo richiamando un'altra funzione */
		if(!controlloNegativo(numero)){
			/* Se è negativo, cambio il segno */
			numero=-numero;;
		}
		/* Memorizzo il numero (cambiato o meno) nella nuova sequenza */
		nuovaSequenza[i]=numero;
	}
	/* OUTPUT: stampo la nuova sequenza */
	for(i=0; i<n; i++){
		printf("%d ", nuovaSequenza[i]);
	}
}

/* Funzione che riceve come parametro un numero della sequenza
 * e ritorna 1 se è positivo o nullo, 0 altrimenti */
int controlloNegativo(int valore){
	return (valore>=0);			// Valore booleano di ritorno
}
