#include <stdio.h>
int main(){
	int numero;
	int fattoriale;
	int i;

	printf("Dammi un  intero positivo e te ne calcolo\ne stampo il fattoriale: ");
	scanf("%d", &numero);
	fattoriale = 1;

	for(i=1; i<=numero; i++){
		fattoriale *= i;
		printf("%d\n", fattoriale);
	}
}