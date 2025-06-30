#include <stdio.h>
#include <string.h>

/* Programma che legge una stringa e la modifica eliminando
 * tutti i caratteri che non sono alfbetici */

/* Funzioni ausialiarie */
void soloAlfabetici(char* stringa);
void testSoloAlfabetici();
int isAlfabetico(char c);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa e la restituisce\n");
	printf("eliminando dalla stringa tutti i caratteri non alfabetici\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Modifica la stringa */
	soloAlfabetici(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Test correttezza funzione */
	testSoloAlfabetici();
}

/* Funzione che modifica la stringa ricevuta eliminando i caratteri non alfabetici */
void soloAlfabetici(char* stringa){
	int i, j;			// Contatori
	i = 0;

	/* Leggo la stringa fino all'ultimo carattere */
	while(stringa[i]!='\0'){
		/* Il carattere è alfanetico */
		if(!isAlfabetico(stringa[i])){
			j = i;
			/* Cambio indice e sfoglio la stringa */
			while(stringa[j]!='\0'){
				stringa[j] = stringa[j+1];
				j++;
			}
		}
		else
			i++;
	}
}

/* Funzione che stampa sullo schermo un test che testimonia la correttezza dell'algoritmo */
void testSoloAlfabetici(){
	/* Stringa vuota */
	char stringa1[] = "";
	soloAlfabetici(stringa1);
	printf("Test soloAlfabetici (\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* Stringa di soli alfabetici */
	char stringa2[] = "AAbbRTjfoeXZZyy";
	soloAlfabetici(stringa2);
	printf("Test soloAlfabetici (\"AAbbRTjfoeXZZyy\"): Atteso = \"AAbbRTjfoeXZZyy\", Calcolato = \"%s\" \n", stringa2);

	/* Stringa senza alfabetici */
	char stringa3[] = "3820-- 432__ 480*";
	soloAlfabetici(stringa3);
	printf("Test soloAlfabetici (\"3820-- 432__ 480*\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa3);

	/* Stringa mista */
	char stringa4[] = "ah5$56knFGJ=) 12g";
	soloAlfabetici(stringa4);
	printf("Test soloAlfabetici (\"ah5$56knFGJ=) 12g\"): Atteso = \"ahknFGJg\", Calcolato = \"%s\" \n", stringa4);
}

/* Funzione che controlla se il carattere preso in esame sia alfabetico o meno */
int isAlfabetico(char c){
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));	// Valore booleano di ritorno
}