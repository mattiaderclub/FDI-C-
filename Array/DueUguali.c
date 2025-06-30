#include <stdio.h>

/*Scrivere un programma che legge una sequenza di interi introdotta dall'utente
 *e stampa un messaggio che indica se tale sequenza contiene due numeri uguali oppure no.
 *Utilizzare una funzione che riceve come parametro un array di interi e restituisce
 *1 oppure 0 se la sequenza contiene due numeri uguali oppure no.*/

int controllo(int interi[], int lung){
	int dueUguali=0;
	int ultimoNumero;
	int i;
	for(i=0; i<lung; i++){
		ultimoNumero = interi[i];
		for(i=i+1; i<lung; i++){
			if(ultimoNumero==interi[i])
				return dueUguali=1;
			else
				dueUguali=0;
		}
	}
	return dueUguali;
}

int main(){
	int dimensione;
	int i;

	printf("\nUtente, scegli la dimensione della sequenza: ");
	scanf("%d", &dimensione);
	printf("\n");

	int sequenza[dimensione];

	for(i=0; i<dimensione; i++){
		printf("Dammi un valore: ");
		scanf("%d", &sequenza[i]);
	}

	printf("\nAll'interno della sequenza ci sono due numeri uguali? %d\n", controllo(sequenza, dimensione));

}
