#include <stdio.h>

int main(){
	int n, intero;
	int i, max;

	printf("Quanti valori vuoi?\n");
	scanf("%d", &n);

	for(i=1; i<=n; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &intero);
		if(intero>max)
			max=intero;
	}
	printf("Il massimo tra i %d interi %c pari a: %d", n, 138, max);
}