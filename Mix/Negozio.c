/* */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LUNG 40			// Lunghezza stringa del nome del capo d'abbigliamento

/* Strutture */
/* Struct che gestisce i dati di un capo d'abbigliamento */
typedef struct Abbigliamento {
	char nome[LUNG];
	char taglia[5];
	float prezzo;
	int quanti;
} SHOP;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	SHOP negozio;
	struct Lista *next;
} N;

/* Dichiarazione funzioni secondarie */
void introduzione();
void reminder();
void primaMaiuscola(char *stringa);
void campoDati(N *leggi);
void inserisciInTesta(N **nuovo);
void inserisciInCoda(N **nuovo);
void stampaDati(SHOP *item);
void visualizzaMagazzino(N *head);
int conta(N *head, char *stringa);
void ricerca(N *head);
void prezzoTot(N *lista);
void quantiTot(N *lista);
void scambia(N *n1, N *n2);
int nuovoMinimoP(SHOP *abb1, SHOP *abb2);
void ordinaPrezzo(N **ordina);
int nuovoMinimoQ(SHOP *abb1, SHOP *abb2);
void ordinaQuanti(N **ordina);
int nuovoMinimoN(SHOP *abb1, SHOP *abb2);
void ordinaNome(N **ordina);
void salvaSuFile(N *deposito);
void archivia(N *deposito);
/* Funzioni da aggiungere */
/*void cancellaPrezzo
void cancellaQuanti
void leggiDaFile
void recuperaArchiviati*/		// Recupera lista archivio

/* Corpo del programma */
int main() {
	/* Input */
	N *magazzino = NULL;
	int scelta = -1;

	introduzione();
	while (scelta != 0) {
		reminder();
		printf("Inserisci un codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInTesta(&magazzino);
		else if (scelta == 2)
			inserisciInCoda(&magazzino);
		else if (scelta == 3) {
			visualizzaMagazzino(magazzino);
			prezzoTot(magazzino);
			quantiTot(magazzino);
		}
		else if (scelta == 4)
			ricerca(magazzino);
		else if (scelta == 5)
			ordinaPrezzo(&magazzino);
		else if (scelta == 6)
			ordinaQuanti(&magazzino);
		else if (scelta == 7)
			ordinaNome(&magazzino);
	}
	/* Salva il contenuto della lista su file */
	salvaSuFile(magazzino);
	/* Aggiungi dati all'archivio */
	archivia(magazzino);
	/* Chiusura del programma */
	printf("\nChiusura del programma...\n");
}

/* -------> Definizione delle funzioni di supporto <------- */

/* Funzione che introduce l'utente nel programma attraverso una breve descrizione */
void introduzione() {
	printf("\nCiao utente, questo programma virtualizza il magazzino di un negozio.");
	printf("\nPuoi gestirlo come vuoi, utilizzando i codici comandi per comunicare al sistema la funzionalit%c", 133);
	printf("\nche vuoi fargli eseguire. Qui sotto sono riportati i comandi...\n");
}

/* Funzione che stampa a schermo i comandi (e le funzionalità associate) a disposizione dell'utente all'interno del programma */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un elemento in testa al magazzino.");
	printf("\n2 - Inserisci un elemento in coda al magazzino.");
	printf("\n3 - Visualizza la lista corrente di elementi contenuti nel magazzino, prezzo e quantit%c totali dei capi.", 133);
	printf("\n4 - Legge un nome da tastiera e cerca e stampa i capi con quel nome.");
	printf("\n5 - Ordina la lista in ordine di prezzo.");
	printf("\n6 - Ordina la lista in ordine di quantit%c.", 133);
	printf("\n7 - Ordina la lista in ordine alfabetico.\n\n");
}

/* Funzione che riceve come parametro una stringa e la modifica rendendo maiuscola la prima lettera se necessario */
void primaMaiuscola(char *stringa) {
	if (stringa[0] >= 'a' && stringa[0] <= 'z')
		stringa[0] += 'A' - 'a';					// Trasformo in maiuscola
}

