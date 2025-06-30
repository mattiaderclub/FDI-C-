#include <stdio.h>
#include <string.h>

/* Programma che consiste di quattro funzioni */

/* Funzioni ausiliarie */
/* Una funzione numeriNascosti che riceve come parametro una stringa e la modifica
 * rimpiazzando ogni sequenza di caratteri numerici con esattamente un carattere '*'.

/* Una funzione testNumeriNascosti che verifica la correttezza della funzione
 * numeriNascosti. La funzione di test deve realizzare un test a scatola nera. */
void numeriNascosti(char* stringa);
void testNumeriNascosti();

/* Funzioni in aggiunta */
/* Funzione che torna un valore booleano a seconda che il carattere sia numerico o meno */
int isNumerico(char c);

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica\n");
	printf("rimpiazzando ogni sequenza di caratteri numerici con esattamente un carattere '*'.\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuove \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione numeriNascosti e modifica la stringa */
	numeriNascosti(stringa);

	/* Output */
	printf("\nStringa modificata: %s\n\n", stringa);
	/* Stampa test di correttezza dell'algoritmo */
	testNumeriNascosti();
}

void numeriNascosti(char* stringa){
	int i, j;
	i = 0;

	/* Va avanti fino a fine stringa */
	while(stringa[i]!='\0'){
		/* Il primo carattere è numerico? */
		if(isNumerico(stringa[i])){
			stringa[i] = '*';
			/* Controllo se anche il suo successivo è numerico */
			if(isNumerico(stringa[i+1])){
				/* Se anche il successivo è numerico cancelli e sposti 
				 * gli elementi di un posto all'indietro */
				j = i;
				while(stringa[j]!='\0'){
					stringa[j] = stringa[j+1];
					j++;				// Passo al carattere successivo
				}
			}
			else
				i++;
		}
		else
			i++;
	}
}

int isNumerico(char c){
	int numero = 0;
	if(c>='0' && c<='9')
		numero = 1;

	return numero;			// Valore di ritorno (booleano)
}

void testNumeriNascosti(){
	/* Stringa vuota */
	char stringa1[] = "";
	numeriNascosti(stringa1);
	printf("Test numeriNascosti (\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);
}