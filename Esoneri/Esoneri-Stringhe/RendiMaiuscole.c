#include <stdio.h>
#include <string.h>

/* Funzioni di supporto */
void rendiMaiuscole(char* stringa);
void testRendiMaiuscole();
int isMinuscolo(char c);

/* Funzione principale */
int main(){
	/* Input */
    printf("\nCiao utente, sono un programma che legge una stringa e la modifica\n");
    printf("rendendo maiuscole tutte le lettere minuscole (non accentate)\n\n");
    char stringa[50];
    printf("Introduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione rendiMaiuscole */
    rendiMaiuscole(stringa);

    /* Output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);
    /* Fai partire il test */
    testRendiMaiuscole();
}

/* Funzione che trasforma caratteri alfabetici minuscoli (non accentati) in maiuscoli */
void rendiMaiuscole(char* stringa){
	int i;				// Contatore
	i = 0;

	/* Controllo la stringa fino all' ultimo carattere */
	while(stringa[i]!='\0'){
		/* Controllo se il carattere è minuscolo richiamando la funzione */
		if(isMinuscolo(stringa[i])){
			/* Rendo maiuscolo il carattere giocando con i codici ASCII */
			stringa[i] = stringa[i] + 'A' - 'a';
		}
		i++;			// Passo al carattere successivo
	}
}

/* Test di correttezza della funzione rendiMaiuscole */
void testRendiMaiuscole(){
	/* Stringa vuota */
	char stringa1[] = "";
	rendiMaiuscole(stringa1);
	printf("Test RendiMaiuscole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* Stringa senza minuscoli */
	char stringa2[] = "0A9BRO234XJE45";
	rendiMaiuscole(stringa2);
	printf("Test RendiMaiuscole(\"0A9BRO234XJE45\"): Atteso = \"0A9BRO234XJE45\", Calcolato = \"%s\" \n", stringa2);

	/* Stringa mista */
	char stringa3[] = "28 giugno - Aula Campus";
	rendiMaiuscole(stringa3);
	printf("Test RendiMaiuscole(\"28 giugno - Aula Campus\"): Atteso = \"28 GIUGNO - AULA CAMPUS\", Calcolato = \"%s\" \n", stringa3);
}

/* Funzione che ritorna 1 se il carattere controllato è minuscolo, 0 altrimenti */
int isMinuscolo(char c){
	return (c>='a' && c<='z');
}



