/* Realizzare un'applicazione Fritti per gestire il menù di una pizzeria: 
 * Definire due strutture, una per rappresentare un elemento della lista ed una per rappresentare un fritto che fa parte del menù. 
 * In particolare, l’applicazione deve gestire ciascun fritto come una struttura con tre campi: 
  	
  		- Il primo campo è una stringa che indica il nome del fritto (ad esempio “fiori di zucca”), 
 		- Il secondo campo è un valore reale che indica il prezzo del fritto, 
 		- Il terzo campo è un carattere ‘s’ o ‘f’ che indica se il fritto è surgelato o fresco.

 * Definire una funzione che visualizza il menù, stampando per ciascun fritto il nome, il prezzo e se il fritto è surgelato oppure no.
 * Definire una funzione che inserisce un fritto in coda al menù.
 * Definire una funzione che ordina la lista così che i fritti freschi compaiano prima di quelli surgelati
 * e così che i fritti freschi (e quelli surgelati) siano fra loro ordinati per prezzo.
 * Definire una funzione main che crea la lista e gestisce l’interazione con l’utente. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che gestisce i dati del fritto */
typedef struct Fritto {
	char nome[30];
	float prezzo;
	char tipo;
} F;

/* Struct che gestisce un nodo della lista */
typedef struct Nodo {
	F fritto;
	struct Nodo *next;
} N;

/* Dichiarazione funzioni secondarie */
void reminder();
void campoDati(N *nodo);
void inserimentoInCoda(N **puntaHead);
void stampaFritto(F *fri);
void visualizzaMenu(N *head);
int daScambiare(F *f1, F *f2);
void scambiaNodi(N *n1, N *n2);
void ordinaMenu(N **puntaHead);
void salvataggio(N *menu);
void leggiDaFile(N **crea);

/* Corpo del programma */
int main() {
	/* Input */
	N *head;						// Inizializzo la lista
	/* Lista creata attraverso la lettura di un file */
	leggiDaFile(&head);
	int scelta = -1;				// Variabile comando
	printf("\nCiao utente sono un programma che gestisce il menu' di una pizzeria.\n");

	/* Ciclo d'interazione compilatore utente attraverso l'inserimento di un intero da tastiera */
	while (scelta != 0) {
		reminder();
		printf("\nInserisci codice comando : ");
		scanf("%d%*c", &scelta);					// Lettura intero che funge da codice comando

		/* Funzioni */
		if (scelta == 1)
			inserimentoInCoda(&head);
		else if (scelta == 2)
			visualizzaMenu(head);
		else if (scelta == 3)
			ordinaMenu(&head);
	}
	/* Salva lista su file */
	salvataggio(head);
	/* Chiusura programma */
	printf("\nChiusura programma.\n");
}


/* -------> Definzione funzioni secondarie <------- */

/* Funzione che stampa a schermo un messaggio che illustra i comandi (con funzionalità associate) a disposizione dell'utente */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un fritto in coda al menu'.");
	printf("\n2 - Visualizza il menu' dei fritti.");
	printf("\n3 - Ordina la lista cosi' che i fritti freschi siano prima dei surgelati.\n    Fritti dello stesso tipo vengono ordinati per prezzo.\n");
}

/* Funzione che legge i dati di un fritto */
void campoDati(N *nodo) {
	printf("\nInserisci i dati del fritto...\n");
	/* Leggi nome */
	printf("\nNome del fritto : ");
	fgets(nodo->fritto.nome, 30, stdin);
	nodo->fritto.nome[strlen(nodo->fritto.nome) - 1] = '\0';

	/* Leggi prezzo */
	do {
		printf("Prezzo del fritto : ");
		scanf("%f%*c", &nodo->fritto.prezzo);
		if (nodo->fritto.prezzo < 0)
			printf("\nReinserisci il prezzo del fritto...\n");
	} while (nodo->fritto.prezzo < 0);

	/* Leggi tipo (surgelato o fresco) */
	do {
		printf("Tipo ('s' per surgelato, 'f' per fresco) : ");
		scanf("%c", &nodo->fritto.tipo);
		if (nodo->fritto.tipo != 's' && nodo->fritto.tipo != 'f')
			printf("\nReinserisci il tipo del fritto...\n");
	} while (nodo->fritto.tipo != 's' && nodo->fritto.tipo != 'f');
}

/* Funzione che inserisce un elemento in coda alla lista ricevendo l'indirizzo della testa nel main */
void inserimentoInCoda(N **puntaHead) {
	N *nuovoNodo = malloc(sizeof(N));		// Alloco nuovo nodo da leggere nell'heap
	/* Leggo campo dati del nuovo nodo */
	campoDati(nuovoNodo);
	nuovoNodo->next = NULL;					// Nodo successivo punta a NULL

	/* Se la lista è vuota diventa un inserimento in testa */
	if (*puntaHead == NULL)
		*puntaHead = nuovoNodo;
	/* Lista non vuota: mi appoggio a un altro nodo */
	else {
		N *appoggio = *puntaHead;
		/* Raggiungo la fine del nodo di appoggio */
		while (appoggio->next != NULL) {
			appoggio = appoggio->next;		// Vai avanti
		}
		appoggio->next = nuovoNodo;			// Salvo nella coda del nodo d'appoggio il nodo letto
	}
}

