#include <stdio.h>

/*Scrivere un programma che legge una sequenza di interi introdotta dall'utente 
e stampa un messaggio che indica se tale sequenza è crescente oppure no.
Utilizzare una funzione che riceve come parametro un array di interi e restituisce 
1 oppure 0 se la sequenza è crescente oppure no.*/

int crescente(int interi[], int lung){
	int j;
	int cresce=1;
	int ultimoNumero;
	ultimoNumero=interi[0];
	for(j=1; j<lung; j++){
		if(interi[j]>ultimoNumero){
			cresce = 1;
			ultimoNumero = interi[j];
		}
		else
			return cresce = 0;
	}
	return cresce;
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
	printf("\nLa sequenza %c crescente? %d\n", 138, crescente(sequenza, dimensione));

}