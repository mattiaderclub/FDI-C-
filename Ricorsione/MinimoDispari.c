#include <stdio.h>
/* Applicazione della ricorsione che legge una sequenza di interi e verifica se per ogni tripla
 * di elementi consecutivi della sequenza, il minimo fra i tre interi è dispari. */
/* Funzioni di supporto */
int minimoDispari(int s[], int lung);
int minimo(int val1, int val2, int val3);

/* Funzione principale */
int main(){
	printf("\nCiao utente, sono un programma che legge una sequenza di interi\n");
	printf("e verifica se in ogni tripla di consecutivi il minimo tra i tre interi %c dispari.\n", 138);
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

	if(minimoDispari(array, dimensione))
		printf("\nMinimo dispari.\n");
	else
		printf("\nEsiste un minimo non dispari.\n");
}

int minimoDispari(int s[], int lung){
	int esiste;

	if(lung<3)
		esiste = 1;
	else{
		esiste = (minimo(s[lung-1], s[lung-2], s[lung-3])%2!=0) && minimoDispari(s, lung-1); 
	}
	return esiste;
}

/* Funzione che riceve come parametri 3 valori e torna il minimo tra i 3 */
int minimo(int val1, int val2, int val3){
	int min = val1;				// Inizializzo il minimo

	if (val2 < min)
		min = val2;

	if (val3 < min)
		min = val3;

	return min;					// Valore di ritorno
}
