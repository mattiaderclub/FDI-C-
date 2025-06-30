#include <stdio.h>

//Programma che chiede di inserire un intero, 
//lo legge e stampa un messaggio che dice se 
//l'intero è positivo, negativo o nullo

int main(){
	int numero;
	printf("Caro utente, dammi un intero: ");
	scanf("%d", &numero);
	
	if(numero!=0){
		if(numero>0)
			printf("POSITIVO");
		else
			printf("NEGATIVO");
	}
	else 
		printf("NULLO");

}