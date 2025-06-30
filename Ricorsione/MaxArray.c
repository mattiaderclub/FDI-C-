#include <stdio.h>
/* Applicazione della ricorsione che legge una sequenza
 * di interi e ne restituisce il massimo della sequenza */
/* Funzione di supporto */
int maxArray(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un array di interi e\n");
	printf("controlla i suoi elementi per restituirne il massimo.\n");
	int dimensione;
	printf("Da quanti interi %c composta la sequenza? ", 138);
	scanf("%d", &dimensione);
	printf("\n");

	while(dimensione<=0){
		printf("Introduci un valore dimensione positivo: ");
		scanf("%d", &dimensione);
	}

	/* Dichiaro array e assegno valori agli elementi del vettore */
	int array[dimensione];
	for(int i=0; i<dimensione; i++){
		printf("Nuovo elemento di indice %d = ", i);
		scanf("%d", &array[i]);
	}

	/* Output */
	printf("\nIl valore massimo del vettore %c %d.\n", 138, maxArray(array, dimensione));
}

/* Funzione che riceve come parametri un array e la sua lunghezza.
 * Restituisce il valore massimo della sequenza di interi */
int maxArray(int seq[], int lung){
	int max = seq[lung-1];

	if(lung==1){
		if(max<seq[0])
			max = seq[0];
	}
	else{
		if(max<maxArray(seq, lung-1))
			max = maxArray(seq, lung-1);
	}
	return max;
}