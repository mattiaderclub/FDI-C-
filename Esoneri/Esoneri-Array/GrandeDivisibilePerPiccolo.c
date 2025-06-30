/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0 (n è la lunghezza della sequenza), (x1, x2, ..., xn) sequenza di interi
 * Output: valore booleano tutte
 * Post-condizione: tutte vale 1 se per ogni tripla di elementi adiacenti nella sequenza, il più
 					grande elemento della tripla è divisibile per il più piccolo, 0 altrimenti

 * TIPO DI PROBLEMA: Verifica universale */

#include <stdio.h>

/* Funzioni di supporto */
int grandeDivisibilePerPiccolo(int seq[], int n);
int minimo(int a, int b, int c);
int massimo(int a, int b, int c);

/* Funzione principale */
int main(){
	/* Input */
	int lunghezza;			// Lunghezza array
	int i;					// Contatore
	int tutte;				// variabile booleana
	printf("\nCioa utente, sono un programma che legge un array da tastiera\n");
	printf("e restituisce 1 o 0 a seconda che la sequenza soddisfi la propriet%c.\n", 133);
	printf("\nintroduci intanto la lunghezza della sequenza: ");
	scanf("%d", &lunghezza);
	printf("\n");
	int interi[lunghezza];	// Sequenza interi

	/* Input valori array */
	for(i=0; i<lunghezza; i++){
		printf("Nuovo elemento della sequenza di indice %d: ", i);
		scanf("%d", &interi[i]);
	}

	/* Invoca la funzione e memorizza il valore di ritorno nella variabile booleana */
	tutte = grandeDivisibilePerPiccolo(interi, lunghezza);

	/* Output */
	if(tutte)
		printf("\nPer ogni tripla di consecutivi il piu' grande elemento della tripla %c divisibile per il piu' piccolo.\n", 138);
	else
		printf("\nEsiste almeno una tripla di consecutivi per cui il piu' grande elemento della tripla non %c divisibile per il piu' piccolo.\n", 138);
}

/* Funzione che riceve come parametri un array di interi e la sua lunghezza e
 * restituisce 1 se per ogni tripla di consecutivi il più piccolo elemento della
 * tripla divide il più grande, 0 altrimenti */
int grandeDivisibilePerPiccolo(int seq[], int n){
	// Pre: n>=0 e seq[] è sequenza di interi
	int i;					// Contatore
	int divisibile = 1;		// Variabile booleana

	/* Vai avanti nella sequenza fino al terzultimo elemento 
	 * (devo controllare le triple di consecutivi) */
	for(i=0; i<n-2 && divisibile; i++){
		/* Il più grande è divisibile per il più piccolo? */
		/* Mi aiuto invocando due funzioni massimo e minimo di 3 interi */
		if(!(massimo(seq[i], seq[i+1], seq[i+2])%minimo(seq[i], seq[i+1], seq[i+2])==0))
			divisibile = 0;
	}
	return divisibile;			// Valore di ritorno
}

/* Funzione che calcola il minimo tra 3 interi */
int minimo(int a, int b, int c){
	int min = a;
	if(b<min)
		min = b;
	if(c<min)
		min = c;
	return min;
}

/* Funzione che calcola il massimo tra 3 interi */
int massimo(int a, int b, int c){
	int max = a;
	if(b>max)
		max = b;
	if(c>max)
		max = c;
	return max;
}
