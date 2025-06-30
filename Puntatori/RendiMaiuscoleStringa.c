#include <stdio.h>
#include <string.h>
/* ESERCITAZIONE 7 */
/* Programma che legge una stringa introdotta dall'utente, la modifica rimpiazzando
 * ogni carattere alfabetico minuscolo con il corrispondente carattere alfabetico maiuscolo,
 * quindi stampa la stringa modificata in output */

/* Funzioni di supporto */
void maiuscole(char* stringa);
void testMaiuscole();

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica\n");
	printf("rimpiazzando ogni carattere alfabetico minuscolo con il corrispondente maiuscolo.\n\n");
	char stringa[50];
	printf("Introduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa) - 1] = '\0';
	/* Invoco la funzione maiuscole per modificare la stringa */
	maiuscole(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Stampa test di correttezza della funzione maiuscole */
	testMaiuscole();
}

/* Funzione che modifica la stringa parametro rimpiazzando ogni carattere alfabetico
 * minuscolo con il corrispondente carattere maiuscolo. All'interno della funzione non
 * dev'essere dichiarata nessuna variabile ma va usata l'aritmetica dei puntatori */
void maiuscole(char* stringa){

	/* Vado avanti fino all'ultimo carattere della stringa */
	while (*stringa != '\0') {
		/* Il carattere è alfabetico minuscolo */
		if (*stringa >= 'a' && *stringa <= 'z') {
			*stringa = *stringa + 'A' - 'a';
		}
		stringa++;				// Passo al carattere successivo
	}
}

/* Funzione che stampa un test di correttezza della funzione maiuscole */
void testMaiuscole(){
	/* Stringa vuota */
	char stringa1[] = "";
	maiuscole(stringa1);
	printf("Test maiuscole (\"\") : Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

	/* Stringa senza caratteri alfabetici minuscoli */
	char stringa2[] = "AA009BBLO44IIP";
	maiuscole(stringa2);
	printf("Test maiuscole (\"AA009BBLO44IIP\") : Atteso = \"AA009BBLO44IIP\", Calcolato = \"%s\"\n", stringa2);
	
	/* Stringa di soli caratteri alfabetico minuscoli */
	char stringa3[] = "aabbbccdrtt";
	maiuscole(stringa3);
	printf("Test maiuscole (\"aabbbccdrtt\") : Atteso = \"AABBBCCDRTT\", Calcolato = \"%s\"\n", stringa3);

	/* Stringa con un solo carattere alfabetico minuscolo all'inizio */
	char stringa4[] = "a000BD5T";
	maiuscole(stringa4);
	printf("Test maiuscole (\"a000BD5T\") : Atteso = \"A000BD5T\", Calcolato = \"%s\"\n", stringa4);

	/* Stringa con un solo carattere alfabetico minuscolo in mezzo  */
	char stringa5[] = "EE5PPPmAA6UU";
	maiuscole(stringa5);
	printf("Test maiuscole (\"EE5PPPmAA6UU\") : Atteso = \"EE5PPPMAA6UU\", Calcolato = \"%s\"\n", stringa5);

	/* Stringa con un solo carattere alfabetico minuscolo alla fine */
	char stringa6[] = "55TTHN6EEp";
	maiuscole(stringa6);
	printf("Test maiuscole (\"55TTHN6EEp\") : Atteso = \"55TTHN6EEP\", Calcolato = \"%s\"\n", stringa6);

	/* Stringa mista */
	char stringa7[] = "aaHhTT--66iiOopmEE4**qq";
	maiuscole(stringa7);
	printf("Test maiuscole (\"aaHhTT--66iiOopmEE4**qq\") : Atteso = \"AAHHTT--66IIOOPMEE4**QQ\", Calcolato = \"%s\"\n", stringa7);
}