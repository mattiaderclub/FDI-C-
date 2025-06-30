#include <stdio.h>

/* Programma che data una sequenza di interi verifica se per ogni tripla di elementi
 * adiacenti la somma del primo e del secondo elemento della tripla è uguale al terzo.
 * Esempio di istanza positiva: [6,4,10,14,24]
 * Esempio di istanza negativa: [7,5,12,4]

/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) interi
 * Pre-condizione: n>=0
 * Output: valore booleano sommaTerzo
 * Post-condizione: sommaTerzo vale 1 se per ogni tripla di elementi consecutivi
 					della sequenza la somma del primo e del secondo elemento
 					è uguale al terzo, 0 altrimenti

 * TIPO DI PROBLEMA: verifica universale
 */

/* Funzione ausiliaria */
int verificaSequenza(int seq[], int n);

int main(){
	int dimensione;			//dimensione array
	int i;					//contatore cicli for
	int sommaTerzo;
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

	sommaTerzo=verificaSequenza(array, dimensione);
	/* OUTPUT: stampa in base al valore assunto da sommaQuadrato */
	if(sommaTerzo){
		printf("\nPer ogni tripla di elementi consecutivi della sequenza la somma\n");
		printf("dei primi due elementi %c uguale al terzo elemento.\n", 138);
	}
	else{
		printf("\nEsiste almeno una tripla di elementi consecutivi della sequenza per i quali\n");
		printf("la somma dei primi due elementi %c uguale al terzo elemento.\n", 138);
	}
}

int verificaSequenza(int seq[], int n){
	int tutte=1;		//valore booleano

	/* Ciclo for per controllo array interi */
	for(int j=0; j<n-2 && tutte; j++){

		// Controllo proprietà tripla
		if(seq[j]+seq[j+1]!=seq[j+2]){
			tutte=0;	//tutte assume valore negativo (falso)
						//se non si verifica proprietà
		}
	}
	return tutte;		//valore di ritorno
}