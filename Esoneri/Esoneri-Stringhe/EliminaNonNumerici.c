#include <stdio.h>
#include <string.h>

/* Programma che consiste di almeno tre funzioni */
/* Funzioni di supporto */
void eliminaNonNumerici(char* stringa);
void testEliminaNonNumerici();
int isNum(char c);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa di caratteri\n");
	printf("e la modifica eliminando tutti i caratteri non numerici.\n");
	char stringa[50];
	printf("Introduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione per modificare la stringa */
	eliminaNonNumerici(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Stampa test di correttezza */
	testEliminaNonNumerici();
}

/* Funzione che riceve come parametro una stringa e la modifica eliminando 
 * tutti i caratteri non numerici */
void eliminaNonNumerici(char* stringa){
	int i, j;			// Contatori
	i = 0;

	/* Controllo la stringa fino all'ultimo carattere */
	while(stringa[i]!='\0'){
		/* Il carattere è numerico? */
		if(isNum(stringa[i])){
			i++;			// Passo al carattere successivo
		}
		else{
			/* Non essendo numerico lo cancello
			 * ma non avanzo con l'indice i */
			for(j=i; stringa[j]!='\0'; j++)
				stringa[j] = stringa[j+1];
		}
	}

}
/* Funzione che realizza un test a scatola nera per dimostrare la correttezza della funzione.
 * Devono essere presi in considerazione tutti i casi possibili */
void testEliminaNonNumerici(){
	/* Stringa vuota */
	char stringa1[] = "";
	eliminaNonNumerici(stringa1);
	printf("Test eliminaNonNumerici(\"\"). Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* Stringa senza numeri */
	char stringa2[] = "A*bN/_#OO";
	eliminaNonNumerici(stringa2);
	printf("Test eliminaNonNumerici(\"A*bN/_#OO\"). Atteso = \"\", Calcolato = \"%s\" \n", stringa2);

	/* Stringa con solo numeri */
	char stringa3[] = "558204";
	eliminaNonNumerici(stringa3);
	printf("Test eliminaNonNumerici(\"558204\"). Atteso = \"558204\", Calcolato = \"%s\" \n", stringa3);

	/* Stringa con un solo carattere non numerico all'inizio */
	char stringa4[] = "A008934";
	eliminaNonNumerici(stringa4);
	printf("Test eliminaNonNumerici(\"A008934\"). Atteso = \"008934\", Calcolato = \"%s\" \n", stringa4);

	/* Stringa con un solo carattere non numerico alla fine */
	char stringa5[] = "178431P";
	eliminaNonNumerici(stringa5);
	printf("Test eliminaNonNumerici(\"178431P\"). Atteso = \"178431\", Calcolato = \"%s\" \n", stringa5);

	/* Stringa con un solo carattere numerico all'inizio */
	char stringa6[] = "9ALLNIPP";
	eliminaNonNumerici(stringa6);
	printf("Test eliminaNonNumerici(\"9ALLNIPP\"). Atteso = \"9\", Calcolato = \"%s\" \n", stringa6);

	/* Stringa con un solo carattere numerico alla fine */
	char stringa7[] = "UUNNTYE7";
	eliminaNonNumerici(stringa7);
	printf("Test eliminaNonNumerici(\"UUNNTYE7\"). Atteso = \"7\", Calcolato = \"%s\" \n", stringa7);

	/* Stringa mista */
	char stringa8[] = "ab56hj?#fg3";
	eliminaNonNumerici(stringa8);
	printf("Test eliminaNonNumerici(\"ab56hj?#fg3\"): Atteso = \"563\", Calcolato = \"%s\" \n", stringa8);
}
/* Funzione che controlla se il carattere è numerico o meno */
int isNum(char c){
	int numerico = 0;
	if(c>='0' && c<='9')
		numerico = 1;
	return numerico;
}