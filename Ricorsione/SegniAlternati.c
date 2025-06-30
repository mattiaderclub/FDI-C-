#include <stdio.h>

#include <stdio.h>

int segniAlternati(int seq[], int lung);

int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un array di interi\n");
	printf("e sfrutta una funzione ricorsiva per controllare se gli interi\n");
	printf("positivi e negativi si alternano all'interno della sequenza.\n\n");
	int lunghezza;			// Numero di elementi dell'array
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &lunghezza);
	
	/* Assegno i valori all'array */
	int array[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("Intero della sequenza di indice %d: ", i);
		scanf("%d", &array[i]);
	}

	/* Output */
	int tutti = segniAlternati(array, lunghezza);
	if(tutti)
		printf("\nPositivi e negativi si alternano nella sequenza.\n");
	else
		printf("\nEsiste un positivo/negativo seguito da un intero dello stesso segno.\n");

}

int segniAlternati(int seq[], int lung){
	int alterni;

	if(lung<=1)
		alterni = 1;
	else{
		alterni = (((seq[lung-1]>0 && seq[lung-2]<0) || (seq[lung-1]<0 && seq[lung-2]>0)) 
					&& segniAlternati(seq, lung-1));
	}
	return alterni;
}


