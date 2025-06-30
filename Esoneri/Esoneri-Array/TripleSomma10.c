/* SPECIFICA
 * Input: n, (x1, x2, ...,xn)
 * Pre-condizione: n>=0, (x1, x2, ...,xn) sequenza di interi
 * Output: valore booleano tutte
 * Post-condizione: tutte vale 1 se tutte le triple di interi consecutivi nella sequenza 
       				contengono due interi la cui somma è 10, 0 altrimenti

 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>
/* Esonero 2018 A
/* Funzioni di supporto */
int tripleSomma10(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	int i;				// Contatore per scandire ciclo for
	int tutte;			// Variabile booleana
	printf("\nCiao utente, sono un programma che legge un array di interi da tastiera e restituisce\n");
	printf("1 o 0 se ogni tripla di consecutivi contiene due interi la cui somma %c uguale a 10.\n", 138);
	int dimensione;		// Lunghezza array
	printf("\nIntroduci la dimensione della sequenza da leggere: ");
	scanf("%d", &dimensione);
	printf("\n");

	/* Input valori array */
	int interi[dimensione];			// Array di interi
	for(i=0; i<dimensione; i++){
		printf("Elemento di indice %d ha valore: ", i);
		scanf("%d", &interi[i]);
	}

	/* Invoca la funzione e inserisce il valore di ritorno nella variabile booleana */
	tutte = tripleSomma10(interi, dimensione);
	/* Output */
	if(tutte)
		printf("\nOgni tripla contiene due interi la cui somma %c pari a 10.\n", 138);
	else
		printf("\nEsiste almeno una tripla che non contiene due interi la cui somma %c pari a 10.\n", 138);
}

/* Funzione che riceve come parametri un array di interi e la sua lunghezza. Resistuisce un valore booleano
 * positivo se ogni tripla di consecutivi della sequenza contiene due interi la cui somma è 10, negativo altrimenti */
int tripleSomma10(int seq[], int lung){
	int i;						// Contatore
	int somma10 = 1;			// Variabile booleana

	/* Controllo l'array fino al terzultimo elemento in quanto 
	 * ho bisogno di controllare solo le triple di consecutivi */
	for(i=0; i<lung-2 && somma10; i++){
		/* Due interi della tripla sommati fanno 10? */
		if(!(seq[i]+seq[i+1]==10 || seq[i+1]+seq[i+2]==10 || seq[i]+seq[i+2]==10))
			somma10 = 0;
	}
	return somma10;				// Valore di ritorno
}