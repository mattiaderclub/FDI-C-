#include <stdio.h>

int main(){
	int base, altezza;
	int i, j;

	printf("Dammi una base del tuo rettangolo: ");
	scanf("%d", &base);
	printf("Dammi un'altezza del tuo rettangolo: ");
	scanf("%d", &altezza);

	for(i=1; i<=altezza; i++){
		for(j=1; j<=base; j++){
			printf("%c", 42);
		}
		printf("\n");	
	}
	printf("\nEcco il tuo rettangolo di asterischi");
}
