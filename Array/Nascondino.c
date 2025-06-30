#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Programma che simula una sorta di nascondino contro il computer.
 * Per vincere l'utente deve stanare tutti i nascondigli del
 * calcolatore. Alla fine viene stampato anche il numero totale di
 * tentativi prima della vittoria */

/* Funzioni di supporto */
void introduzioneGioco();

int main(){
	int tentativi=0;
	int i, j;
	int dimensione1;
	int dimensione2;

	srand(time(NULL));
	void introduzioneGioco();

	printf("\nScegli la dimensione del terreno: ");
	scanf("%1d", &dimensione1);

	dimensione2=dimensione1;
	int terreno[dimensione1][dimensione2];
	int nascondigli=(dimensione1*dimensione2)/3;

	

	for(i=0; i<dimensione1; i++){
		for(j=0; j<dimensione2; j++){
			printf("%4d", terreno[i][j]);
		}
		printf("\n");
	}


}

void introduzioneGioco(){
	printf("\nCiao giocatore, benvenuto nel gioco di nascondino!");
	printf("\nAll'inizio ti chieder%c di scegliere la dimensione del terreno.");
	printf("\nIl numero dev'essere compreso tra 3 e 9 in modo da rendere il tutto interessante.");
	printf("\nQuindi mi nasconder%c un numero di volte pari a 1/3 della dimensione del terreno.");
	printf("\nSar%c tuo obiettivo trovare tutti i miei nascondigli.");
	printf("\nOvviamente meno tentativi sprecherai e pi%c sarai bravo.");
	printf("\nChe il gioco cominci!!\n\n");
}