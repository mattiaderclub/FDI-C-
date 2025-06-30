#include <stdio.h>
/* Applicazione della ricorsione che sfrutta una funzione che, dato un numero n,
 * calcola la somma dei primi n numeri pari positivi */
/* Funzione di supporto */
int sommaPari(int n);

/* Funzione principale */

int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un intero da tastiera e sfrutta\n");
	printf("la ricorsione per calcolare la somma dei primi n interi pari positivi.\n");
	int quanti;
	printf("\nDammi un intero: ");
	scanf("%d", &quanti);

	/* Output */
	printf("La somma dei primi %d interi pari positivi %c %d.\n", quanti, 138, sommaPari(quanti));
}

/* Funzione ricorsiva */
int sommaPari(int n){
	int somma;

	// Passo base
	if(n==0)
		somma = 0;
	// Passo ricorsivo
	else
		somma = n*2 + sommaPari(n-1);
	return somma;
}