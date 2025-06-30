#include <stdio.h>

int main(){
	int n, valore;
	int i, somma;

	somma=0;

	printf("Quanti valori vuoi sommare? ");
	scanf("%d", &n);

	for(i=1; i<=n; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &valore);

		somma+=valore;
	}
	printf("La somma dei tuoi %d valori %c pari a: %d", n, 138, somma);
}