#include <stdio.h>

/*Funzioni di supporto*/
float quadrato(float x);
float cubo(float x);

/*Applicazione delle 2 funzioni sopra richiamate
 *con lettura di valore da tastiera*/
int main(){
	/*INPUT*/
	float valore;
	printf("\nDammi un intero: ");
	scanf("%7.2f", &valore);
	/*OUTPUT*/
	printf("Quadrato: %f\n", quadrato(valore));
	printf("Cubo: %f\n\n", cubo(valore));
}

/*Funzione che calcola il quadrato di un intero*/
float quadrato(float x){
	x=x*x;				//quadrato
	return x;
}
/*Funzione che calcola il cubo di un intero*/
float cubo(float x){
	x=x*x*x;			//cubo
	return x;
}