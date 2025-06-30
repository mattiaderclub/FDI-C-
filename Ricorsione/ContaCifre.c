#include <stdio.h>

/* Funzione ausiliaria */
int contaCifre(int numero);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge un intero positivo da tastiera\n");
	printf("e sfrutta una funzione ricorsiva per contare le cifre che compongono.\n");
	int val;			// Numero da controllare
	printf("Vuoi contare le cifre del numero ");
	scanf("%d", &val);

	/* Output */
	printf("\nIl numero %d %c composto da %d cifre.\n", val, 138, contaCifre(val));
}

/* Funzione che riceve come parametro un numero e conta il numero di cifre */
int contaCifre(int numero){
	int conta;

	/* Il numero non è divisibile per 10: ha una sola cifra */
	if(numero/10==0)
		conta = 1;
	/* Il numero ha 2 o più cifre */
	else{
		/* Il numero è divisibile per 10: conta una cifra e va al passo successivo
		 * stavolta con il numero diviso per 10, avendo contato il caso (cifra) */
		conta = 1 + contaCifre(numero/10);
	}
	return conta;
}