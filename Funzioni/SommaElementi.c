#include <stdio.h>

/*Problema di accumulazione*/
/*Funzione di supporto*/
int sommaElementi(int* seq, int l);
/*Programma che legge una sequenza di interi da tastiera e
 *utilizza una funzione per calcolarne la somma degli elementi*/
int main(){
	int lunghezza;		//lunghezza array
	int somma;			//somma elementi array
	
	/*INPUT: dimensione*/
	printf("\nQuanto vuoi che sia lunga la sequenza? ");
	scanf("%d", &lunghezza);
	printf("\n");
	//Dichiaro la sequenza
	int seq[lunghezza];
	/*INPUT: valori*/
	for(int i=0; i<lunghezza; i++){
		printf("Dammi un intero: ");
		scanf("%d", &seq[i]);
	}
	//Assegnazione alla variabile somma
	somma=sommaElementi(seq, lunghezza);
	/*OUTPUT*/
	printf("\nLa somma vale %d\n\n", somma);
}

/*Funzione che restituisce la somma degli elementi della sequenza*/
int sommaElementi(int* seq, int l){
	int s=0;		//variabile somma inizializzata a 0
	for(int i=0; i<=l-1; i++)		//ciclo di accumulazione
		s += seq[i];
	return s;			//dato di ritorno
}
