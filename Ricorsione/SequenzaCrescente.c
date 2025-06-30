#include <stdio.h>

/* Funzione di supporto */
int crescente(int interi[], int l);
int decrescente(int interi[], int l);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una sequenza di interi e controlla\n");
	printf("se la funzione %c crescente o decrescente sfruttando il meccanismo di ricorsione.\n", 138);
	int dimensione;
	printf("\nDimensione sequenza: ");
	scanf("%d", &dimensione);

	/* Dichiaro a assegno i valori agli elementi dell'array */
	int sequenza[dimensione];
	for(int i=0; i<dimensione; i++){
		printf("Intero di indice %d della sequenza = ", i);
		scanf("%d", &sequenza[i]);
	}

	/* Output */
	printf("\nLa sequenza di interi (");
	for(int j=0; j<dimensione-1; j++){
		printf("%d,", sequenza[j]);
	}
	printf("%d) ", sequenza[dimensione-1]);

	if(crescente(sequenza, dimensione))
		printf("%c crescente.\n", 138);
	else if(decrescente(sequenza, dimensione))
		printf("%c decrescente.\n", 138);
	else
		printf("non %c n%c crescente n%c decrescente.\n", 138, 138, 138);
}
/* Funzione che riceve come parametri un array di interi e la sua lunghezza.
 * Controlla se la funzione è crescente */
int crescente(int interi[], int l){
	int cresce;

	if(l<2)
		cresce = 1;
	else
		cresce = ((interi[0]<interi[1]) && crescente(interi+1, l-1));
	return cresce;
}
/* Funzione che riceve come parametri un array di interi e la sua lunghezza.
 * Controlla se la funzione è decrescente */
int decrescente(int interi[], int l){
	int decresce;

	if(l<2)
		decresce = 1;
	else
		decresce = ((interi[0]>interi[1]) && decrescente(interi+1, l-1));
	return decresce;
}