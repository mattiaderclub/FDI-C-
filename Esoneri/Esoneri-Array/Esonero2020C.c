#include <stdio.h>

/* Programma che data una sequenza di n interi verifica se esiste una tripla di elementi
 * consecutivi tali che la loro somma sia un quadrato perfetto.
 * Esempio di istanza positiva: [7,4,5,2]
 * Esempio di istanza negativa: [9,3,2,-3]

/* SPECIFICA
 * Input: n, (x1, x2, ..., xn) interi
 * Pre-condizione: n>=0
 * Output: valore booleano sommaQuadrato
 * Post-condizione: sommaQuadrato vale 1 se esiste un tripla di elementi consecutivi
 					tali che la loro somma è un quadrato perfetto, 0 altrimenti

 * TIPO DI PROBLEMA: verifica esistenziale
 */

/* Funzione ausialiaria */
int quadratoPerfetto(int seq[], int n);

int main(){
	int dimensione;			//dimensione array
	int i;					//contatore cicli for
	int sommaQuadrato;
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

	sommaQuadrato=quadratoPerfetto(array, dimensione);
	/* OUTPUT: stampa in base al valore assunto da sommaQuadrato */
	if(sommaQuadrato){
		printf("\nEsiste una tripla di consecutivi tali che la loro somma %c un quadrato perfetto.\n", 138);
	}
	else{
		printf("\nNon esiste una tripla di consecutivi tali che la loro somma %c un quadrato perfetto.\n", 138);
	}
}

int quadratoPerfetto(int seq[], int n){
	//pre: n>=0 e sequenza di interi
	int esiste=0;			//valore booleano
	int somma;				//per memorizzare somma elementi tripla
	int j, i;				//contatori cicli

	/* Ciclo for per controllo array interi */
	for(i=0; i<n-2 && !esiste; i++){
		somma=seq[i]+seq[i+1]+seq[i+2];
		j=0;				//ogni volta che viene rimemorizzato il valore somma
							//j riparte da 0 prima del while
		
		/* ciclo while che si arresta non appena si supera il valore somma
		 * o non appena esiste una tripla che verifica la proprietà */
		while(j*j<=somma && !esiste){
			if(j*j==somma){
				esiste=1;
			}
			else{
				j++;
			}
		}
	}
	return esiste;			//valore di ritorno
}