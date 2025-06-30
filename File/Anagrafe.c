#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che contiene informazioni sull'indirizzo */
typedef struct Indirizzo {
	char via[30];
	int civico;
	char city[30];
} IND;

/* Struct che contiene informazioni sulla data di nascita */
typedef struct Nascita {
	int giorno;
	int mese;
	int anno;
} DATA;

/* Struct che contiene tutte le informazioni della persona da registrare */
typedef struct Anagrafe {
	char nome[30];
	char cognome[30];
	DATA data;
	IND ubicazione;
} PERSONA;

/* Dichiarazione funzioni secondarie */
void reminder();
void registrazione(PERSONA *new);
int calendario(int g, int m, int a);
int cancellaPersona(PERSONA *persona, char *cercaNome, char *cercaCognome, int lung);
void cercaPersona(PERSONA *persona, char *cercaNome, char *cercaCognome, int lung);
void stampaDati(PERSONA *persona);
int leggiDaFile(PERSONA *anagrafe);
void salvaSuFile(PERSONA *anagrafe, int lung);

/* Funzione principale */
int main(){
	printf("\nSei a capo di un'anagrafe.\n");
	reminder();

	/* Input */
	int i = 0;					// Contatore
	char comando = '0';			// Codice comando con funzionalità associata
	char cercaNome[30];			// Nome cercato (3)
	char cercaCognome[30];		// Cognome cercato (3)
	PERSONA anagrafe[30];		// Array di struct

	/* Leggo anagrafe salvata su file e salvo la lunghezza nel contatore */
	i = leggiDaFile(anagrafe);

	/* Ciclo di lettura codici comando */
	while (comando == '0' || comando == '1' || comando == '2' || comando == '3' || comando == '4') {
		/* Leggo codice da tastiera */
		printf("\nInserisci un codice comando: ");
		scanf("%c%*c", &comando);

		if (comando == '0')
			reminder();
		if (comando == '1') {
			/* Lista piena */
			if (i == 30) {
				printf("\nNon %c possibile eseguire una nuova registrazione. Cancella prima qualcuno dalla lista.\n", 138);
			}
			/* Registro persone finchè non riempio la sequenza */
			else {
				registrazione(anagrafe + i);
				i++;
			}			
		}
		if (comando == '2' || comando == '3') {
			if (comando == '2')
				printf("\nInserisci nome e cognome di chi vuoi eliminare dalla lista.\n");
			if (comando == '3')
				printf("\nInserisci nome e cognome di chi vuoi cercare nella lista.\n");

			/* Legge nome da cercare / eliminare */
			printf("Nome : ");
			fgets(cercaNome, 30, stdin);
			cercaNome[strlen(cercaNome) - 1] = '\0';

			/* Legge cognome da cercare / eliminare */
			printf("Cognome : ");
			fgets(cercaCognome, 30, stdin);
			cercaCognome[strlen(cercaCognome) - 1] = '\0';

			if (comando == '2'){
				/* Trasformo il contatore di elementi inseriti e che segna anche la prima
				 * posizione libera nell'array avendo eliminato degli elementi dalla lista */
				i = i - cancellaPersona(anagrafe, cercaNome, cercaCognome, i);
			}
			else {
				/* Invoca funzione per cercare persona con nome e cognome inserito */
				cercaPersona(anagrafe, cercaNome, cercaCognome, i);
			}
		}
		if (comando == '4') {
			/* Output */
			for(int j = 0; j < i; j++) {
				stampaDati(anagrafe + j);
			}
		}
	}
	/* Salvo lista corrente su file */
	salvaSuFile(anagrafe, i);

	/* Fine programma */
	printf("\nChiusura programma...");
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione che stampa a schermo la lista di codici (con funzioni associate) contenuti nel programma */
void reminder(){
	printf("\n0 - Stampa a schermo un messaggio che ricorda all'utente i codici e le funzionalit%c associate all'interno del programma.", 133);
	printf("\n1 - Registra una persona all'anagrafe");
	printf("\n2 - Cancella i dati anagrafici di una persona.");
	printf("\n3 - Ricerca la presenza di una persona in lista dati nome e cognome e visualizza i suoi dati nel caso in cui esista");
	printf("\n4 - Visualizza l'intera anagrafe.\n");
}

/* Funzione che si occupa della registrazione di nuove persone all'anagrafe
 * Legge da tastiera i dati */
void registrazione(PERSONA *new){
	printf("\nNuova registrazione: inserisci i dati richiesti.\n");

	/* Lettura delle generalità */
	printf("\nGENERALITA'");
	/* Lettura del nome */
	printf("\nNome : ");
	fgets(new->nome, 30, stdin);
	new->nome[strlen(new->nome) - 1] = '\0';

	/* Lettura del cognome */
	printf("Cognome : ");
	fgets(new->cognome, 30, stdin);
	new->cognome[strlen(new->cognome) - 1] = '\0';

	/* Lettura dei dati di nascita */
	printf("\nDATA DI NASCITA");
	printf("\nNato il giorno ");
	scanf("%d", &new->data.giorno);
	printf("Mese : ");
	scanf("%d", &new->data.mese);
	printf("Anno : ");
	scanf("%d%*c", &new->data.anno);

	/* Richiamo la funzione per controllare se i dati sono corretti / verosimili */
	while(!calendario(new->data.giorno, new->data.mese, new->data.anno)) {
		printf("\nRegistazione non riuscita: i dati non sono corretti. Inseriscili di nuovo.\n");
		printf("\nGiorno : ");
		scanf("%d", &new->data.giorno);
		printf("Mese : ");
		scanf("%d", &new->data.mese);
		printf("Anno : ");
		scanf("%d%*c", &new->data.anno);
	}

	/* Lettura dei dati di residenza */
	printf("\nRESIDENZA");
	printf("\nIndirizzo : ");
	fgets(new->ubicazione.via, 30, stdin);
	new->ubicazione.via[strlen(new->ubicazione.via) - 1] = '\0';

	printf("Numero civico : ");
	scanf("%d%*c", &new->ubicazione.civico);

	printf("Citt%c : ", 133);
	fgets(new->ubicazione.city, 30, stdin);
	new->ubicazione.city[strlen(new->ubicazione.city) - 1] = '\0';
}

/* Funzione che rivece in input le variabili giorno, mese e anno e controlla che siano
 * verosimili. Ritorna un valore booleano */
int calendario(int g, int m, int a){
	int corretto = 1;					// Variabile booleana inizializzata a TRUE

	/* Primo controllo : i dati rientrano nel calendario ? */
	if((g > 0 && g < 32) && (m > 0 && m < 13) && a >= 0) {

		/* Controllo i mesi da 30 giorni */
		if(m == 4 || m == 6 || m == 9 || m == 11) {
			if(g == 31) {
				corretto = 0;
			}
		}

		/* Controllo febbraio */
		else if(m == 2) {
			/* Anno bisestile ? (29 g) */
			if(((a%4 == 0) && (a%100 != 0)) || (a%400 == 0)) {
				if(g > 29) {
					corretto = 0;
				}
			}
			/* Anno non bisestile (28 g) */
			else {
				if(g > 28) {
					corretto = 0;
				}
			}
		}
	}
	/* Valori errati : modifico il valore della variabile booleana */
	else
		corretto = 0;

	return corretto;				// Valore di ritorno
}

/* Funzione che riceve in input due stringhe (una per il nome e una per il cognome) e cerca all'interno
 * dell'array la persona con il nome e il cognome desiderato */
/* Se l'operazione ha successo, elimina la persona dalla lista */
int cancellaPersona(PERSONA *persona, char *cercaNome, char *cercaCognome, int lung){
	int eliminati = 0;			// Conta le persone eliminate		

	/* Sfoglio la lista di elementi dell'anagrafe */
	for(int i = 0; i < lung; i++) {
		/* Ricerca del nome */
		if(strcmp((persona + i)->nome, cercaNome) == 0) {
			/* Ricerca del cognome */
			if(strcmp((persona + i)->cognome, cercaCognome) == 0) {
				eliminati++;											// Incremento contatore

				printf("\nCancellazione in corso... Persona cancellata.\n");
				/* Cancello l'elemento trovato dalla lista */
				for(int k = i; k < lung; k++) {
					*(persona + k) = *(persona + (k + 1));
				}
			}
		}
	}
	/* Ritorno un contatore delle persone eliminate in modo tale da poter aggiornare contatore nel main */
	return eliminati;					// Valore di ritorno
}

/* Funzione che riceve in input due stringhe (una per il nome e una per il cognome) e cerca all'interno
 * dell'array la persona con il nome e il cognome desiderato */
/* Se l'operazione ha successo, stampa i dati della/e persona/e trovata/e */
void cercaPersona(PERSONA *persona, char *cercaNome, char *cercaCognome, int lung){
	/* Sfoglio la lista di elementi dell'anagrafe */
	for(int i = 0; i < lung; i++) {
		/* Ricerca del nome */
		if(strcmp((persona + i)->nome, cercaNome) == 0) {
			/* Ricerca del cognome */
			if(strcmp((persona + i)->cognome, cercaCognome) == 0) {
	
				/* Output */
				printf("\nTrovato!\n");
				stampaDati(persona + i);
			}
		}
	}
}

/* Funzione che stampa a schermo l'intera anagrafe */
void stampaDati(PERSONA *persona){
	/* Output */
	printf("\nNome : %s , Cognome : %s", persona->nome, persona->cognome);
	printf("\nData di nascita : %d/%d/%d", persona->data.giorno, persona->data.mese, persona->data.anno);
	printf("\nResidenza : %s", persona->ubicazione.city);
	printf("\nIndirizzo : %s , Numero civico : %d\n", persona->ubicazione.via, persona->ubicazione.civico);
}

/* Funzione che legge da file */
int leggiDaFile(PERSONA *anagrafe) {
	FILE *fp = fopen("Lista1.txt", "r");

	int nuovaL = 0;

	if(fp == NULL) {
		printf("\nNon sono riuscito ad aprire il file.\n");
	}
	else {
		while(!feof(fp)) {
			fscanf(fp, "%s", &(anagrafe + nuovaL)->nome);
			fscanf(fp, "%s", &(anagrafe + nuovaL)->cognome);
			fscanf(fp, "%d", &(anagrafe + nuovaL)->data.giorno);
			fscanf(fp, "%d", &(anagrafe + nuovaL)->data.mese);
			fscanf(fp, "%d", &(anagrafe + nuovaL)->data.anno);
			fscanf(fp, "%s", &(anagrafe + nuovaL)->ubicazione.city);
			fscanf(fp, "%d", &(anagrafe + nuovaL)->ubicazione.civico);
			fscanf(fp, "%*c");
			fscanf(fp, "%[^\n]", &(anagrafe + nuovaL)->ubicazione.via);
			nuovaL++;
		}
	}
	fclose(fp);
	return nuovaL;
}

/* Funzione che salva su file */
void salvaSuFile(PERSONA *anagrafe, int lung) {
	FILE *fp = fopen("Lista1.txt", "w");

	if(fp == NULL) {
		printf("\nNon sono riuscito ad aprire il file.\n");
	}
	else {
		for(int k = 0; k < lung; k++){			
			fprintf(fp, "%s ", (anagrafe + k)->nome);
			fprintf(fp, "%s ", (anagrafe + k)->cognome);
			fprintf(fp, "%d ", (anagrafe + k)->data.giorno);
			fprintf(fp, "%d ", (anagrafe + k)->data.mese);
			fprintf(fp, "%d ", (anagrafe + k)->data.anno);
			fprintf(fp, "%s ", (anagrafe + k)->ubicazione.city);
			fprintf(fp, "%d ", (anagrafe + k)->ubicazione.civico);
			fprintf(fp, "%s", (anagrafe + k)->ubicazione.via);
			if(k<lung-1)
				fprintf(fp, "\n");
		}
	}
	fclose(fp);
}

