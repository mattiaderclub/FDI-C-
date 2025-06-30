#include <stdio.h>

/* Programma che dato un intero realizza
 * un conto alla rovescia fino a 0 */

int main(){
	int countdown;
	printf("Inserisci un valore countdown: ");
	scanf("%d", &countdown);
	
	while(countdown>=0){
		printf("%d  ", countdown);
		countdown--;
	}
}