#include <stdio.h>

/*Scrivere un programma che legge due vettori e ne calcola il prodotto scalare.*/
int main(){
	int dimensione;		//lunghezza array
	int i;				//variabili per cicli
	int somma=0;

	/*INPUT DIMENSIONE ARRAY*/
	printf("\nScegli la dimensione dei vettori: ");
	scanf("%d", &dimensione);
	printf("\n");

	int vettore1[dimensione];	//dichiaro primo vettore
	int vettore2[dimensione];	//dichiaro secondo vettore

	/*INPUT*/
	/*Lettura valori primo vettore*/
	for(i=0; i<dimensione; i++){
		printf("Dammi una nuova coordinata del 1%c vettore: ", 167);
		scanf("%d", &vettore1[i]);
	}
	printf("\n");
	/*Lettura valori secondo vettore*/
	for(i=0; i<dimensione; i++){
		printf("Dammi una nuova coordinata del 2%c vettore: ", 167);
		scanf("%d", &vettore2[i]);
	}

	/*Prodotto scalare*/
	for(i=0; i<dimensione; i++){
		somma+=vettore1[i]*vettore2[i];
	}
	/*OUTPUT*/
	printf("\nProdotto scalare dei 2 vettori = %d.\n", somma);

}