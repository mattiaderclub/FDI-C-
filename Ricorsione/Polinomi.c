#include <stdio.h>

float potenza(float base, int esp);
float polinomio(int seq[], int lung, float x);

int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge i coefficienti di un polinomio in una variabile e\n");
	printf("calcola il valore del polinomio per un certo valore della variabile inserito dall'utente.\n\n");
	int lunghezza;			// Numero di elementi dell'array
	printf("Quanti coefficienti ha il polinomio? ");
	scanf("%d", &lunghezza);
	
	/* Assegno i valori all'array */
	int array[lunghezza];
	printf("\n");
	for(int i=0; i<lunghezza; i++) {
		printf("coefficiente del polinomio di indice %d: ", i);
		scanf("%d", &array[i]);
	}

	float variabile;
	printf("\nVariabile del polinomio: ");
	scanf("%f", &variabile);

	/* Output */
	float risultato = polinomio(array, lunghezza, variabile);
	printf("\nIl valore del polinomio per la variabile %f %c %f", variabile, 138, risultato);
	
}

float potenza(float base, int esp){
	int ris;

	if(esp==0)
		ris = 1;
	else
		ris = base * potenza(base, esp-1);
	return ris;
}

float polinomio(int seq[], int grado, float x){
	int somma = 0;
	
	if(grado==0){
		somma = 0;
	}
	else{
		somma = seq[grado-1] * potenza(x, grado-1) + polinomio(seq, grado-1, x);
	}
	return somma;
}


