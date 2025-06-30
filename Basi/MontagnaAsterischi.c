#include <stdio.h>

int main(){
	int altezza;
	int i, j;

	printf("Scegli un'altezza per la tua montagna: ");
	scanf("%d", &altezza);

	for(i=1; i<=altezza; i++){
		for(j=1; j<=(2*i); j++){
			printf("%c", 42);
		}
		printf("\n");
	}
	printf("\nEcco la tua montagna");
}