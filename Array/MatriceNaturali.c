#include <stdio.h>

/*Programma che legge due interi r e c introdotti dall'utente
 *(dimensioni di una matrice) e crea una matrice r * c che contiene 
 *tutti i numeri  naturali da 1 fino a r * c, in ordine crescente 
 *da 1 a c sulla prima riga, poi da c+1 a 2c sulla seconda riga, etc. 

 *Esempio: per r=2 e c=8 il programma stampa
 *
 *			1   2   3   4   5   6   7   8
 *			9  10  11  12  13  14  15  16
 */

int main(){

	int righe;
	int colonne;
	int i, j;		//contatori cicli
	int numeroAssegnato=1;		//variabile stampata

	/* Input: dimensioni */
	printf("\nScegli le dimensioni della tua matrice.\n");
	printf("Quante righe deve avere la matrice? ");
	scanf("%d", &righe);
	printf("Quante colonne deve avere la matrice? ");
	scanf("%d", &colonne);
	//Dichiaro matrice
	int matrice[righe][colonne];
	printf("Stampo la matrice di tipo (%d,%d).\n\n", righe, colonne);

	/* Assegnazione valori */
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++ ){
			matrice[i][j]=numeroAssegnato;	//memorizzazione valori
			numeroAssegnato++;				//incremento numero naturale
		}
	}
	/* Output */
	//Stampa i numeri naturali da 1 a (righe*colonne)
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++ ){
			printf("%3d", matrice[i][j]);	//istruzione di stampa
		}
		printf("\n");
	}
}