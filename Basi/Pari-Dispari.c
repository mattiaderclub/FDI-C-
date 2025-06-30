#include <stdio.h>

int main(){
	int numero;      //Consideriamo gli interi maggiori di 2
	printf("Dammi un  numero e ti diro' se esso e' pari o dispari\n");
	scanf("%d", &numero);
	if(numero%2==0)
		printf("il tuo numero e' pari\n");
	else{
		(numero++);
	    printf("Il tuo numero e' pari solo se incrementato di un'unita'");
	}
}