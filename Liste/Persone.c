#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Lstringa 20

/* Strutture */
typedef struct Data {
	int giorno;
	int mese;
	int anno;
} DATA;

typedef struct Generalita {
	char nome[Lstringa];
	char cognome[Lstringa];
	DATA nascita;
} PERS;

typedef struct Lista {
	PERS persona;
	struct Lista *next;
} N;

/* Dichiarazione funzioni di supporto */
void reminder();
int calendario(int g, int m, int a);
void campoDati(N *leggi);
void inserisciInCoda(N **nuovo);
void stampaPersona(PERS *stampa);
void visualizzaLista(N *people);
void cancellaTesta(N **people);
void salvaSuBinario(N *lista);
void leggiDaBinario(N **crea);

/* Corpo del programma */
int main() {
	N *persone;
	leggiDaBinario(&persone);
	int scelta = -1;

	while (scelta != 0) {
		reminder();
		printf("Inserisci codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInCoda(&persone);
		else if (scelta == 2)
			visualizzaLista(persone);
		else if (scelta == 3)
			cancellaTesta(&persone);
	}
	/* Salvataggio su file */
	salvaSuBinario(persone);
	/* Chiusura programma */
	printf("\nChiusura programma...\n");
}

/* ------> Definizione funzioni secondarie <------ */

/* Funzione che stampa a schermo i comandi (e le funzionalità associate) a disposizione dell'utente all'interno del programma */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci una persona in coda alla lista.");
	printf("\n2 - Visualizza la lista corrente di persone.");
	printf("\n3 - Elimina la testa della lista.\n\n");
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

/* Funzione che legge da tastiera i dati da inserire nel nodo ricevuto come parametro */
void campoDati(N *leggi) {
	printf("\nRegistrazione in corso...\n");
	printf("\nInserisci nome : ");
	fgets(leggi->persona.nome, Lstringa, stdin);
	leggi->persona.nome[strlen(leggi->persona.nome) - 1] = '\0';

	printf("Inserisci cognome : ");
	fgets(leggi->persona.cognome, Lstringa, stdin);
	leggi->persona.cognome[strlen(leggi->persona.cognome) - 1] = '\0';

	do {
		printf("\nData di nascita...\n");
		printf("\nGiorno : ");
		scanf("%d", &leggi->persona.nascita.giorno);
		printf("Mese : ");
		scanf("%d", &leggi->persona.nascita.mese);
		printf("Anno : ");
		scanf("%d", &leggi->persona.nascita.anno);

		if (!calendario(leggi->persona.nascita.giorno, leggi->persona.nascita.mese, leggi->persona.nascita.anno))
			printf("\nReinserisci i dati: registrazione fallita...\n");
	} while (!calendario(leggi->persona.nascita.giorno, leggi->persona.nascita.mese, leggi->persona.nascita.anno));
}

/* Funzione che inserisce un elemento in coda alla lista */
/* Testa della lista passata per indirizzo */
void inserisciInCoda(N **nuovo) {
	N *registra = malloc(sizeof(N));	// Alloco nodo per registrare nuovo capo nell'heap

	campoDati(registra);				// Leggo il campo dati del nodo da registrare in lista
	registra->next = NULL;

	/* Caso speciale : la lista è vuota quindi diventa un inserimento in testa */
	if (*nuovo == NULL)
		*nuovo = registra;				// Collego i nodi e esco
	else {
		/* Presente qualcosa in lista : mi appoggio a un altro nodo arrivo a fine lista e registro quanto letto */
		N *appoggio = *nuovo;			// Dichiaro nodo d'appoggio
		/* Arrivo a fine lista */
		while (appoggio->next != NULL) {
			appoggio = appoggio->next;	// Vai avanti
		}
		appoggio->next = registra;		// Memorizzo a fine lista il nuovo capo
	}
}

void stampaPersona(PERS *stampa) {
	printf("\nNome : %s", stampa->nome);
	printf("\nCognome : %s", stampa->cognome);
	printf("\nData di nascita : %d/%d/%d\n", stampa->nascita.giorno, stampa->nascita.mese, stampa->nascita.anno);
}

void visualizzaLista(N *people) {
	if (people == NULL)
		printf("\nLista vuota...\n");
	else {
		printf("\nREGISTRO PERSONE :\n");
		while (people != NULL) {
			stampaPersona(&people->persona);
			people = people->next;
		}
	}
}

void cancellaTesta(N **people) {
	if (*people == NULL)
		printf("\nNon c'%c nulla cancellare...\n", 138);
	else {
		N *appoggio = *people;
		*people = (*people)->next;
		free(appoggio);
		printf("\nCancellazione effettuata...\n");
	}
}

/* Funzione che salva il contenuto di una lista su file */
void salvaSuBinario(N *lista) {
	FILE *salva = fopen("Registro.dat", "wb");

	if (salva == NULL)
		printf("\nApertura file fallita...\n");
	else {
		printf("\nSalvataggio in corso...");
		while (lista != NULL) {
			fwrite(&lista->persona, sizeof(PERS), 1, salva);
			lista = lista->next;
		}
		printf("\nSalvataggio effettuato...");
		fclose(salva);
	}
}

/* Funzione che legge il contenuto di un file e lo inserisce in una lista */
void leggiDaBinario(N **crea) {
	*crea = NULL;

	FILE *leggi = fopen("Registro.dat", "rb");

	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		PERS lettura;
		if (fread(&lettura, sizeof(PERS), 1, leggi) != EOF) {
			N *memorizza = malloc(sizeof(N));
			memorizza->persona = lettura;
			*crea = memorizza;
			while (fread(&lettura, sizeof(PERS), 1, leggi) > 0) {
				memorizza->next = malloc(sizeof(N));
				memorizza = memorizza->next;
				memorizza->persona = lettura;
			}
			memorizza->next = NULL;
			printf("\nLettura effettuata...");
			printf("\nDati recuperati...\n");
		}
		else {
			printf("\nFile vuoto...\n");
		}
		fclose(leggi);
	}
}
