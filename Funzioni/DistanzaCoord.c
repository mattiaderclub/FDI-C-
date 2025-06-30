#include <stdio.h> 
#include <math.h>

/*Funzione di supporto*/
float coordinate(int x_a, int x_b, int y_a, int y_b);

/*Programma che entrambe le coordinate di due punti 
 *e utilizza una funzione per calcolarne la distanza*/
int main(){
	/*INPUT: coordinate*/
	int a1, a2, b1, b2;
	//Punto A
	printf("\nDammi le coordinate del punto A\n");
	scanf("%d%d", &a1, &a2);
	//Punto B
	printf("Dammi le coordinate del punto B\n");
	scanf("%d%d", &b1, &b2);
	/*OUTPUT*/
	printf("\nLa distanza tra il punto A e il punto B %c %.2f\n\n", 138, coordinate(a1,b1,a2,b2));
}

/*Funzione che riceve le coordinate del punto A
 *e del punto B e ne calcola la distanza*/
float coordinate(int x_a, int x_b, int y_a, int y_b){
	//Dichiarazione variabili
	float distanza; 
	int calcolo_x, calcolo_y;
	calcolo_x=(x_a - x_b)*(x_a - x_b);	//Quadrato differenza delle x
	calcolo_y=(y_a - y_b)*(y_a - y_b);	//Quadrato differenza delle y
	distanza = sqrt(calcolo_x+calcolo_y);	//Somma quadrati sotto radice
	return distanza;
}
