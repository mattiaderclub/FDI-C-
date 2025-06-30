/* Programma che gestisce un laboratorio di computer */

/* Definire due struttura, per rappresentare un elemento della lista e un computer. l'applicazione deve gestire
 * ogni computer come una struttura con tre campi. Il primo campo indica il modello del computer, il secondo è
 * un codice identificativo intero che identifica il computer all'interno del laboratorio, il terzo è un array di 12
 * interi che indica l'indirizzo IP.

 * Definire una funzione che permette di visualizzare la lista di computer del laboratorio. Per ogni computer, devono
 * essere visualizzati modello, codice identificativo e indirizzo IP che va visualizzato inserendo un punto dopo ogni tripla
 * di cifre.

 * Definire una funzione che oltre alla lista prende come parametro un intero e restituisce 1 se esiste un computer in lista
 * con quel codice identificativo, 0 altrimenti.

 * Definire una funzione che cancella tutti i computer fissi. Informare l'utente di un'eventuale assenza di computer da cancellare

 * Definire una funzione che inserisce un nuovo coputer in coda alla lista. Il modello del computer e il codice IP devono essere
 * inseriti dall'utente, mentre il codice identificativo dev'essere il più piccolo intero positivo che non è già il codice di un altro
 * computer.

 * Il main deve inizializzare la lista da file e terminare salvando la lista corrente sullo stesso file */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che gestisce le informazioni del singolo computer */
typedef struct Info {
	char modello[20];
	char tipo;
	int IP[12];
	int codice;
} C;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	C computer;
	struct Lista *next;
} N;

/* Dichiarazione funzioni secondarie */
void reminder();
void campoDati(N *controllo, N *leggi);
void inserisciCoda(N **nuovo);
void stampaComputer(C *stampa);
void visualizzaLab(N *elenco);
int esisteComputer(N *sistema, int cerca);
int quantiFissi(N *head);

/* DA FARE */
void cancellaFissi(N **cancella);
void acquisizione(N **crea);
void salvataggio(N *database);

/* Corpo del programma */
int main() {
	/* Input */
	int scelta = -1;
	N *laboratorio = NULL;
	printf("\nBenvenuto nel sistema di un laboratorio di computer.\n");

	/* Ciclo d'interazione con l'utente */
	while (scelta != 0) {
		reminder();
		printf("\nInserisci il codice comando : ");
		scanf("%d%*c", &scelta);						// Legge codice comando

		/* Lista di funzioni associate ai vari codici comando */
		if (scelta == 1)
			inserisciCoda(&laboratorio);
		else if (scelta == 2)
			visualizzaLab(laboratorio);
		else if (scelta == 3)
			cancellaFissi(&laboratorio);
	}
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione funzioni di supporto <----- */

/* Funzione che stampa a schermo i comandi a disposizione dell'utente con le funzionalità del programma associate */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un computer in coda.");
	printf("\n2 - Visualizza la lista corrente di computer in laboratorio.");
	printf("\n3 - Cancella tutti i computer di tipo fisso all'interno della lista\n");
}

/* Funzione che riceve la testa di una lista e un intero da cercare e torna 1 se esiste un elemento in lista che
 * ha come codice identificativo quell'intero, 0 altrimenti. */
int esisteComputer(N *sistema, int cerca) {
	int ris = 0;
	/* Controllo la lista */
	while (sistema != NULL && !ris) {
		/* Ho trovato un computer con il codice identificativo cercato */
		if (sistema->computer.codice == cerca)
			ris = 1;

		sistema = sistema->next;			// Vai avanti
	}
	return ris;				// Valore di ritorno
}

/* Funzione che legge i dati da inserire all'intterno del nodo ricevuto */
void campoDati(N *controllo, N *leggi) {
	printf("\nRegistro il prossimo computer all'interno del database...\n");
	
	/* Modello del computer */
	printf("\nInserisci il modello del computer : ");
	fgets(leggi->computer.modello, 20, stdin);
	leggi->computer.modello[strlen(leggi->computer.modello) - 1] = '\0';

	/* Indicazione se il computer è un fisso o un portatile */
	do {
		printf("Il computer %c un fisso o un portatile ? ", 138);
		scanf("%c%*c", &leggi->computer.tipo);
		if (leggi->computer.tipo != 'f' && leggi->computer.tipo != 'p')
			printf("\nRegistrazione tipo fallita...\n");
	} while (leggi->computer.tipo != 'f' && leggi->computer.tipo != 'p');

	/* Indirizzo IP : è un array a 12 interi quindi uso for */
	printf("Inserisci l'indirizzo IP : ho bisogno di 12 numeri.\n\n");
	for (int i = 0; i < 12; i++) {
		printf("%d%c cifra = ", i+1, 167);
		scanf("%d", &leggi->computer.IP[i]);

		if (leggi->computer.IP[i] < 0 || leggi->computer.IP[i] > 9)
			while (leggi->computer.IP[i] < 0 || leggi->computer.IP[i] > 9) {
				printf("\nHo posto per un'unica cifra : ");
				scanf("%d", &leggi->computer.IP[i]);
			}
	}

	/* Assegnazione del codice identificativo in modo tale che sia il più piccolo intero positivo
	 * che non è già il codice identificativo di un altro computer dell'elenco */
	int identificativo = 1;				// Codice da assegnare
	int trovato = 0;					// Ho trovato il posto dove metterlo ? */

	/* Il ciclo continua finchè trovato vale false ovvero finchè non ho trovato un posto dove metterlo.
	 * Utilizzo la funzione esisteComputer per cercare posto : appena lo trovo trovato cambia valore di verità
	 * e esco dal while e assegno il codice al campo dati del nodo. */
	while (!trovato) {
		if (!esisteComputer(controllo, identificativo))
			trovato = 1;
		else
			/* Non ho trovato un posto : incremento l'identificativo */
			identificativo++;
	}
	leggi->computer.codice = identificativo;		// Memorizzo identificativo
}

