#include <stdio.h>
#include <string.h>

/* Programma che consiste di quattro funzioni */

/* Funzioni ausiliarie */
/* Una funzione soloParole che riceve come parametro una stringa e la modifica
 * in modo tale checompaiano solo le parole della stringa parametro, dove ogni
 * due parole consecutive sono separate da un singolo spazio.

/* Una funzione testSoloParole stampa un test che verifica la correttezza
 * dell'algoritmo. La funzione deve realizzare un test a scatola nera. */
void soloParole(char* stringa);
void testSoloParole();

/* Funzioni in aggiunta */
/* Funzione che torna un valore booleano a seconda che il carattere sia alfabetico o meno */
int isAlfabetico(char c);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica\n");
	printf("in modo tale checompaiano solo le parole della stringa parametro, dove ogni\n");
	printf("due parole consecutive sono separate da un singolo spazio.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuove \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione per modifica la stringa */
	soloParole(stringa);

	/* Output */
	printf("\nStringa modifica: %s\n\n", stringa);
	/* Stampa test di correttezza della funzione */
	testSoloParole();
}

void soloParole(char* stringa){
	int i, j;		// Contatori
	i = 0;

	/* Vai avanti fino a fine stringa */
	while(stringa[i]!='\0'){
		/* Controllo se mi trovo a inizio stringa */
		if(i==0){
			/* Il carattere è alfabetico? */
			if(isAlfabetico(stringa[i]))		
				i++;			// Passo al carattere successivo
			else{
				/* Sposta tutti gli elementi della stringa un posto indietro
				 * cancellando il carattere controllato. Contatore i non incrementa */
				for(j=0; stringa[j]!='\0'; j++)
					stringa[j] = stringa[j+1];
			}
		}
		else{
			/* Il carattere è alfabetico? */
			if(isAlfabetico(stringa[i])){
				i++;			// Passa avanti
			}
			else{
				stringa[i] = ' ';		// Separo la parola precedente con uno spazio
										// non essendo alfabetico il carattere controllato
				/* Significa che ci sta un blocco di caratteri non alfabetico consecutivi */
				if(!isAlfabetico(stringa[i+1])){
					/* Sposta tutti gli elementi della stringa un posto indietro
				 	 * cancellando il carattere controllato. Contatore i non incrementa */
					j = i;
					while(stringa[j]!='\0'){
						stringa[j] = stringa[j+1];
						j++;
					}
				}
				else
					i++;		// Legge carattere successivo
			}

		}
	}
}

void testSoloParole(){
	/* Stringa vuota */
	char stringa1[] = "";
	soloParole(stringa1);
	printf("Test soloParole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* Stringa con sole caratteri alfabetici */
	char stringa2[] = "djskfhdjkhg";
	soloParole(stringa2);
	printf("Test soloParole(\"djskfhdjkhg\"): Atteso = \"djskfhdjkhg\", Calcolato = \"%s\" \n", stringa2);

	/* Stringa senza caratteri alfabetici */
	char stringa3[] = "0£,  .34";
	soloParole(stringa3);
	printf("Test soloParole(\"0£,.34\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa3);

	/* Stringa con un solo carattere alfabetico all'inizio */
	char stringa4[] = "a678()0";
	soloParole(stringa4);
	printf("Test soloParole(\"a678()0\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa4);

	/* Stringa con un solo carattere alfabetico alla fine */
	char stringa5[] = "678/0a";
	soloParole(stringa5);
	printf("Test soloParole(\"678/0a\"): Atteso = \"a\", Calcolato = \"%s\" \n", stringa5);


	/* Stringa con un solo carattere non alfabetico all'inizio */
	char stringa6[] = "6abcde";
	soloParole(stringa6);
	printf("Test soloParole(\"6abcde\"): Atteso = \"abcde\", Calcolato = \"%s\" \n", stringa6);

	/* Stringa con un solo carattere non alfabetico alla fine */
	char stringa7[] = "abcde6";
	soloParole(stringa7);
	printf("Test soloParole(\"abcde6\"): Atteso = \"abcde\", Calcolato = \"%s\" \n", stringa7);

	/* Stringa con una sola parola centrale*/
	char stringa8[] = "123abcd 45";
	soloParole(stringa8);
	printf("Test soloParole(\"123abcd 45\"): Atteso = \"abcd\", Calcolato = \"%s\" \n", stringa8);

	/* Stringa con tante parole */
	char stringa9[] = " abc 5def ?? ghi))";
	soloParole(stringa9);
	printf("Test soloParole(\" abc 5def ?? ghi))\"): Atteso = \"abc def ghi\", Calcolato = \"%s\" \n", stringa9);
}

int isAlfabetico(char c){
	int alfabetico = 0;
	/* Il carattere ricevuto è alfabetico? */
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		alfabetico = 1;
	return alfabetico;
}
