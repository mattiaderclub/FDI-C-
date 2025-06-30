#include <stdio.h>

/* Realizzare un programma che consiste di tre funzioni.

La funzione main legge una sequenza di interi introdotta dall'utente 
(prima di leggere tale sequenza chiede all'utente di quanti numeri consiste la sequenza). 
La funzione main invoca quindi la funzione esistePositivo che verifica se, fra gli interi 
della sequenza, ce n'è almeno uno positivo. Nel caso tale intero positivo non esista, 
viene stampato un messaggio che informa l'utente che non esiste nessun intero positivo. 
Nel caso tale intero positivo esista, viene invocata una funzione positivoMinimo che calcola 
e restituisce l'intero positivo più piccolo fra quelli della sequenza; la funzione main stampa 
quindi tale intero.

*/

/* Funzioni di supporto */
int esistePositivo();
int positivoMinimo();

int main(){
	int lunghezza;			//dimensione array
	int i, j;				//variabili contatore per cicli
	/* Input: dimensione */
	printf("\nDi quanti numeri consiste la sequenza? ");
	scanf("%d", &lunghezza);
	printf("\n");

	// Dichiaro array e inserisco valori da tastiera
	int sequenza[lunghezza];
	for(i=0; i<lunghezza; i++){
		printf("Elemento di indice %d ha valore ", i);
		scanf("%d", &sequenza[i]);
	}
	printf("\n");
	if(esistePositivo(sequenza, lunghezza)){
		printf("L'intero positivo pi%c piccolo della sequenza %c %d.\n", 151, 138, positivoMinimo(sequenza, lunghezza));
	}
	else
		printf("Non esiste nessun numero positivo all'interno della sequenza.\n");
}

/* La funzione esistePositivo riceve come parametro un array di interi, la sua lunghezza e 
restituisce 1 se la sequenza contiene almeno un intero positivo, 0 altrimenti. */
int esistePositivo(int array[], int n){
	int i;
	int esiste=0;
	for(i=0; i<n; i++){
		if(array[i]>0){
			return esiste=1;
		}
	}
	return esiste;
}
/* La funzione positivoMinimo riceve come parametro un array di interi, nel quale si assume 
sia presente almeno un intero positivo, la sua lunghezza e restituisce il valore del più 
piccolo intero positivo nella sequenza. */
int positivoMinimo(int array[], int n){
	int i;
	int minimo;
	int positivo=0;
	i=0;
	while(!positivo && i<n){
		if(array[i]>0){
			positivo=1;
			minimo=array[i];
		}
		else
			i++;
	}
	for(i++; i<n; i++){
		if(array[i]>0 && array[i]<minimo){
			minimo=array[i];
		}
	}
	return minimo;
}