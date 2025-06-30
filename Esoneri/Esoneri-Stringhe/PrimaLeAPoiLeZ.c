#include <stdio.h>
#include <string.h>

/* Programma che consiste di tre funzioni */

/* Funzioni ausiliarie */
/* Una funzione primaLeAPoiLeZ riceve come parametro una stringa e la modifica riordinando 
 * i caratteri della stringa così che tutte le 'a' (minuscole) compaiono all'inizio della
 * stringa e tutte le 'z' (minuscole) compaiono alla fine della stringa. Caratteri diversi 
 * da 'a' e 'z' possono apparire in un ordine qualsiasi (comunque dopo le 'a' e prima delle 'z')

/* Una funzione testPrimaLeAPoiLeZ verifica la correttezza della funzione primaLeAPoiLeZ.
 * La funzione di test deve realizzare un test a scatola nera */
void primaLeAPoiLeZ(char* stringa);
void testPrimaLeAPoiLeZ();

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa da tastiera e la modifica\n");
	printf("riordinando i caratteri della stringa in modo tale che tutte le 'a' e 'z' (minuscole) compaiano\n");
	printf("all'inizio e alla fine della stringa. I restanti caratteri possono comparire in qualsiasi ordine\n");
	char stringa[50];
	printf("\nIntroduci una stringa: ");
	fgets(stringa, 50, stdin);

	/* Rimuovi \n */
	stringa[strlen(stringa)-1] = '\0';
	/* Invoca la funzione per la modifica della stringa */
	primaLeAPoiLeZ(stringa);

	/* Output */
	printf("\nEcco la stringa modificata: %s\n\n", stringa);
	/* Stampa test di correttezza dell'algoritmo */
	testPrimaLeAPoiLeZ();
}

void primaLeAPoiLeZ(char* stringa){
	int i, j, k, n;
	i = 0;			// Contatore primo processo
	j = 0;			// Contatore primo processo

	/* Processo per sistemare le a */
	/* Leggo stringa fino all'ultimo carattere */
	while(stringa[i]!='\0'){
		/* Controllo se il carattere è proprio 'a' */
		if(stringa[i]=='a'){
			/* Scambio i caratteri e inserisco 'a' */
			stringa[i] = stringa[j];
			stringa[j] = 'a';
			j++;
		}
		i++;
	}
	k = strlen(stringa)-1;		// Contatore secondo processo
	n = strlen(stringa)-1;		// Contatore secondo processo

	/* Processo per sistemare le z */
	/* Leggo stringa fino all'ultimo carattere */
	while(stringa[n]!='\0'){
		/* Controllo se il carattere è proprio 'z' */
		if(stringa[n]=='z'){
			/* Scambio i caratteri e inserisco 'z' */
			stringa[n] = stringa[k];
			stringa[k] = 'z';
			k--;
		}
		n--;
	}
}

void testPrimaLeAPoiLeZ(){
	/* Stringa vuota */
	char stringa1[] = "";
	primaLeAPoiLeZ(stringa1);
	printf("Test primaLeAPoiLeZ (\"\"): Atteso = \"\", Calcolato = \"%s\"\n", stringa1);

	/* Stringa con una sola 'a' in ultima posizione */
	char stringa2[] = "000a";
	primaLeAPoiLeZ(stringa2);
	printf("Test primaLeAPoiLeZ (\"000a\"): Atteso = \"a000\", Calcolato = \"%s\"\n", stringa2);

	/* Stringa con diverse 'a' in varie posizioni */
	char stringa3[] = "a0a000aaa00aaa";
	primaLeAPoiLeZ(stringa3);
	printf("Test primaLeAPoiLeZ (\"a0a000aaa00aaa\"): Atteso = \"aaaaaaaa000000\", Calcolato = \"%s\"\n", stringa3);

	/* Stringa con una sola 'z' in prima posizione */
	char stringa4[] = "z000";
	primaLeAPoiLeZ(stringa4);
	printf("Test primaLeAPoiLeZ (\"z000\"): Atteso = \"000z\", Calcolato = \"%s\"\n", stringa4);

	/* Stringa con diverse 'z' in varie posizioni */
	char stringa5[] = "zz00zz000zz0z0zz";
	primaLeAPoiLeZ(stringa5);
	printf("Test primaLeAPoiLeZ (\"zz00zz000zz0z0zz\"): Atteso = \"0000000zzzzzzzzz\", Calcolato = \"%s\"\n", stringa5);

	/* Stringa contenenti sia 'a' sia 'z' */
	char stringa6[] = "09za0a00z909azazaaa090azzzz90";
	primaLeAPoiLeZ(stringa6);
	printf("Test primaLeAPoiLeZ (\"09za0a00z909azazaaa090azzzz90\"): Atteso = \"aaaaaaaa0909090009009zzzzzzzz\", Calcolato = \"%s\"\n", stringa6);
}
