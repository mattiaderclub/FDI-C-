/* Realizzare un programma che gestisce un elenco di libri.
 * 
 * Definire due strutture, una per rappresentare un elemento della lista e una per rappresentare un libro appartenente all'elenco.
 * Ogni libro dev'essere gestito come una struttura con quattro campi : nome del libro, nome dell'autore, numero di pagine
 * e indicazione se il libro è una prima edizione oppure una ristampa.
 *
 * Definire una funzione che visualizza l'elenco di libri stampando per ognuno di loro le informazioni di ogni campo del libro.
 *
 * Definire una funzione che inserisce un libro in coda all'elenco.
 *
 * Definire una funzione che cancella il libro in testa all'elenco.
 *
 * Definire una funzione main che crea la lista e gestisce l'interazione con l'utente. All'avvio del programma l'elenco di libri
 * dev'essere inizializzato con i valori letti da un file; al termine i dati presenti nell'elenco devono essere salvati nello stesso file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Strutture */
/* Struct che gestisce le informazioni del singolo libro */
typedef struct Dati {
	char nome[30];
	char autore[30];
	int pag;
	char tipo;
} L;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	L libro;
	struct Lista *next;
} N;

/* Dichiarazione delle funzioni secondarie */
void reminder();
void campoDati(N *leggi);
void inserisciInCoda(N **nuovo);
void stampaLibro(L *stampa);
void visualizzaElenco(N *head);
void cancellaTesta(N **elenco);
void leggiDaBin(N **crea);
void salvaSuBin(N *elenco);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che gestisce una lista di libri.\n");

	/* Input */
	N *books;					// Lista di libri
	leggiDaBin(&books);			// Leggo nel file e "costruisco" la lista
	int scelta = -1;			// Scelta dell'utente

	/* Ciclo d'interazione con l'utente sfruttando la variabile scelta */
	while (scelta != 0) {
		reminder();
		/* Lettura codice comando da utilizzare all'interno del while */
		printf("\nInserisci il codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInCoda(&books);
		else if (scelta == 2)
			visualizzaElenco(books);
		else if (scelta == 3)
			cancellaTesta(&books);
	}
	/* Salvo contenuto della lista su un file */
	salvaSuBin(books);
	/* Fine programma */
	printf("Chiusura programma...\n");
}
/* -----> Definizione funzioni di supporto <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con tutte le funzionalità del programma associate */
void reminder(){
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un libro in coda all'elenco.");
	printf("\n2 - Visualizza l'elenco corrente di libri registrati.");
	printf("\n3 - Cancella il primo libro dell'elenco.\n");
}

