#include <stdio.h>
#include <string.h>

/* Funzioni ausiliarie */
void asteriscoNonAlfabetico(char* stringa);
int isAlfabetico(char c);

/* Funzione principale */
int main(){
	/* Input */
    printf("\nCiao utente, sono un programma che legge una stringa e la modifica\n");
    printf("rendendo asterischi tutti i caratteri non alfabetici\n");
    char stringa[50];
    printf("Introduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione asteriscoNonAlfabetico */
    asteriscoNonAlfabetico(stringa);

    /* Output */
    printf("\nEcco la stringa trasformata: %s\n\n", stringa);
}

/* Funzione che riceve come parametro una stringa e la modifica rimpiazzando ogni
 * carattere non alfabetico con l'asterisco */
void asteriscoNonAlfabetico(char* stringa){
	int i;			// Contatore
	i = 0;

	/* Controllo tutta la stringa */
	while(stringa[i]!='\0'){
		/* Il carattere controllato è alfabetico? Richiamo la funzione */
		if(!isAlfabetico(stringa[i])){
			stringa[i] = '*';				// Scambio il carattere non alfabetico con l'asterisco
		}
		i++;								// Passo al carattere alfabetico
	}
}

/* Funzione che controlla se il carattere è alfabetico o meno. Ritorna un valore booleano */
int isAlfabetico(char c){
	return ((c>='A' && c<='Z') || (c>='a' && c<='z'));
}
