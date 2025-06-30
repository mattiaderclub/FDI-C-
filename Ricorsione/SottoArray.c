#include <stdio.h>
/* Applicazione della ricorsione che sfrutta una funzione per sfogliare due vettori V1 e V2 di dimensione N1 e N2.
 * Pre-condizioni: 1 <= N2 <= N1.
 * La funzione restituisce 1 se V2 è contenuto in V1 in ordine inverso
 * non necessariamente con i suoi elementi consecutivi, 0 altrimenti */
/* Funzione di supporto */
int sottoArray(int s1[], int s2[], int lung1, int lung2);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente sono un programma che legge due array da tastiera e controlla\n");
	printf("se il secondo %c contenuto nel primo sfruttando il meccanismo di ricorsione.\n");
	int n1, n2;			// Dimensioni array
	printf("Introduci la dimensione del 1%c vettore: ", 167);
	scanf("%d", &n1);
	printf("Introduci la dimensione del 2%c vettore: ", 167);
	scanf("%d", &n2);

	/* Controllo delle dimensioni inserite in input */
	while((n1<1 || n2<1) || n1<n2){
		printf("Pre: ->  N1 >= N2 && N1>0 && N2>0  <-\n\n");
		printf("Introduci la dimensione del 1%c vettore: ", 167);
		scanf("%d", &n1);
		printf("Introduci la dimensione del 2%c vettore: ", 167);
		scanf("%d", &n2);
	}
	printf("\n");

	/* Dichiaro i due vettori */
	int vettore1[n1];
	int vettore2[n2];

	/* Riempio il primo vettore */
	for(int i=0; i<n1; i++){
		printf("Nuovo elemento del 1%c vettore di indice %d = ", 167, i);
		scanf("%d", &vettore1[i]);
	}
	printf("\n");
	/* Riempio il secondo vettore */
	for(int j=0; j<n2; j++){
		printf("Nuovo elemento del 2%c vettore di indice %d = ", 167, j);
		scanf("%d", &vettore2[j]); 
	}

	/* Output */
	if(sottoArray(vettore1, vettore2, n1, n2)==n2)
		printf("\nIl secondo vettore %c contenuto nel primo.\n", 138);
	else
		printf("\nIl secondo vettore non %c contenuto nel primo.\n", 138);
}

/* Funzione che controlla due vettori e controlla se il secondo è contenuto nel primo */
int sottoArray(int s1[], int s2[], int lung1, int lung2){
	int contenuto;

	if((lung1==0 && contenuto!=lung2) || (lung2==0 && contenuto==lung2)){
		contenuto = 0;
	}
	else{
		if(s1[0]==s2[lung2-1])
			contenuto = 1 + sottoArray(s1+1, s2, lung1-1, lung2-1);
		else
			contenuto = 0 + sottoArray(s1+1, s2, lung1-1, lung2);
	}
	return contenuto;
}
