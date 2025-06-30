#include <stdio.h>

/*Programma che legge i valori di un array bidimensionale 
 *di elementi di tipo int e lo visualizza in forma matriciale, 
 *assumendo che i numeri introdotti abbiano al massimo 3 cifre.*/

int main(){
	int righe, colonne;		//dimensioni matrice
	int i, j;				//variabili contatore
	/*INPUT: dimensione*/
	printf("\nIntroduci le dimensioni della matrice.\n");
	printf("Numero righe: ");
	scanf("%d", &righe);
	printf("Numero colonne: ");
	scanf("%d", &colonne);
	printf("\n");
	//Dichiaro array bidimensionale
	int matrice[righe][colonne];

	/*INPUT: valori*/
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++){
			printf("Elemento della matrice in riga %d e colonna %d: ", i, j);
			scanf("%3d", &matrice[i][j]);	//%3d serve a considerare solo le
											//prime 3 cifre inserite in output
		}
		printf("\n");
	}
	/*OUTPUT: stampa matrice*/
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++){
			printf("%5d", matrice[i][j]);
		}
		printf("\n");
	}
}