/* Funzione che legge da tastiera i dati da inserire nel nodo ricevuto come parametro */
void campoDati(N *leggi) {
	printf("\nInserisci i dati del prossimo pezzo da aggiungere al magazzino...\n");
	/* Leggi nome del capo */
	printf("\nNome : ");
	fgets(leggi->negozio.nome, LUNG, stdin);
	leggi->negozio.nome[strlen(leggi->negozio.nome) - 1] = '\0';
	primaMaiuscola(leggi->negozio.nome);				// Modifico stringa

	/* Leggi taglia */
	printf("Taglia : ");
	fgets(leggi->negozio.taglia, 5, stdin);
	leggi->negozio.taglia[strlen(leggi->negozio.taglia) - 1] = '\0';
	primaMaiuscola(leggi->negozio.taglia);				// Modifico stringa

	/* Leggi prezzo */
	do {
		printf("Prezzo : ");
		scanf("%f", &leggi->negozio.prezzo);
		/* Il prezzo inserito non rispetta le condizioni */
		if (leggi->negozio.prezzo <= 0)
			printf("\nRegistrazione fallita...\nReinserisci il prezzo del capo...\n");
	} while (leggi->negozio.prezzo <= 0);

	/* Leggi quantità */
	do {		
		printf("Quantit%c : ", 133);
		scanf("%d", &leggi->negozio.quanti);
		/* La quantità inserita non rispetta le condizioni */
		if (leggi->negozio.quanti < 0)
			printf("\nRegistrazione fallita...\nReinserisci la quantit%c del capo...\n", 133);
	} while (leggi->negozio.quanti < 0);
}

