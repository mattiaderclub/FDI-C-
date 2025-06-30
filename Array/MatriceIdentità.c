#include <stdio.h>

/*Scrivere un programma che legge un valore n e crea 
 *e visualizza la matrice identità di dimensione n.*/

 int main(){
 	int n;			//dimensione matrice
 	int i, j;		//variabile contatore
 	/*INPUT*/
 	//Inserimento dimensione matrice
 	printf("\nDimensione matrice: ");
 	scanf("%d", &n);
 	//Dichiarazione matrice identità
 	int matriceId[n][n];

 	//Memorizzazione valori
 	for(i=0; i<n; i++){
 		for(j=0; j<n; j++){
 			if(i==j){		//se indici uguali allora 
 							//viene memorizzato valore 1
 				matriceId[i][j]=1;
 			}
 			else{
 				matriceId[i][j]=0;
 			}
 		}
 	}
 	/*OUTPUT*/
 	printf("Matrice identit%c di dimensione %d:\n\n", 133, n);
 	//Ciclo stampa matrice
 	for(i=0; i<n; i++){
 		for(j=0; j<n; j++){
 			printf("%d  ", matriceId[i][j]);
		}
		printf("\n");
	}
}