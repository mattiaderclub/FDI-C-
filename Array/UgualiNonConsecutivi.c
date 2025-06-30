#include <stdio.h>

/*Scrivere un programma che legge una sequenza di interi introdotta 
dall'utente e stampa un messaggio che indica se tale sequenza contiene 
due numeri uguali oppure no. Utilizzare una funzione che riceve come 
parametro un array di interi e restituisce  1 oppure 0 se la sequenza 
contiene due numeri uguali oppure no.*/

/*Funzione che controlla se due numeri della 
sequenza (non consecutivi) sono uguali o no*/
int dueUguali(int array[], int dim){
	int i, j;
	int controllo=0;

	for(i=0; i<dim-1; i++){
		for(j=i+1; j<dim; j++){
			if(array[i]==array[j])
				return controllo=1;
			else
				controllo=0;
		}
	}
	return controllo;
}

/*Applicazione funzione*/
int main(){
	int lunghezza;
	int i;

	printf("\nLunghezza array: ");
	scanf("%d", &lunghezza);
	printf("\n");
	int numeri[lunghezza];

	for(i=0; i<lunghezza; i++){
		printf("Nuovo numero: ");
		scanf("%d", &numeri[i]);
	}

	printf("\nCi sta una coppia di numeri uguali ");
	printf("all'interno della sequenza?\n");
	if(dueUguali(numeri, lunghezza))
		printf("SI'");
	else
		printf("NO");
	printf("\n");

}