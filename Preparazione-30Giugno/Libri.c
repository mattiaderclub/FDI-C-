/* Programma che gestisce una biblioteca.
 
 * Definire due strutture, una per controllare ogni libro della lista e una per ogni nodo della lista. Ogni struct libro deve
 * avere quattro campi : uno indica il numero di pagine, uno il nome del libro, uno quello dell'autore e l'ultimo indica se si
 * tratta di una prima edizione o di una ristampa.

 * Funzioni secondarie da dichiarare e definire :

 * Funzione per inserire in testa all'elenco un nuovo libro 
 * Funzione per inserire in coda all'elenco un nuovo libro
 * Funzione per inserire nell'elenco un nuovo libro mantenendo l'ordine alfabetico dei nomi dei libri
 * Funzione che stampa la lista corrente di libri
 * Funzione che ordina l'elenco a seconda del numero di pagine dei libri (ordine decrescente) 
 * Funzione che cancella la testa della lista
 * Funzione che cancella la coda della lista
 * Funzione che cancella dalla lista tutti i libri che hanno più di 300 pagine
 * Funzione che legge una stringa da tastiera e cancella dalla lista il libro con quel nome
 * Funzione che legge una stringa da tastiera e cerca (e stampa) i libri di quell'autore
 * Funzione che legge a inizio file il contenuto di un file e lo inserisce in una lista
 * Funzione che salva il contenuto della lista su un file 

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che gestisce i dati di un libro */
typedef struct Libro {
	char nome[30];
	char autore[30];
	int pagine;
	char tipo;
} L;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	L libro;
	struct Lista *next;
} N;

/* Funzioni secondarie */
void reminder();
void campoDati(N *leggi);
void inserisciTesta(N **nuovo);
void inserisciCoda(N **nuovo);
void inserimentoOrdinato(N **nodo);
void stampaLibro(L *stampa);
void visualizzaElenco(N *elenco);
int precede(L *l1, L *l2);
void scambia(N *n1, N *n2);
void ordinaPagine(N **elenco);
void cancellaTesta(N **libri);
void cancellaCoda(N **libri);
void cancella300Pagine(N **libri);
void cancellaLibroConNome(N **libri);
void cercaAutore(N *lista);
void acquisizione(N **elenco);
void salvataggio(N *lista);

