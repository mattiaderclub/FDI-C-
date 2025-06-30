#include <stdio.h>
#include <string.h>

/* Funzione ausiliaria */
int occorrenzeCarattere(char* stringa, char c);

int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa non vuota di caratteri e un carattere\n");
	printf("e sfrutta una funzione ricorsiva per contare le occorrenze di tale carattere nella stringa.\n");
	char stringa[50];
	char carattere;
	printf("\nIntroduci una stringa: "),
	fgets(stringa, 50, stdin);
	printf("Introduci il carattere da contare: "),
	scanf("%c", &carattere);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';

	/* Invoco la funzione per assegnare il valore booleano alla variabile */
	int quante = occorrenzeCarattere(stringa, carattere);
	/* Output */
	printf("\nIl carattere %c compare %d volte.\n", carattere, quante);
}

int occorrenzeCarattere(char* stringa, char c){
	int contatore;

	if(strlen(stringa)==0)
		contatore = 0;
	else{
		contatore = (stringa[0] == c) + occorrenzeCarattere(stringa+1, c);
	}
	return contatore;
}