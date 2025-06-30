#include <stdio.h>

/*Funzione di supporto*/
int minimoN(int n, int a);

/*Programma che senza utilizzare array legge un intero
 *n e utilizza una funzione per calcolare il minimo
 *tra gli n interi inseriti in input dall'utente*/
int main(){
	/*INPUT: quantità interi e primo valore*/
	int quanti, primo_valore;
	printf("\nQuanti valori vuoi che controlli: ");
	scanf("%d", &quanti);
	printf("Dammi un primo valore: ");
	scanf("%d", &primo_valore);		//serve a inizializzare minimo
	/*OUTPUT*/
	printf("Minimo: %d\n\n", minimoN(quanti,primo_valore));
}

/*Funzione che riceve un intero n e un valore a
 *e dopo aver letto n-1 interi ne restituisce il minimo*/
int minimoN(int n, int a){
	//Variabili
	int x, minimo;
	minimo=a;		//inizializzazione
	/*INPUT: valori*/
	for(int j=2; j<=n; j++){
		printf("Nuovo valore: ");
		scanf("%d", &x);
		//Controllo minimo
		if(x<minimo)
			minimo=x;
	}
	return minimo;
}