#include <stdio.h>

/* Funzione di supporto */
int contaPositivi(int seq[], int lung);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un array da tastiera e sfrutta\n");
	printf("una funzione ricorsiva per contare il n umero di interi positivi nella sequenza.\n");
	int dimensione;
	printf("Da quanti interi %c composto l'array? ", 138);
	scanf("%d", &dimensione);
	printf("\n");

	/* Dichiaro l'array e assegno i valori a ogni indice */
	int interi[dimensione];
	for(int i=0; i<dimensione; i++){
		printf("Intero di indice %d della sequenza = ", i);
		scanf("%d", &interi[i]);
	}
	
	/* Output */
	printf("\nL'array (");
	for(int j=0; j<dimensione-1; j++){
		printf("%d,", interi[j]);
	}
	printf("%d) ", interi[dimensione-1]);
	printf("contiene %d interi positivi.\n", contaPositivi(interi, dimensione));
}

/* Funzione che riceve come parametri una sequenza di interi e la sua lunghezza
 * e conta il numero di interi positivi presenti nella sequenza */
int contaPositivi(int seq[], int lung){
	int conta;

	if(lung==0)
		conta = 0;
	else
		conta = (seq[lung-1]>0) + contaPositivi(seq, lung-1);
	return conta;
}