/* Funzione che legge le informazioni di un libro */
void campoDati(N *leggi){
	printf("\nRegistro le informazioni del prossimo libro...\n");
	/* Nome del libro */
	printf("\nInserisci il nome del libro : ");
	fgets(leggi->libro.nome, 30, stdin);
	leggi->libro.nome[strlen(leggi->libro.nome) - 1] = '\0';

	/* Nome dell'autore del libro */
	printf("Dammi il nome dell'autore del libro : ");
	fgets(leggi->libro.autore, 30, stdin);
	leggi->libro.autore[strlen(leggi->libro.autore) - 1] = '\0';

	/* Numero di pagine del libro : viene inserito finchè non è maggiore di 0 */
	do {
		printf("Da quante pagine %c composto il libro ? ", 138);
		scanf("%d%*c", &leggi->libro.pag);
		if (leggi->libro.pag <= 0)
			printf("\nRegistazione fallita...\n");
	} while (leggi->libro.pag <= 0);

	/* Indicazione se il libro è una prima edizione o una ristampa :
	 * anche qui while che controlla se il valore è consono o meno */
	do {
		printf("Il libro %c una prima edizione o una ristampa ? ", 138);
		scanf("%c%*c", &leggi->libro.tipo);
		if (leggi->libro.tipo != 'p' && leggi->libro.tipo != 'r')
			printf("\nRegistrazione fallita, riprovare...\n");
	} while (leggi->libro.tipo != 'p' && leggi->libro.tipo != 'r');
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisce un libro in coda */
void inserisciInCoda(N **nuovo){
	N *registra = malloc(sizeof(N));		// Alloco nodo per la registrazione nell'heap
	/* Leggo le informazioni da registrare */
	campoDati(registra);
	registra->next = NULL;

	/* Caso speciale : lista vuota -> diventa un inserimento in testa */
	if (*nuovo == NULL) {
		*nuovo = registra;					// Collego nodo registrato alla testa ricevuta dalla funzione
	}

	/* Inserimento in coda normale */
	else {
		N *appoggio = *nuovo;				// Mi appoggio a un nodo di supporto per non midificare la lista
		/* Arrivo alla fine della lista d'appoggio */
		while (appoggio->next != NULL)
			appoggio = appoggio->next;		// Vai avanti
		appoggio->next = registra;			// Collego nuovo nodo alla fine della lista
	}
}

/* Funzione che stampa a schermo le informazioni del singolo libro */
void stampaLibro(L *stampa){
	/* Output */
	printf("\nNome : %s", stampa->nome);
	printf("\nAutore : %s", stampa->autore);
	printf("\nNumero di pagine : %d", stampa->pag);
	if (stampa->tipo == 'p')
		printf("\nPrima edizione!\n");
	else if (stampa->tipo == 'r')
		printf("\nEdizione ristampata!\n");
}

/* Funzione che stampa a schermo l'elenco corrente di libri che sono stati registrati */
void visualizzaElenco(N *head){
	/* Lista vuota ? */
	if (head == NULL)
		printf("\nNessun libro %c stato registrato...\n", 138);
	else {
		printf("\nLibri registrati:\n");

		/* Stampo finchè ho qualcosa in lista */
		while (head != NULL) {
			stampaLibro(&head->libro);		// Stampo il libro
			head = head->next;				// Passo al nodo successivo
		}
	}
}

/* Funzione che riceve l'indirizzo della testa della lista e cancella il libro in testa all'elenco */
void cancellaTesta(N **elenco){
	/* Lista vuota ? */
	if (*elenco == NULL)
		printf("\nNulla da cancellare...\n");
	else {
		N *cancella = *elenco;			// Collego la testa della lista a un nodo di supporto
		*elenco = (*elenco)->next;		// Mi sposto
		free(cancella);					// Dealloco la memoria del nodo d'appoggio

		printf("\nLibro in testa all'elenco cancellato...\n");
	}
}

/* Funzione che legge il contenuto di un file binario e lo memorizza all'interno di una lista */
void leggiDaBin(N **crea){
	*crea = NULL;				// Inizializzo la lista a NULL

	/* Apro file binario in lettura */
	FILE *leggi = fopen("Libri.dat", "rb");

	/* Controllo apertura del file */
	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		L appoggio;				// Struct d'appoggio per la lettura

		/* File aperto correttamente : eseguo un primo controllo sul suo contenuto */
		if (fread(&appoggio, sizeof(L), 1, leggi) > 0) {
			N *memorizza = malloc(sizeof(N));				// Alloco memoria per il primo nodo della lista
			memorizza->libro = appoggio;					// Memorizzo dati letti nel campo dati del nodo
			*crea = memorizza;								// Collego nodi

			/* Ciclo di controllo del file : leggo e memorizzo struct
			 * nei vari nodi della lista finchè non raggiungo la fine del file */
			while (fread(&appoggio, sizeof(L), 1, leggi) > 0) {
				memorizza->next = malloc(sizeof(N));				// Alloco memoria per prossimo nodo da registrare
				memorizza = memorizza->next;						// Passo avanti nella lista di supporto
				memorizza->libro = appoggio;						// Registro il contenuto
			}
			printf("\nLettura riuscita...\n");
		}
		/* File vuoto */
		else {
			printf("\nFile vuoto...\n");
		}
		/* Chiudo il file : lettura terminata */
		fclose (leggi);
	}
}

/* Funzione che salva il contenuto di una lista su un file binario */
void salvaSuBin(N *elenco){
	/* Apro file binario in scrittura */
	FILE *salva = fopen("Libri.dat", "wb");

	/* Controllo apertura del file */
	if (salva == NULL) {
		printf("\nApertura file fallita...\n");
	}
	else {
		/* Salvo contenuto di ogni nodo della lista finchè non raggiungo quello che contiene NULL */
		while (elenco != NULL) {
			fwrite(&elenco->libro, sizeof(L), 1, salva);		// Scrivo sul file
			elenco = elenco->next;								// Vai avanti
		}

		printf("\nSalvataggio effettuato...\n");
		/* Chiudo il file : scrittura terminata */
		fclose(salva);
	}
}