/* Funzione che inserisce un nuovo computer in coda all'elenco */
void inserisciCoda(N **nuovo) {
	N *registra = malloc(sizeof(N));		// Alloco nodo nell'heap

	campoDati(*nuovo, registra);			// Leggo campo dati del nuovo nodo da registrare
	registra->next = NULL;

	/* Caso speciale (lista vuota) : diventa inserimento in testa */
	if (*nuovo == NULL)
		*nuovo = registra;					// Collego nodo alla testa
	else {
		N *appoggio = *nuovo;				// Nodo d'appoggio
		/* Controllo finchè il nodo successivo non punta a NULL */
		while (appoggio->next != NULL)
			appoggio = appoggio->next;		// Vai avanti
		appoggio->next = registra;			// Attacco nodo alla coda
	}
	printf("\nInserimento riuscito correttamente...\n");
}

/* Funzione che stampa le informazioni del singolo computer */
void stampaComputer(C *stampa) {
	printf("\nIl computer %c di modello %s, ", 138, stampa->modello);
	printf("ha codice identificativo %d ed indirizzo IP ", stampa->codice);
	for (int i = 0; i < 12; i++) {
		printf("%d", stampa->IP[i]);

		/* Stampo un punto ogni tripla di numeri */
		if (i == 2 || i == 5 || i == 8)
			printf(".");
	}
	if (stampa->tipo == 'f')
		printf("\nComputer fisso.\n");
	else if (stampa->tipo == 'p')
		printf("\nComputer portatile.\n");
}

/* Funzione che stampa a schermo l'elenco corrente di computer presenti in laboratorio */
void visualizzaLab(N *elenco) {
	/* Lista vuota ? */
	if (elenco == NULL)
		printf("\nLaboratorio vuoto...\n");
	else {
		/* Output */
		printf("\nLABORATORIO --> COMPUTER REGISTRATI\n\n");
		printf("***********************************\n");
		while (elenco != NULL) {
			stampaComputer(&elenco->computer);			// Stampo un computer
			elenco = elenco->next;					// Nodo successivo
		}
		printf("\n***********************************\n");
	}
}

int quantiFissi(N *head) {
	int quanti = 0;
	while (head != NULL) {
		if (head->computer.tipo == 'f')
			quanti++;
		head = head->next;
	}
	return quanti;
}

/* Funzione che riceve l'indirizzo della testa della lista. Cancella tutti i computer fissi dall'elenco */
void cancellaFissi(N **cancella) {

	/* Lista vuota */
	if (*cancella == NULL)
		printf("\nNulla da cancellare...\n");
	else {
		int quanti = quantiFissi(*cancella);

		if (quanti == 0)
			printf("\nNon devo cancellare nulla.\n");
		else {
			printf("\n%d computer fissi da cancellare.\n", quanti);		
			N *check;				// Nodo ausiliario di controllo e cancellazione
			N *prec;				// Nodo ausiliario per collegare

			/* Effettuo tutte le possibili cancellazioni in testa */
			while (*cancella != NULL && (*cancella)->computer.tipo == 'f' && quanti != 0) {
				check = *cancella;
				(*cancella) = (*cancella)->next;
				quanti--;
				free(check);
			}
			if (*cancella == NULL)
				printf("\nLista svuotata.\n");
			else {
				check = (*cancella)->next;
				prec = *cancella;

				while (check != NULL && quanti != 0) {
					if (check->computer.tipo == 'f') {
						prec->next = check->next;
						quanti--;
						free(check);
					}
					prec = check;
					check = check->next;
				}
				printf("\nCancellazione multipla riuscita.\n");
			}
		}

	}

}


void acquisizione(N **crea) {

}


void salvataggio(N *database) {

}