/* Corpo del programma */
int main() {
	/* Input */
	int scelta = -1;				// Scelta utente
	N *biblioteca;					// Lista di libri
	acquisizione(&biblioteca);		// Inizializzo lista da un file

	printf("\nSono un programma che gestisce un elenco di libri.\n");

	/* Ciclo d'interazione con l'utente */
	while (scelta != 0) {
		reminder();
		/* Lettura codice comando */
		printf("\nInserisci codice comando : ");
		scanf("%d%*c", &scelta);

		/* Funzioni a disposizione dell'utente */
		if (scelta == 1)
			inserisciTesta(&biblioteca);
		else if (scelta == 2)
			inserisciCoda(&biblioteca);
		else if (scelta == 3)
			inserimentoOrdinato(&biblioteca);
		else if (scelta == 4)
			visualizzaElenco(biblioteca);
		else if (scelta == 5)
			ordinaPagine(&biblioteca);
		else if (scelta == 6)
			cancellaTesta(&biblioteca);
		else if (scelta == 7)
			cancellaCoda(&biblioteca);
		else if (scelta == 8)
			cancella300Pagine(&biblioteca);
		else if (scelta == 9)
			cancellaLibroConNome(&biblioteca);
		else if (scelta == 10)
			cercaAutore(biblioteca);
	}
	/* Salvo dati su un file */
	salvataggio(biblioteca);
	/* Chiura programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con tutte le funzionalità del programma associate */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n00 - Termina il programma.");
	printf("\n01 - Inserisci un libro in testa all'elenco.");
	printf("\n02 - Inserisci un libro in coda all'elenco.");
	printf("\n03 - Inserisci un libro in lista mantenendo l'ordine alfabetico tra i nomi dei libri.");
	printf("\n04 - Visualizzazione.");
	printf("\n05 - Ordinamento per numero di pagine.");
	printf("\n06 - Cancellazione in testa.");
	printf("\n07 - Cancellazione in coda.");
	printf("\n08 - Cancellazione multipla di tutti i libri che hanno un numero di pagine superiore a 300.");
	printf("\n09 - Lettura del titolo di un libro e cancellazione del libro con que titolo.");
	printf("\n10 - Lettura di un nome di un autore e visualizzazione di tutti i suoi libri.\n");
}
void campoDati(N *leggi) {
	printf("\nRegistro le informazioni del prossimo libro...\n\n");

	/* Nome del libro */
	printf("Inserisci il nome del libro : ");
	fgets(leggi->libro.nome, 30, stdin);
	leggi->libro.nome[strlen(leggi->libro.nome) - 1] = '\0';

	/* Nome autore */
	printf("Inserisci il nome dell'autore del libro : ");
	fgets(leggi->libro.autore, 30, stdin);
	leggi->libro.autore[strlen(leggi->libro.autore) - 1] = '\0';

	/* Numero di pagine del libro */
	do {
		printf("Inserisci il numero di pagine del libro : ");
		scanf("%d%*c", &leggi->libro.pagine);
		/* Intero positivo */
		if (leggi->libro.pagine <= 0)
			printf("\nRegistrazione fallita...\n");
	} while (leggi->libro.pagine <= 0);

	/* Indicazione se è una prima edizione o una ristampa */
	do {
		printf("Il libro %c una prima edizione o una ristampa ? ", 138);
		scanf("%c%*c", &leggi->libro.tipo);
		/* Non ho inserito un carattere adeguato */
		if (leggi->libro.tipo != 'p' && leggi->libro.tipo != 'r')
			printf("\nRegistrazione fallita...\n");
	} while (leggi->libro.tipo != 'p' && leggi->libro.tipo != 'r');
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisci un libro in testa alla lista */
void inserisciTesta(N **nuovo) {	
	N* registra = malloc(sizeof(N));		// Alloco nodo nell'heap

	campoDati(registra);					// Lettura campo dati
	registra->next = *nuovo;				// Collego testa al nuovo nodo
	*nuovo = registra;						// Trasformo la testa
	printf("\nInserimento in testa effettuato...\n");
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisci un libro in coda alla lista */
void inserisciCoda(N **nuovo) {
	N* registra = malloc(sizeof(N));		// Alloco memoria per nodo

	campoDati(registra);
	registra->next = NULL;					// Setto successivo

	/* Caso speciale : lista vuota -> diventa inserimento in testa */
	if (*nuovo == NULL)
		*nuovo = registra;			// Collego nodi
	else {
		/* Inserimento in coda : Ricopio la lista, la scorro fino alla fine */
		N *appoggio = *nuovo;

		while (appoggio->next != NULL) {
			appoggio = appoggio->next;
		}
		appoggio->next = registra;			// Collego nodi
	}
	printf("\nInserimento in coda effettuato...\n");
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisce in lista un elemento mantenendo l'ordinamento
 * alfabetico dei nomi dei libri */
void inserimentoOrdinato(N **nodo) {
	N *nuovo = malloc(sizeof(N));			// Alloco nodo nell'heap

	campoDati(nuovo);						// Registro i dati

	/* Casi speciali : testa vuota oppure testa non vuota ma devo inserirlo in testa per un discorso di ordine */
	if (*nodo == NULL || strcmp(nuovo->libro.nome, (*nodo)->libro.nome) < 0) {

		/* Inserimento in testa */
		nuovo->next = *nodo;
		*nodo = nuovo;
		printf("Inserimento in testa riuscito...\n");
	}
	else {

		/* Setto nodi di supporto */
		N *check = (*nodo)->next;
		N *prec = *nodo;

		/* Continuo a procedere nella lista o finchè ho elementi all'interno o finchè non trovo posto dove inserire il nuovo nodo */
		while (check != NULL && strcmp(nuovo->libro.nome, (*nodo)->libro.nome) >= 0) {
			prec = check;				// Vai avanti
			check = check->next;		// Vai avanti
		}
		/* Collego nodi */
		prec->next = nuovo;
		nuovo->next = check;
		printf("\nInserimento ordinato effettuato...\n");
	}
}

/* Funzione che stampa le informazioni di un singolo libro */
void stampaLibro(L *stampa) {
	/* Output */
	printf("\n%s", stampa->nome);
	printf("\n%s", stampa->autore);
	printf("\n%d pagine", stampa->pagine);

	if (stampa->tipo == 'p')
		printf("\nPrima edizione.\n");
	else if (stampa->tipo == 'r')
		printf("\nRistampa.\n");
}

/* Funzione che stampa a schermo la lista di libri registrati in lista */
void visualizzaElenco(N *elenco) {
	/* Lista vuota ? */
	if (elenco == NULL)
		printf("\nLista vuota.\n");
	else {
		printf("\nLIBRI\n");
		printf("\n************************\n");

		/* Stampo finchè ho nodi che non puntano a NULL in lista */
		while (elenco != NULL) {
			stampaLibro(&elenco->libro);		// Stampa il libro
			elenco = elenco->next;				// Vai avanti
		}

		printf("\n************************\n");
	}
}

/* Funzione che serve per la funzione di ordinamento. Controlla se il primo libro ricevuto come parametro precede il secondo.
 * Si controlla prima il numero di pagine, poi il tipo, infine il nome del libro nel caso in cui tipo e numero di pagine corrispondano */
int precede(L *l1, L *l2) {
	return ((l1->pagine > l2->pagine) || ((l1->pagine == l2->pagine) && (l1->tipo == 'p' && l2->tipo != 'p'))
			|| ((l1->pagine == l2->pagine) && (l1->tipo == l2->tipo) && (strcmp(l1->nome, l2->nome) < 0)));
}

/* Funzione che riceve due nodi e scambia i contenuti dei nodi */
void scambia(N *n1, N *n2) {
	L temp = n1->libro;			// Variabile temporanea per non perdere dati
	n1->libro = n2->libro;
	n2->libro = temp;
}

/* Funzione che riceve l'indirizzo della testa della lista e ordina la lista in base al numero di pagine decrescente */
/* Algoritmo di ordinamento -> selection sort */
void ordinaPagine(N **elenco) {
	/* Lista vuota o solo un elemento in lista */
	if (*elenco == NULL || (*elenco)->next == NULL)
		printf("\nNulla da ordinare.\n");

	/* Devo ordinare */
	else {
		N *check;			// Nodo che controlla i valori
		N *minimo;			// Nodo per memorizzare minimo
		N *appoggio = *elenco;			// Nodo d'appoggio per ricopiare lista

		/* Sfoglio lista fino al penultimo elemento */
		while (appoggio->next != NULL) {
			minimo = appoggio;				// Setto minimo
			check = appoggio->next;			// Setto nodo dal quale cominciare controlli nel secondo ciclo

			/* Controllo adesso tutti i restanti valori della lista per cercare quelli che vanno scambiati */
			while (check != NULL) {
				/* Ho trovato un elemento che precede il minimo nella lista "finale" : memorizzo il nuovo minimo */
				if (precede(&check->libro, &minimo->libro))
					minimo = check;

				check = check->next;		// Non ho trovato nulla : avanzo con il nodo di controllo
			}
			/* Scambio il campo dati dei nodi avendo trovato il minimo definitivo */
			scambia(appoggio, minimo);
			appoggio = appoggio->next;		// Vai avanti
		}
		printf("\nOrdinamento effettuato...\n");
	}
}

/* Funzione che riceve l'indirizzo della lista e cancella la testa della lista */
void cancellaTesta(N **libri) {
	if (*libri != NULL) {
		N *cancella = *libri;			// Nodo d'appoggio
		*libri = (*libri)->next;		// Cancello
		free(cancella);					// Dealloco nodo di supporto
		printf("\nCancellazione in testa riuscita...\n");
	}
}

/* Funzione che riceve l'indirizzo della lista e cancella la coda della lista */
void cancellaCoda(N **libri) {
	/* Ho qualcosa da cancellare */
	if (*libri != NULL) {
		/* Ho solo un elemento in lista -> diventa cancellazione in testa */
		if ((*libri)->next == NULL) {

			N *cancella = *libri;
			*libri = (*libri)->next;
			free(cancella);
			printf("\nCancellazione in testa riuscita...\n");
		}
		/* Nessun caso speciale : cerco la coda */
		else {
			if ((*libri)->next->next == NULL) {

				N *cancella = *libri;
				*libri = (*libri)->next;
				free(cancella);
				printf("\nCancellazione in testa riuscita...\n");
			}
			else {				
				/* Dichiaro e inizializzo nodi di supporto */
				N *check = (*libri)->next;
				N *prec = *libri;

				/* Vado avanti fino alla coda */
				while (check->next->next != NULL) {
					prec = check;
					check = check->next;
				}
				N *appoggio = check;
				prec->next = check->next;		// Cancello
				check->next = appoggio;
				free(check);					// Dealloco
				printf("\nCancellazione del penultimo elemento riuscita...\n");
			}
		}
	}
}

/* Funzione che riceve l'indirizzo della lista e cancella dalla lista tutti i libri che hanno un numero
 * di pagine superiore a 300 -> Cancellazione multipla */
void cancella300Pagine(N **libri) {
	/* Lista vuota ? */
	if (*libri == NULL) {
		printf("\nNulla da cancellare...\n");
	}

	else {

		/* Cancellazioni multiple nella testa finchè testa non vuota e elemento in testa è da cancellare */
		while (*libri != NULL && (*libri)->libro.pagine >= 300) {
			/* Cancellazione in testa */
			N *cancella = *libri;
			*libri = (*libri)->next;
			free(cancella);
		}

		/* Controllo contenuto testa per sapere se devo ancora cercare elementi da cancellare in lista */
		if (*libri == NULL)
			printf("\nHo svuotato la lista...\n");
		else {
			/* Dichiaro e setto nodi di supporto */
			N *check = (*libri)->next;
			N *prec = (*libri);

			/* Sfoglio la lista */
			while (check != NULL) {
				/* Ho trovato un elemento da cancellare */
				if (check->libro.pagine >= 300) {
					prec->next = check->next;		// Cancello
					free(check);					// Dealloco nodo di controllo valori
					check = prec->next;				// Setto il nuovo nodo
				}
				else {
					/* Non ho trovato nulla : vado avanti normale */ 
					prec = check;
					check = check->next;
				}
			}
		}
		printf("\nCancellazione multipla riuscita...\n");
	}
}

/* Funzione che riceve l'indirizzo della testa della lista, legge un nome da tastiera e cancella un libro con quel nome */
void cancellaLibroConNome(N **libri) {

	if (*libri != NULL) {

		char cercaBook[30];
		printf("\nInserisci il titolo del libro che cerchi : ");
		fgets(cercaBook, 30, stdin);
		cercaBook[strlen(cercaBook) - 1] = '\0';

		if (strcmp((*libri)->libro.nome, cercaBook) == 0) {

			N *cancella = *libri;
			*libri = (*libri)->next;
			free(cancella);
			printf("\nIl libro \"%s\" %c stato cancellato dalla lista", cercaBook, 138);
		}
		else {
			N *check = (*libri)->next;
			N *prec = *libri;
			int trovato = 0;

			while (check != NULL && !trovato) {
				if (strcmp(check->libro.nome, cercaBook) == 0) {

					prec->next = check->next;
					free(check);
					trovato = 1;
					printf("\nIl libro \"%s\" %c stato cancellato dalla lista", cercaBook, 138);
				}
				else {
					prec = check;
					check = check->next;
				}
			}
			if (!trovato)
				printf("\nNon ho trovato nessun libro con questo nome...\n");
		}
	}
	else
		printf("\nLista vuota...\n");
}

/* Funzione che legge il nome di un autore da tastiera e stampa i libri di quell'autore */
void cercaAutore(N *lista) {
	if (lista == NULL)
		printf("\nLista vuota...\n");
	else {

		char cercaScrittore[30];
		printf("\nInserisci il nome dell'autore del quale vuoi stamparne i libri : ");
		fgets(cercaScrittore, 30, stdin);
		cercaScrittore[strlen(cercaScrittore) - 1] = '\0';

		printf("\nCollezione di %s:\n", cercaScrittore);
		printf("\n===========================\n");
		while (lista != NULL) {
			if (strcmp(lista->libro.autore, cercaScrittore) == 0)
				stampaLibro(&lista->libro);

			lista = lista->next;
		}
		printf("\n===========================\n");
	}
}

/* Funzione che salva il contenuto di una lista all'interno di un file binario*/
void salvataggio(N *lista) {
	/* Apro file binario in scrittura */
	FILE *salva = fopen("Biblioteca.dat", "wb");

	/* Controllo apertura file */
	if (salva == NULL)
		printf(
			"\nApertura file fallita...\n");
	else {
		/* Sfoglio la lista fino all'ultimo nodo e a ogni passo scrivo sul file binario
		 * un libro della lista e vado avanti al nodo successivo */
		while (lista != NULL) {
			fwrite(&lista->libro, sizeof(L), 1, salva);
			lista = lista->next;
		}

		printf("\nSalvataggio riuscito...");
		fclose(salva);							// Chiusura file
	}
}

/* Funzione che riceve l'indirizzo della testa della lista e 
 * inserisce nella lista il contenuto letto da un file binario */
void acquisizione(N **elenco) {
	*elenco = NULL;						// Inizializzo lista
	/* Apro file binario in lettura */
	FILE *leggi = fopen("Biblioteca.dat", "rb");

	/* Controllo esistenza del file */
	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		L lettura;			// Variabile d'appoggio per la lettura
		/* File contiene almeno un elemento da leggere */
		if (fread(&lettura, sizeof(L), 1, leggi) > 0) {

			N *memorizza = malloc(sizeof(N));		// Alloco nodo nell'heap
			memorizza->libro = lettura;				// Memorizzo campo dati letto
			*elenco = memorizza;					// Collego lista dei nodi da memorizzare alla testa

			/* Finchè ho altri elementi da leggere continuo la lettura e la memorizzazione */
			while (fread(&lettura, sizeof(L), 1, leggi) > 0) {

				memorizza->next = malloc(sizeof(N));		// Alloco nodo successivo
				memorizza = memorizza->next;				// Vai avanti
				memorizza->libro = lettura;					// Memorizzo
			}
			printf("\nDati recuperati...\n");
		}
		else								// Nel file non c'è nulla da leggere
			printf("\nFile vuoto...\n");
		fclose(leggi);						// Chiudo il file
	}
}

