#include <stdio.h>

/* Programma che chiede all'utente di inserire 2 numeri x e y
 * e un numero compreso tra 1 e 4 che servirà per determinare
 * l'operazione da effettuare sui 2 interi */

int main(){
	int x, y, operazione;
	do{
		printf("Scegliere l'operazione da effettuare\n");
		scanf("%d", &operazione);
		printf("Inserire due numeri interi\n");
		scanf("%d%d", &x, &y);
		
		if(operazione==1)
			printf("Il risultato dell'addizione %c: %d\n\n", 138, x+y);
			//Con 1 viene effettuata la somma
		else if(operazione==2)
			printf("Il risultato della sottrazione %c: %d\n\n", 138, x-y);
			//Con 2 viene effettuata la sottrazione
		else if(operazione==3)
			printf("Il risultato del prodotto %c: %d\n\n", 138, x*y);
			//Con 3 viene effettuato il prodotto
		else if(operazione==4)
			printf("Il risultato della divisione %c: %d con resto %d\n\n", 138, x/y, x%y);
			//Con 4 vengono calcolati quoziente e resto
	}

	while(operazione!=0);
		printf("Alla prossima");
}