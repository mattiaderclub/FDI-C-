#include <stdio.h>
#include <stdlib.h> 
/* ESERCITAZIONE 7 */
/* Programma che legge due interi introdotti dall'utente e stampa il quoziente e il resto
 * della divisione intera fra il più grande e il più piccolo dei due interi. Il programma
 * non deve utilizzare nessuna variabile di tipo int, ma solo variabili di tipo *int */

/* Funzioni di supporto da definire */
int *allocaMemoria();
void leggiValore(int* variabile);
void riordina(int* a, int* b);
void calcolaQuoziente(int* dividendo, int* divisore, int* quoziente);
void calcolaResto(int* dividendo, int* divisore, int* resto);

/* Funzione principale */
int main(){
	/* Dichiarazione variabili */
	int* x;
	int* y;
	int* q;
	int* r;

	/* Allocazione memoria */
	x = allocaMemoria();
	q = allocaMemoria();
	r = allocaMemoria();
	y = allocaMemoria();

	/* Input */
	printf("\nCiao utente sono un programma che legge due interi da tastiera e stampa\n");
	printf("quoziente e resto della divisione intera fra il piu' grande e il piu' piccolo.\n"); 
	printf("\nIntroduci due interi x & y.\n");
	/* Lettura valori */
	printf("\nX = ");
	leggiValore(x);
	printf("Y = ");
	leggiValore(y);


	/* Riordina i valori in modo tale che il primo sia il più grande */
	riordina(x, y);
	/* Calcolo del quoziente della divisione intera */
	calcolaQuoziente(x, y, q);
	/* Calcolo del resto della divisione intera */
	calcolaResto(x, y, r);

	/* Output */
	printf("\nQuoziente = %d.", *q);
	printf("\nResto = %d.\n", *r);

	/* Libero l'area di memoria delle variabili */
	free(x);
	free(y);
	free(q);
	free(r);
}

/* Funzione che alloca memoria per un intero e restituisce
 * l'indirizzo dell'area di memoria allocata */
int *allocaMemoria(){
	int *intero = (int *)malloc(1 * sizeof(int));
	return intero;
}

/* Funzione che legge un valore introdotto dall'utente e lo memorizza
 * all'indirizzo specificato nel parametro formale */
void leggiValore(int* variabile){
	scanf("%d", variabile);
}


/* Funzione che riordina due valori interi, di cui sono forniti gli indirizzi
 * nei parametri formali, così che il primo sia il più grande */
void riordina(int* a, int* b){
	if(*a < *b) {
		int c = *b;
		*b = *a;
		*a = c;
	}
}

/* Funzione che calcola il quoziente della divisione interi fra due interi di cui sono
 * forniti gli indirizzi nei parametri formali, e memorizza tale resto all'indirizzo
 * specificato nel parametro formale */
void calcolaQuoziente(int* dividendo, int* divisore, int* quoziente){
	*quoziente = *dividendo / *divisore;
}

/* Funzione che calcola il resto della divisione interi fra due interi di cui sono
 * forniti gli indirizzi nei parametri formali, e memorizza tale resto all'indirizzo
 * specificato nel parametro formale */
void calcolaResto(int* dividendo, int* divisore, int* resto){
	*resto = *dividendo % *divisore;
}