/* Funzione che inserisce un elemento in testa alla lista */
/* Testa della lista passata per indirizzo */
void inserisciInTesta(N **nuovo) {
	N *registra = malloc(sizeof(N));	// Alloco nodo per registrare nuovo capo nell'heap

	campoDati(registra);				// Leggo il campo dati del nodo da registrare in lista

	registra->next = *nuovo;			// Collego i nodi
	*nuovo = registra;					// Collego la testa del nuovo nodo alla lista che mi ritrovo nel main
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

/* Funzione che stampa a schermo i dati di un pezzo d'abbigliamento */
void stampaDati(SHOP *item) {
	printf("\nNome : %s , Taglia : %s", item->nome, item->taglia);
	printf("\nPrezzo : %.2f$ , Quantit%c : %d unit%c\n", item->prezzo, 133, item->quanti, 133);
}

/* Funzione che stampa a schermo la lista di pezzi d'abbigliamento nel magazzino */
void visualizzaMagazzino(N *head) {
	/* Lista vuota ? */
	if (head == NULL)
		printf("\nLista vuota...\n");
	else {
		printf("\nContenuto del magazzino :\n");
		/* Controllo tutta la lista */
		while (head != NULL) {
			/* Output */
			stampaDati(&head->negozio);
			head = head->next;			// Passo al nodo successivo della lista
		}
	}
}

/* Funzione che conta quanti elementi con il nome dato da tastiera in 'ricerca' si trovano in magazzino */
int conta(N *head, char *stringa) {
	int trovati = 0;					// Contatore di capi con il nome passato trovati
	/* Controllo la lista fino all'ultimo nodo */
	while (head != NULL) {
		/* Confronto i nomi dei capi */
		if (strcmp(head->negozio.nome, stringa) == 0)
			trovati++;					// Ne ho trovato uno
		head = head->next;				// Vai avanti
	}
	return trovati;						// Valore di ritorno
}

/* Funzione che legge un nome da tastiera e cerca e stampa il/i capo/i in magazzino con quel nome */
void ricerca(N *head) {
	/* Lista vuota */
	if (head == NULL)
		printf("\nLista vuota...\n");
	else {	
		char daCercare[LUNG];			// Nome da cercare
		/* Lettura */
		printf("\nCome si chiama il pezzo da cercare ?\n");
		fgets(daCercare, LUNG, stdin);
		daCercare[strlen(daCercare) - 1] = '\0';
		primaMaiuscola(daCercare);					// Modifico la stringa da cercare

		int stampa = conta(head, daCercare);		// Numero di persone con nome cercato
		printf("Ho trovato %d capo/i con questo nome.\n", stampa);
		/* Vado avanti fino all'ultimo nodo o finchè non ho trovato tutti i capi */
		while (head != NULL && stampa != 0) {
			/* Ho trovato un capo con quel nome: lo stampo */
			if (strcmp(head->negozio.nome, daCercare) == 0) {
				stampaDati(&head->negozio);
				stampa--;							// Uno in meno
			}
			head = head->next;						// Nodo successivo
		}
	}
}

/* Funzione che stampa a schermo il prezzo totale dei capi in magazzino */
void prezzoTot(N *lista) {
	float somma = 0;				// Somma prezzi

	if (lista != NULL) {
		/* Se la lista non è vuota somma i prezzi di ogni nodo fino ad arriva al nodo NULL */
		while (lista != NULL) {
			somma += lista->negozio.prezzo;
			lista = lista->next;				// Prossimo nodo
		}
		/* Output */
		printf("\nPrezzo totale dei capi in magazzino : %.2f$", somma);
	}
}

/* Funzione che stampa a schermo il numero totale di capi in magazzino */
void quantiTot(N *lista) {
	int conta = 0;					// Somma numero di unità dei capi

	if (lista != NULL) {
		/* Se la lista non è vuota somma i numeri di unità di ogni nodo fino ad arriva al nodo NULL */
		while (lista != NULL) {
			conta += lista->negozio.quanti;
			lista = lista->next;				// Vai avanti
		}
		/* Output */
		printf("\nNumero totale di capi in magazzino : %d unit%c\n", conta, 133);
	}
}

/* Funzione che scambia i campi dati di due nodi ricevuti come parametri in input */
void scambia(N *n1, N *n2) {
	SHOP temp;					// Variabile d'appoggio
	temp = n1->negozio;			// Salvo campo dati del primo nodo così da non perdere nulla
	n1->negozio = n2->negozio;
	n2->negozio = temp;
}

/* Funzione che riceve due struct come parametro e controlla se il secondo precede (va prima del) il primo */
/* Il secondo (nodo di controllo nella funzione) precede il primo (nodo "minimo" nella funzione) se
 * il prezzo del secondo è maggiore del primo oppure, a parità di prezzo, se  il secondo presenta un numero di unità
 * minore oppure (ancora), a parità di prezzo e quantità, se il secondo va prima in ordina alfabetico */
int nuovoMinimoP(SHOP *abb1, SHOP *abb2) {
	return ((abb1->prezzo < abb2->prezzo) || (abb1->prezzo == abb2->prezzo && abb1->quanti > abb2->quanti)
			 || (abb1->prezzo == abb2->prezzo && abb1->quanti == abb2->quanti && strcmp(abb1->nome, abb2->nome) > 0));
}

/* Funzione che riceve come parametro l'indirizzo della testa della lista e la ordina per prezzo decrescente */
void ordinaPrezzo(N **ordina) {
	N *check;					// Nodo di controllo (scorre i campi dati)
	N *minimo;					// Nodo che memorizza minimo
	N *appoggio;				// Nodo d'appoggio per la lista

	/* Esco subito se non ho nulla in testa alla lista o se ho un solo elemento in essa */
	if (*ordina == NULL || (*ordina)->next == NULL)
		printf("\nNon c'%c nulla da ordinare.\n", 138);
	else {
		appoggio = *ordina;		// Collego la testa della lista passata al nodo d'appoggio
		
		/* Vado avanti fino al penultimo */
		while (appoggio->next != NULL) {
			minimo = appoggio;				// Aggiorno nodo del minimo
			check = appoggio->next;			// Aggiorno nodo di controllo

			/* Controllo tutti i valori rimasti in lista */
			while (check != NULL) {
				/* Ho trovato un nuovo minimo (uso funzione relativa al prezzo) */
				/* Aggiorno il minimo */
				if (nuovoMinimoP(&minimo->negozio, &check->negozio))
					minimo = check;
				check = check->next;		// Passo al prossimo nodo da controllare
			}
			scambia(appoggio, minimo);		// Scambio i campi dati del minimo memorizzato con quello del nodo d'appoggio corrente
			appoggio = appoggio->next;		// Vai avanti
		}
	}
}

/* Funzione che riceve due struct come parametro e controlla se il secondo precede il primo */
/* Il secondo (nodo di controllo nella funzione) precede il primo (nodo "minimo" nella funzione) se
 * il numero di unità del secondo è minore di quello del primo oppure, a parità di quantità, se il secondo
 * costa meno del primo oppure (ancora), a parità di quantità e di prezzo, se il secondo precede il primo
 * nell'alfabeto */
int nuovoMinimoQ(SHOP *abb1, SHOP *abb2) {
	return ((abb1->quanti > abb2->quanti) || (abb1->quanti == abb2->quanti && abb1->prezzo > abb2->prezzo)
			 || (abb1->quanti == abb2->quanti && abb1->prezzo == abb2->prezzo && strcmp(abb1->nome, abb2->nome) > 0));
}

/* Funzione che riceve come parametro l'indirizzo della testa della lista e la ordina per quantità crescente */
void ordinaQuanti(N **ordina) {
	N *check;					// Nodo di controllo (scorre i campi dati)
	N *minimo;					// Nodo che memorizza minimo
	N *appoggio;				// Nodo d'appoggio per la lista

	/* Esco subito se non ho nulla in testa alla lista o se ho un solo elemento in essa */
	if (*ordina == NULL || (*ordina)->next == NULL)
		printf("\nNon c'%c nulla da ordinare.\n", 138);
	else {
		appoggio = *ordina;		// Collego la testa della lista passata al nodo d'appoggio

		/* Vado avanti fino al penultimo */
		while (appoggio->next != NULL) {
			minimo = appoggio;				// Aggiorno nodo del minimo
			check = appoggio->next;			// Aggiorno nodo di controllo

			/* Controllo tutti i valori rimasti in lista */
			while (check != NULL) {
				/* Ho trovato un nuovo minimo (uso funzione relativa alla quantità) */
				/* Aggiorno il minimo */
				if (nuovoMinimoQ(&minimo->negozio, &check->negozio))
					minimo = check;
				check = check->next;		// Passo al prossimo nodo da controllare
			}
			scambia(appoggio, minimo);		// Scambio i campi dati del minimo memorizzato con quello del nodo d'appoggio corrente
			appoggio = appoggio->next;		// Vai avanti
		}
	}
}

/* Funzione che riceve due struct come parametro e controlla se il secondo precede il primo */
/* Il secondo (nodo di controllo nella funzione) precede il primo (nodo "minimo" nella funzione) se
 * va prima per ordine alfabetico oppure, a parità di nome, se costa più del primo oppure (ancora),
 * a parità di nome e di prezzo, se presenta un numero di unità maggiore rispetto al primo */
int nuovoMinimoN(SHOP *abb1, SHOP *abb2) {
	return ((strcmp(abb1->nome, abb2->nome) > 0) || (strcmp(abb1->nome, abb2->nome) == 0 && abb1->prezzo < abb2->prezzo)
			|| (strcmp(abb1->nome, abb2->nome) == 0 && abb1->prezzo == abb2->prezzo && abb1->quanti < abb2->quanti));
}

/* Funzione che ordina gli elementi della lista in ordine alfabetico */
void ordinaNome(N **ordina) {
	N *check;					// Nodo di controllo (scorre i campi dati)
	N *minimo;					// Nodo che memorizza minimo
	N *appoggio;				// Nodo d'appoggio per la lista

	/* Esco subito se non ho nulla in testa alla lista o se ho un solo elemento in essa */
	if (*ordina == NULL || (*ordina)->next == NULL)
		printf("\nNon c'%c nulla da ordinare.\n", 138);
	else {
		appoggio = *ordina;		// Collego la testa della lista passata al nodo d'appoggio
		
		/* Vado avanti fino al penultimo */
		while (appoggio->next != NULL) {
			minimo = appoggio;				// Aggiorno nodo del minimo
			check = appoggio->next;			// Aggiorno nodo di controllo

			/* Controllo tutti i valori rimasti in lista */
			while (check != NULL) {
				/* Ho trovato un nuovo minimo (uso funzione relativa al nome) */
				/* Aggiorno il minimo */
				if (nuovoMinimoN(&minimo->negozio, &check->negozio))
					minimo = check;
				check = check->next;		// Passo al prossimo nodo da controllare
			}
			scambia(appoggio, minimo);		// Scambio i campi dati del minimo memorizzato con quello del nodo d'appoggio corrente
			appoggio = appoggio->next;		// Vai avanti
		}
	}
}

/* Funzione che salva il contenuto della lista su un file */
void salvaSuFile(N *deposito) {
	/* Apro file di testo in scrittura */
	FILE *fpout = fopen("Outlet.txt", "w");

	if (fpout == NULL)
		printf("\nApertura file fallita...\n");
	else {
		while (deposito != NULL) {
			fprintf(fpout, "%s\n%s\n", deposito->negozio.nome, deposito->negozio.taglia);
			fprintf(fpout, "%.2f %d\n\n", deposito->negozio.prezzo, deposito->negozio.quanti);
			deposito = deposito->next;
		}
		printf("\nSalvataggio effettuato...");
		fclose(fpout);
	}
}

/* Funzione che salva il contenuto della lista nell'archivio generale del magazzino */
void archivia(N *deposito) {
	/* Apro file di testo in scrittura */
	FILE *archivio = fopen("Deposito.txt", "a");

	if (archivio == NULL)
		printf("\nApertura file fallita...\n");
	else {
		while (deposito != NULL) {
			fprintf(archivio, "%s\n%s\n", deposito->negozio.nome, deposito->negozio.taglia);
			fprintf(archivio, "%.2f %d\n\n", deposito->negozio.prezzo, deposito->negozio.quanti);
			deposito = deposito->next;
		}
		printf("\nDati archiviati...");
		fclose(archivio);
	}
}




