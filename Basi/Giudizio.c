#include <stdio.h>

/* Programma che chiede prima all'utente di inserire un numero intero
 * che rappresenta il voto di un'esame universitario, ne stampa un giudizio 
 * e poi chiede di inserirne un altro tra 0 e 1 per accettare 
 * o rifiutare l'esito */

int main(){
	int esito, verdetto;
	printf("Inserisci il voto\n");
	scanf("%d", &esito);

	if(esito>0 && esito<=31){
		if(esito<=17)
			printf("Esame non superato\n");
		else if(esito>=18 && esito<=31){
			if(esito>=18 && esito<=24)
				printf("Giudizio: Sufficiente\n");
			else if(esito>=25 && esito<=30)
				printf("Giudizio: Buono\n");
			else if(esito=31)
				printf("Bravissimo, 30 e lode\n");

			printf("Hai intenzione di registrare il voto?\n");
			scanf("%d", &verdetto);
			if(verdetto==1)
				printf("Voto registrato\n");
			else if(verdetto==0)
				printf("Voto rifiutato\n");

		}
	}
	else
		printf("Numero errato\n");
}