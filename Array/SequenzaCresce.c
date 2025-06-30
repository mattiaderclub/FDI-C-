#include <stdio.h>

/* Scrivere un programma che legge una sequenza di interi introdotta 
dall'utente e stampa un messaggio che indica se tale sequenza è crescente 
oppure no. Utilizzare una funzione che riceve come parametro un array di 
interi e restituisce 1 oppure 0 se la sequenza è crescente oppure no.*/

/*Funzione che controlla la crescenza dell'array*/
int cresce(int array[], int l){
	int controllo=1;		//valore booleano
	int i;

	/*Controllo se la sequenza è crescente*/
	for(i=0; i<l-1; i++){
		if(array[i]>=array[i+1])
			return controllo=0;
		else
			controllo=1;
	}
	return controllo;		//tipo di ritorno
}

int main(){
	int dimensione;
	int i;

	/*INPUT DIMENSIONE*/
	printf("\nDimensione: ");
	scanf("%d", &dimensione);
	printf("\n");

	int sequenza[dimensione];	//dichiaro l'array dopo 
								//aver memorizzato la lunghezza

	/*INPUT VALORI*/
	for(i=0; i<dimensione; i++){
		printf("Aggiungi un valore alla sequenza: ");
		scanf("%d", &sequenza[i]);
	}

	/*OUTPUT*/
	printf("\nLa sequenza %c crescente?", 138);
	if(cresce(sequenza, dimensione))
		printf(" SI'\n");
	else
		printf(" NO\n");
}