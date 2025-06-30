#include <stdio.h>

/* Programma che legge le dimensioni e i valori di due matrici di 
 * elementi di tipo int e calcola e visualizza la matrice prodotto. */

int main(){
	int righe1, colonne1;		//dimensioni matrice A
	int righe2, colonne2;		//dimensioni matrice B
	int i, j, k;				//variabili contatori per sfogliare matrici
	/* Input: dimensioni */
	printf("\nIntroduci le dimensioni delle due matrici.\n");
	printf("Numero righe matrice A: ");
	scanf("%d", &righe1);
	printf("Numero colonne matrice A: ");
	scanf("%d", &colonne1);
	righe2=colonne1;	//in questo modo le matrici sono conformabili
						//aggiungere condizioni prodotto prossimamente
	printf("La matrice B ha %d righe. Quante colonne ha? ", colonne1);
	scanf("%d", &colonne2);
	printf("\n");
	//Dichiaro le matrici
	int matriceA[righe1][colonne1];
	int matriceB[righe2][colonne2];
	int prodotto[righe1][colonne2];

	/* Input: valori */
	//Matrice A
	for(i=0; i<righe1; i++){
		for(j=0; j<colonne1; j++){
			printf("Elemento della matrice A in riga %d e colonna %d: ", i, j);
			scanf("%4d", &matriceA[i][j]);
		}
		printf("\n");
	}
	//Matrice B
	for(i=0; i<righe2; i++){
		for(j=0; j<colonne2; j++){
			printf("Elemento della matrice B in riga %d e colonna %d: ", i, j);
			scanf("%4d", &matriceB[i][j]);
		}
		printf("\n");
	}
	/* Calcolo prodotto tra le matrici */
	/* Con il primo for mi sposto tra le righe di A (e matrice prodotto), con il secondo
	 * tra le colonne di B (e matrice prodotto) mentre con il terzo mi muovo in entrambe
	 * le dimensioni associando correttamente i valori da moltiplicare che si vanno poi
	 * a sommare tra loro.*/
	/* I primi due for servono anche a selezionare la posizione per il nuovo elemento
	 * della matrice prodotto.*/
	for(i=0; i<righe1; i++){
		for(k=0; k<colonne2; k++){
			/*L'elemento con indici i,k è pari al prodotto scalare
			fra la riga della matrice A e la colonna della matrice B*/ 
			prodotto[i][k]=0;
			for(j=0; j<colonne1; j++){
				/*Eseguo il prodotto scalare e grazie a j ogni passo iterativo
				mi sposto sia sulla riga(i) di A sia sulla colonna(k) di B*/
				prodotto[i][k]+=matriceA[i][j]*matriceB[j][k];
			}
		}
	}

	/* Output: matrici */
	printf("Adesso stamper%c il prodotto tra la matrice A\n\n", 162);
	//Stampa matrice A
	for(i=0; i<righe1; i++){
		for(j=0; j<colonne1; j++){
			printf("%4d", matriceA[i][j]);
		}
		printf("\n");
	}

	printf("\ne la matrice B\n\n");
	//Stampa matrice B
	for(i=0; i<righe2; i++){
		for(j=0; j<colonne2; j++){
			printf("%4d", matriceB[i][j]);
		}
		printf("\n");
	}

	printf("\nMatrice prodotto:\n\n");
	//Stampa matrice Prodotto
	for(i=0; i<righe1; i++){
		for(j=0; j<colonne2; j++){
			printf("%4d", prodotto[i][j]);
		}
		printf("\n");
	}
}