/* Funzione che stampa i dati di un fritto ricevuto come parametro */
void stampaFritto(F *fri) {
	/* Output */
	printf("\nNome del fritto : %s", fri->nome);
	printf("\nIl fritto costa %.2f $.", fri->prezzo);
	if (fri->tipo == 's')
		printf("\nFritto surgelato.\n");
	else
		printf("\nFritto fresco.\n");
}

/* Funzione che stampa il menù corrente di fritti della pizzeria */
void visualizzaMenu(N *menu) {
	/* Lista vuota */
	if (menu == NULL)
		printf("\nMenu' vuoto...\n");
	/* Presente del contenuto in lista */
	else {
		printf("\nEcco il menu':\n");
		/* Stampo finchè ho elementi in lista */
		while (menu != NULL) {
			stampaFritto(&menu->fritto);
			menu = menu->next;				// Passa al nodo successivo
		}
	}
}

/* Funzione che controlla se un elemento è da scambiare con un altro */
int daScambiare(F *f1, F *f2) {
	return ((f1->tipo == 's' && f2->tipo == 'f') || (f1->tipo == f2->tipo && f1->prezzo < f2->prezzo));
}

/* Funzione che scambia i dati di un fritto con un altro */
void scambiaNodi(N *n1, N *n2) {
	F fri;					// Variabile d'appoggio da mettere in testa
	fri = n1->fritto;
	n1->fritto = n2->fritto;
	n2->fritto = fri;
}

/* Funzione che ordina il menù a seconda del tipo del fritto. 
 * I fritti freschi prima dei surgelati. 
 * Fritti dello stesso tipo vengono ordinati per prezzo decrescente */
void ordinaMenu(N **puntaHead) {
	N *check;						// Lista che contiene i nodi controllati a ogni passo del while 
	N *minimo;						// Nodo che memorizza il minimo
	N *nuovo = *puntaHead;			// Nodo d'appoggio (ci collego la testa passata dal main per indirizzo)
									// Eventuali cambiamenti in "nodo" modificano la lista del main (meccanismo puntatori)

	/* While che serve sia a controllare se la lista è vuota (solo alla prima esecuzione)
	 * sia a leggere la lista tranne l'ultimo elemento (una volta entrati nel while) */
	while (nuovo != NULL && (nuovo)->next != NULL) {
		minimo = nuovo;					// Inizializzato il minimo
		check = (nuovo)->next;			// Inizializzata la lista da controllare
		/* Leggo tutti i nodi successivi */
		while (check != NULL) {
			if (daScambiare(&minimo->fritto, &check->fritto)) {
				/* Ho trovato valore da scambiare : memorizzo nuovo minimo */
				minimo = check;
			}
			check = check->next;		// Nodo di controllo successivo
		}
		/* Scambio ciò che è contenuto nel minimo con ciò che sta nell'attuale nodo d'appoggio */
		scambiaNodi(nuovo, minimo);
		nuovo = (nuovo)->next;			// Nodo d'appoggio successivo
	}
}

/* Funzione che salva gli elementi di una lista in un file */
void salvataggio(N *menu) {
	/* Apro file in scrittura */
	FILE *fpout = fopen("Menu'.txt", "w");

	/* Controllo apertura file */
	if (fpout == NULL)
		printf("\nApertura file fallita...\n");
	else {
		printf("\nSalvo la lista...");
		/* Vado avanti fino a fine lista */
		while (menu != NULL) {
			/* Stampa su file */
			fprintf(fpout, "%s\n%.2f %c\n", menu->fritto.nome, menu->fritto.prezzo, menu->fritto.tipo);
			menu = menu->next;				// Passo al nodo successivo
		}
		printf("\nSalvataggio effettuato...\n");
		/* Chiusura file di scrittura */
		fclose(fpout);
	}
} 

/* Funzione che legge il contenuto di un file e lo inserisci in una lista */
void leggiDaFile(N **crea) {
	*crea = NULL;					// Inizializzo la testa
	/* Apro file in lettura */
	FILE *fpin = fopen("Menu'.txt", "r");
	/* Apertura file non andata a buon fine */
	if (fpin == NULL) {
		printf("\nFile inesistente o apertura fallita...\n");
	}
	/* File aperto */
	else {
		F piatto;				// Variabile per appoggiarsi in lettura

		/* Leggo primo nodo se è presente qualcosa nel file */
		if (fscanf(fpin, "%[^\n]%*c%f%*c%c%*c", &piatto.nome, &piatto.prezzo, &piatto.tipo) > 0) {
			N *nuovo = malloc(sizeof(N));			// Alloco nodo nell'heap
			nuovo->fritto = piatto;					// Inserisco valori letti nel nodo
			*crea = nuovo;							// Collego nodo alla testa (doppio puntatore modifica automaticamente nel main)

			/* Leggo finchè c'è qualcosa da leggere */
			while (fscanf(fpin, "%[^\n]%*c%f%*c%c%*c", &piatto.nome, &piatto.prezzo, &piatto.tipo) > 0) {
				
				/* Ho qualcosa da leggere : alloco memoria nel nodo successivo, mi sposto nella lista
				 * e memorizzo ciò che ho letto nel contenuto del nodo corrente */
				nuovo->next = malloc(sizeof(N));
				nuovo = nuovo->next;
				nuovo->fritto = piatto;
			}
			nuovo->next = NULL;			// Fine lista : coda punta NULL
			printf("\nLettura effettuata...	\n");
		}
		/* Nulla nel file */
		else
			printf("\nFile vuoto...\n");
		/* Chiusura file di lettura */
		fclose(fpin);
	}
}

