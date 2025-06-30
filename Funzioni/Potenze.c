#include <stdio.h>

/*Funzione di supporto*/
int potenze(int a, int b);

/*Programma per il calcolo di potenze a esponente positivo*/
int main(){
	/*INPUT: base ed esponente*/
	float base; 
	int esponente;
	printf("\nBase: ");
	scanf("%7.2f", &base);
	printf("Esponente: ");
	scanf("%d", &esponente);
	/*IF: esponente dev'essere non negativo*/
	if(esponente>=0){
		/*OUTPUT*/
		if(esponente==0 && base==0){
			printf("\nForma indeterminata!\n\n");
		}
		else{
			printf("\nIl risultato della potenza ");
			printf("%c %f\n\n", 138, potenze(base,esponente));
		}
	}
	else
		printf("Esponente negativo!\n\n");
}

/*Funzione che dati 2 interi base(a) e esponente(b) restituisce 
 *il risultato della potenza con base a ed esponente b*/
float potenze(float a, int b){
	//b>=0
	int risultato=1;			//dichiarazione con inizializzazione
	for(int j=1; j<=b; j++){
		risultato*=a;			//risultato moltiplica base a per b volte
	}
	return risultato;
}