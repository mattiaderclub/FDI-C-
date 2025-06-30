#include <stdio.h>

/* Programma che che legge un intero n introdotto dall'utente e crea 
 * una matrice con n righe i cui elementi sotto alla diagonale principale 
 * (compresa) sono quelli del triangolo di Tartaglia.

 * Dopo aver stampato la matrice, la ristampa come una scala e infine
 * la ristampa come un triangolo isoscele
 * Esempio: per n=6 l'output stampato è il seguente:

 *		1    0    0    0    0    0			1
 *		1    1    0    0    0    0			1 	1
 *		1    2    1    0    0    0 			1 	2 	1
 *		1    3    3    1    0    0 			1 	3 	3 	1
 *		1    4    6    4    1    0 			1 	4 	6 	4 	1
 *		1    5    10   10   5    1 			1 	5 	10 	10 	5 	1
 *
 *						1
 *		             1     1
 *		          1     2     1
 *		       1     3     3     1
 *		    1     4     6     4     1
 *		 1     5     10    10    5     1
 *
 */
int main(){
	int righe, colonne;			// dimensioni matrice
	int i, j;					// contatori cicli
	/* Input: dimensione*/
	printf("\nIntroduci la dimensione della tua matrice: ");
	scanf("%d", &righe);
	printf("Stamper%c Tartaglia in 3 diversi formati.\n\n", 162);
	// matrice quadrata
	colonne=righe;
	// dichiarazione matrice
	int tartaglia[righe][colonne];

	/* Elementi sopra la diagonale uguali a 0 */
	for(i=0; i<righe; i++){
		for(j=i+1; j<colonne; j++){
			tartaglia[i][j]=0;
		}
	}

	/* Assegnazione altri valori non nulli */
	for(i=0; i<righe; i++){
		for(j=0; j<=i; j++){		// j non supera a i perchè dopo
									// è presente 0 (guarda ciclo precedente)
			if(i==j || j==0){		// controllo indice j per assegnare il valore
				tartaglia[i][j]=1;	// 1 memorizzato sulla diagonale e sulla prima colonna
			}
			else{
				/* L'elemento di posto i,j è pari alla somma dei due elementi che gli 
				 * stanno sopra (uno sulla sua colonna, l'altro sulla sua diagonale) */
				tartaglia[i][j]=tartaglia[i-1][j-1]+tartaglia[i-1][j];
			}
		}
	}
	/* Output di stampa nei 3 formati: matrice, scala, triangolo isoscele */
	printf("Matrice:\n\n");
	// Stampa in formato matrice
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++){
			printf("%4d",tartaglia[i][j]);
		}
		printf("\n");
	}
	printf("\nScala:\n\n");
	// Stampa in formato scala
	for(i=0; i<righe; i++){
		for(j=0; j<=i; j++){		//Non stampa valori sopra la diagonale principale
			printf("%4d",tartaglia[i][j]);
		}
		printf("\n");
	}
	printf("\nTriangolo isoscele:\n\n");
	// Stampa in formato triangolo isoscele
	for(i=0; i<righe; i++) {
		/* su una riga devi lasciare un numero iniziale di spazi bianchi pari a 
		 * 3 x (n-i-1) -- scelta di visualizzare ciascun numero con 3 caratteri */
		for(j=1; j<=colonne-i-1; j++) 
			printf("%3c", ' ');
		/* ora visualizza i caratteri */
		for(j=0; j<=i; j++) {
			printf("%-3d", tartaglia[i][j]);
			/* fra un carattere e l'altro lascia 3 spazi bianchi */
			if(j<i)
				printf("%3c", ' ');
		}
		printf("\n");
	}

}