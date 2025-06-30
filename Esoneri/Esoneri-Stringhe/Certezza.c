#include <stdio.h>
#include <string.h>

/* Funzioni di supporto */
void certezza(char* stringa);
void testCertezza();

/* Funzione principale */
int main(){
	/* Input */
	printf("\nCiao utente, sono un programma che legge una stringa di caratteri e\n");
	printf("la modifica rimpiazzando ogni sottostringa 'boh' con una stringa 'si'.\n");
	char stringa[50];
    printf("\nIntroduci una stringa: ");
    fgets(stringa, 50, stdin);

    /* Rimuovi \n */
    stringa[strlen(stringa)-1] = '\0';
    /* Invoca la funzione certezza */
    certezza(stringa);

    /* Output */
    printf("Ecco la stringa trasformata: %s\n\n", stringa);
    /* Fai partire il test */
    testCertezza();
}

/* Funzione che controlla una stringa ricevuta come parametro e la modifica
 * rimpiazzando ogni sottostringa 'boh' con una stringa 'si */
void certezza(char* stringa){
	int i, j;				// Variabili per scandire la stringa
	i=0;					// Parto dal primo carattere

	/* Controllo la stringa finchè non finisce */
	while(stringa[i]!='\0'){
		/* è presente la sottostringa 'boh' all'interno della stringa? */
		if(stringa[i]=='b' && stringa[i+1]=='o' && stringa[i+2]=='h'){
			/* Trasformo i primi caratteri per ottenere la sottostringa 'si',
			 * quindi sposto tutta la stringa un posto più indietro prima di
			 * ricominciare il controllo di essa */
			stringa[i]='s';
			stringa[i+1]='i';
			j=i+2;
			// J parte da i+2 in quanto è il carattere di 'boh' che dev'essere eliminato */
			while(stringa[j]!='\0'){
				stringa[j]=stringa[j+1];
				j++;
			}
		}
		else
			i++;		// Passa al carattere successivo se non compare 'boh'
	}
}

/* Funzione che stampa sullo schermo un test della funzione eseguito su alcune parole
 * coprendo tutti i casi possibili */
void testCertezza(){

	/* Stringa vuota */
	char stringa1[] = "";
	certezza(stringa1);
	printf("Test Certezza(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", stringa1);

	/* Stringa non vuota ma senza sottostringhe 'boh' */
	char stringa2[] = "ab56hj98";
	certezza(stringa2);
	printf("Test Certezza(\"ab56hj98\"): Atteso = \"ab56hj98\", Calcolato = \"%s\" \n", stringa2);

	/* Stringa con una sola sottostringa 'boh' all'inizio */
	char stringa3[] = "boh123";
	certezza(stringa3);
	printf("Test Certezza(\"boh123\"): Atteso = \"si123\", Calcolato = \"%s\" \n", stringa3);

	/* Stringa con una sola sottostringa 'boh' in mezzo */
	char stringa4[] = "dip567bohBi190";
	certezza(stringa4);
	printf("Test Certezza(\"dip567bohBi190\"): Atteso = \"dip567siBi190\", Calcolato = \"%s\" \n", stringa4);

	/* Stringa con una sola sottostringa 'boh' alla fine */
	char stringa5[] = "45trh7boh";
	certezza(stringa5);
	printf("Test Certezza(\"45trh7boh\"): Atteso = \"45trh7si\", Calcolato = \"%s\" \n", stringa5);

	/* Stringa con multiple sottostringhe 'boh' */
	char stringa6[] = "Loboh78boh196tyBb66boh";
	certezza(stringa6);
	printf("Test Certezza(\"Loboh78boh196tyBb66boh\"): Atteso = \"Losi78si196tyBb66si\", Calcolato = \"%s\" \n", stringa6);

}