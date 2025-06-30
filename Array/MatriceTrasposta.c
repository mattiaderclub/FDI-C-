#include <stdio.h>

/* Realizzare un programma che legge una matrice M di interi introdotta 
 * dall'utente (prima di leggere gli elementi di tale matrice chiede all'utente 
 * il numero di righe ed il numero di colonne della matrice). Il programma 
 * crea quindi la matrice trasposta M^T della matrice M, ovvero la matrice 
 * ottenuta da M scambiando le righe con le colonne. Il programma stampa quindi 
 * la matrice M^T e stampa inoltre un messaggio che indica se la matrice M 
 * è simmetrica (ovvero se è uguale alla sua matrice trasposta). */

/* Oltre alla funzione main, si possono definire a piacimento funzioni, 
 * ad esempio per il calcolo della matrice trasposta, per la stampa 
 * di una matrice, per la verifica se due matrici sono uguali... */

int main(){
	int righe, colonne;
	int i, j;
	int simmetrica=1;

	printf("\nIntroduci le dimensioni della matrice M.\n");
	printf("Quante righe deve avere la matrice? ");
	scanf("%d", &righe);
	printf("Quante colonne deve avere la matrice? ");
	scanf("%d", &colonne);
	printf("\n");

	int matrice[righe][colonne];
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++){
			printf("Elemento della matrice M di riga %d e colonna %d: ", i, j);
			scanf("%d", &matrice[i][j]);
		}
		printf("\n");
	}

	int trasposta[colonne][righe];
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++){
			trasposta[j][i]=matrice[i][j];
		}
	}

	printf("La matrice M %c la seguente:\n\n", 138);
	for(i=0; i<righe; i++){
		for(j=0; j<colonne; j++){
			printf("%3d", matrice[i][j]);
		}
		printf("\n");
	}

	printf("\nLa trasposta della matrice M %c la matrice seguente:\n\n", 138);
	for(i=0; i<colonne; i++){
		for(j=0; j<righe; j++){
			printf("%3d", trasposta[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<righe && simmetrica; i++){
		for(j=0; j<colonne && simmetrica; j++){
			if(matrice[i][j]!=trasposta[i][j]){
				simmetrica=0;
			}
		}
	}

	if(simmetrica && righe==colonne)
		printf("\nLa matrice M %c simmetrica\n", 138);
	else if(!simmetrica)
		printf("\nLe matrice M non %c simmetrica\n", 138);
	else if(righe!=colonne)
		printf("\nLa matrice non puo' essere simmetrica\n");
}