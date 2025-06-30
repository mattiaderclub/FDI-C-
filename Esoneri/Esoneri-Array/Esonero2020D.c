#include <stdio.h>

/* Programma che data una sequenza di interi verifica se per ogni tripla
 * di elementi consecutivi la somma del primo e del secondo elemento della
 * tripla è uguale alla differenza tra il terzo e il secondo elemento della
 * tripla.
 * Esempio di istanza positiva del problema: [3,5,13,31,75]
 * Esempio di istanza negativa del problema: [3,5,10,31,75]

/* SPECIFICA
 * Input: n, (x1, x2, ..., xn)
 * Pre-condizione: n>=0 e (x1, x2, ..., xn) interi
 * Output: valore booleano tripleSommaDiff
 * Post-condizione: tripleSommaDiff vale 1 se per ogni tripla di consecutivi
 					la somma del primo e del secondo è pari alla differenza
 					tra il terzo e il secondo, 0 altrimenti

 * TIPO DI PROBLEMA: verifica universale
 */

/* Funzione ausiliaria */
int verificaSuccesione(int seq[], int n);

int main(){
	int dimensione;		//dimensione array
	int i;				//per scandire cicli for
	int tripleSommaDiff;
	/* INPUT: dimensione */
	printf("\nQuanti interi vuoi introdurre?\n");
	scanf("%d", &dimensione);
	printf("\n");

	int array[dimensione];		//dichiarazione sequenza interi
	/* INPUT: interi sequenza */
	for(i=0; i<dimensione; i++){
		printf("L'elemento di indice %d della sequenza ha valore ", i);
		scanf("%d", &array[i]);
	}

	tripleSommaDiff=verificaSuccesione(array, dimensione);
	/* OUTPUT: stampa in base al valore assunto dalla variabile booleana */
	if(tripleSommaDiff){
		printf("\nPer ogni tripla di elementi consecutivi della sequenza la somma\n");
		printf("del primo e del secondo elemento è pari alla differenza tra il terzo e il secondo.\n");
	}
	else{
		printf("\nEsiste almeno una tripla di elementi consecutivi della sequenza dove la somma\n");
		printf("del primo e del secondo elemento è diversa alla differenza tra il terzo e il secondo.\n");
	}
}

int verificaSuccesione(int seq[], int n){
	//pre: n>=0 e sequenza di interi
	int controllo=1;		//valore booleano
	for(int i=0; i<n-2; i++){
		//controllo per assegnare valore (1 o 0) a variabile booleana
		if(seq[i]+seq[i+1]!=seq[i+2]-seq[i+1]){
			return controllo=0;
		}
	}
	return controllo;		//valore di ritorno
}

