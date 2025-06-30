#include <stdio.h>

/*Scrivere un programma che legge una sequenza di interi introdotta dall'utente e stampa 
 *un messaggio che indica qual è l'elemento che appare più di frequente. Utilizzare due 
 *funzioni: una che riceve come parametro un array di interi, un valore intero e conta il 
 *numero di occorrenze dell'intero nell'array. Un'altra che riceve come parametro un array 
 *di interi e restituisce l'indice del valore dell'array che ha occorrenza massima.*/

/*Funzioni di supporto*/
int frequenzaValore(int seq[], int lung, int numero);
int indiceFrequente(int seq[], int lung);

int main(){
	int dimensione;			//lunghezza sequenza
	int i, j;				//variabili contatore

	/*INPUT*/
	//Inserisco la dimensione dell'array
	printf("\nIntroduci la dimensione del tuo array: ");
	scanf("%d", &dimensione);
	printf("\n");

	//Dichiaro la sequenza ora che è nota la dimensione
	int array[dimensione];
	//Insersco i valori nell'array
	for(i=0; i<dimensione; i++){
		printf("Nuovo valore: ");
		scanf("%d", &array[i]);
	}

	//Dichiarazione variabili per rendere più leggibile il programma
	int indice = indiceFrequente(array, dimensione);
	int conta = frequenzaValore(array, dimensione, array[indice]);

	/*OUTPUT*/
	//Stampo il numero che ha occorrenza massima nella sequenza e quante volte compare
	printf("Il numero che compare piu' volte all'interno della sequenza %c %d.\n", 138, array[indice]);
	printf("Compare %d volte agli indici: ", conta);
	//Stampo anche gli indici in cui compare il valore
	for(i=0; i<dimensione; i++){
		if(array[indice]==array[i])
			printf("%d ", i);
	}
	printf("\n");
}

int frequenzaValore(int seq[], int lung, int numero){
	int contatore=0;
	int i;
	for(i=0; i<lung; i++){
		if(numero==seq[i])
			contatore++;
	}
	return contatore;
}

int indiceFrequente(int seq[], int lung){
	int quanti=1;
	int quantiMax=0;
	int numControllato=seq[0];
	int i, j;
	int indiceFreq;

	for(i=0; i<lung; i++){
		quanti=1;
		numControllato=seq[i];
		for(j=i+1; j<lung; j++){
			if(numControllato==seq[j]){
				quanti++;
			}
		}
		if(quanti>quantiMax){
			quantiMax=quanti;
			indiceFreq=i;
		}
	}
	return indiceFreq;
}