#include <stdio.h>
#include <string.h>

/* Funzione ausiliaria */
int esisteMaiuscola(char* stringa);

int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa non vuota di caratteri e sfrutta\n");
	printf("una funzione ricorsiva per controllare se compare almeno un carattere alfabetico minuscolo.\n");
	printf("Restituisco un valore booleano.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: "),
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';

	/* Invoco la funzione per assegnare il valore booleano alla variabile */
	int esiste = esisteMaiuscola(stringa);
	/* Output */
	if(esiste)
		printf("\nEsiste un carattere alfabetico minuscolo all'interno della stringa.\n");
	else
		printf("\nNon esiste alcun carattere alfabetico minuscolo all'interno della stringa.\n");
}

int esisteMaiuscola(char* stringa){
	int ris;

	if(strlen(stringa)==0)
		ris = 0;
	else{
		ris = ((stringa[0]>='a' && stringa[0]<='z') || esisteMaiuscola(stringa+1));
	}
	return ris;
}