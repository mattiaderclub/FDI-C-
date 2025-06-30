#include <stdio.h>

/* Programma che chiede all'utente di inserire
 * gli estremi di un intervallo e ne stampa
 * i valori all'interno */

int main(){
	int est1, est2;
	int i;
	printf("Utente, scegli gli estremi di un intervallo\n");
	scanf("%d%d", &est1, &est2);
	printf("Ecco il tuo intervallo: [%d;%d]\n", est1, est2);
	printf("Il tuo intervallo contiene i seguenti numeri: ");

	for(i=est1; i<=est2; i++){
		printf("%d  ", i);
	}
}