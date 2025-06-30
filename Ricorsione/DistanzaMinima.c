#include <stdio.h>
/* Applicazione della ricorsione che legge da tastiera una sequenza di interi e determina
 * la minima distanza fra due interi consecutivi della sequenza utilizzando una sequenza
 * ricorsiva. La distanza fra due interi è data dal massimo meno il minimo tra i due */
/* Funzione di supporto */
int distanzaMin(int s[], int n);
int massimo(int val1, int val2);
int minimo(int val1, int val2);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e restituisce\n");
	printf("in output la distanza minima tra due interi consecutivi della sequenza.\n");
	int lunghezza;
	printf("\nDa quanti interi %c composta la sequenza?\n", 138);
	scanf("%d", &lunghezza);

	/* Controllo della dimensione inserita in input */
	while(lunghezza<2){
		printf("Pre: ->  Lunghezza >= 2  <-\n");
		printf("Re-introduci la dimensione del vettore: ");
		scanf("%d", &lunghezza);
	}
	printf("\n");

	/* Dichiaro l'array e assegno i valori agli elementi della sequenza */
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Nel posto di indice %d memorizzo il numero ", i);
		scanf("%d", &sequenza[i]);
	}

	/* Output */
	printf("\nLa distanza minima tra due interi consecutivi dell'array {");
	for(int j=0; j<lunghezza-1; j++){
		printf("%d,", sequenza[j]);
	}
	printf("%d} %c %d.\n", sequenza[lunghezza-1], 138, distanzaMin(sequenza, lunghezza));
}

/* Funzione che riceve in input una sequenza di interi e la sua lunghezza.
 * Sfrutta la ricorsione.
 * Ritorna il valore della distanza minima tra due interi consecutivi */
/* Sfrutta le funzioni massimo e minimo per il calcolo delle distanza */
int distanzaMin(int s[], int n){
	int minDistanza = (massimo(s[n-1], s[n-2]) - minimo(s[n-1], s[n-2])); // Inizializzo il minimo

	if(n<2){
		/* Passo base: rimangono due elementi dell'array da leggere
		 * Calcolo la distanza tra il massimo e il minimo e controlla 
		 * se è più piccola del valore minimo */
		if(minDistanza > massimo(s[1], s[0]) - minimo(s[1], s[0]))
			minDistanza = massimo(s[1], s[0]) - minimo(s[1], s[0]);
	}
	else{
		/* Passo induttivo: calcolo della differenza tra il più grande
		 * e il più piccolo richiamando le funzioni e controllo se il valore
		 * è più piccolo del minimo */
		if(minDistanza > distanzaMin(s, n-1))
			minDistanza = distanzaMin(s, n-1);
	}
	return minDistanza;
}

/* Funzione che riceve due valori della sequenza e ne ritorna il massimo tra i due */
int massimo(int val1, int val2){
	int max = val1;
	if(val2>val1)
		max = val2;
	return max;
}

/* Funzione che riceve due valori della sequenza e ne ritorna il massimo tra i due */
int minimo(int val1, int val2){
	int min = val1;
	if(val2<val1)
		min = val2;
	return min;
}