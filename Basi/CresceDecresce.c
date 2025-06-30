#include <stdio.h>

int main(){
	int penultimo, ultimo;
	printf("Dammi un primo intero: ");
	scanf("%d", &penultimo);
	printf("Dammi un secondo intero: ");
	scanf("%d", &ultimo);

	while(penultimo!=ultimo) {
		if(penultimo>ultimo)
			printf("Questo era piu' piccolo\n");
		else
			printf("Questo era piu' grande\n");

		penultimo = ultimo;
		printf("Dammi un intero: ");
		scanf("%d", &ultimo);

	}
	printf("Basta sei diventato ripetitivo!!");
}