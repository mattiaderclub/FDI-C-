/* Realizzare un programma che gestisce una lista di film.
 * 
 * Definire due strutture, una per rappresentare un elemento della lista e una per rappresentare un film appartenente all'elenco.
 * Ogni film dev'essere gestito come una struttura con cinque campi : nome del film, nome del regista, anno d'uscita,
 * durata del film e indicazione se il film è per tutti o vietato ai minori di 18 anni.
 *
 * Definire una funzione che visualizza l'elenco di film stampando per ognuno di loro le informazioni di ogni campo.
 *
 * Definire una funzione che inserisce un film in testa all'elenco.
 * Definire una funzione che inserisce un film in coda all'elenco.
 *
 * Definire una funzione che cancella il film in testa all'elenco.
 * Definire una funzione che cancella il film in coda all'elenco.
 *
 * Definire una funzione che ordina i film dell'elenco in ordine di durata.
 *
 * Definire una funzione main che crea la lista e gestisce l'interazione con l'utente. All'avvio del programma l'elenco di film
 * dev'essere inizializzato con i valori letti da un file; al termine i dati presenti nell'elenco devono essere salvati nello stesso file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Strutture */
/* Struct che gestisce le informazioni del singolo film */
typedef struct Dati {
	char nome[30];
	char regista[30];
	int durata;
	int anno;
	char limite;
} F;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	F film;
	struct Lista *next;
} N;

/* Dichiarazione delle funzioni secondarie */
void reminder();
void campoDati(N *leggi);
void inserisciInTesta(N **nuovo);
void inserisciInCoda(N **nuovo);
void stampaFilm(F *stampa);
void visualizzaElenco(N *head);
void cancellaTesta(N **elenco);
void cancellaCoda(N **elenco);
int nuovoMinimoDA(F *f1, F *f2);
void scambia(N *n1, N *n2);
void ordinaDurata(N **ordina);
void leggiDaBin(N **crea);
void salvaSuBin(N *elenco);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che gestisce una lista di film.\n");

	/* Input */
	N *movies;					// Lista di film
	leggiDaBin(&movies);		// Leggo nel file e "costruisco" la lista
	int scelta = -1;			// Scelta dell'utente

	/* Ciclo d'interazione con l'utente sfruttando la variabile scelta */
	while (scelta != 0) {
		reminder();
		/* Lettura codice comando da utilizzare all'interno del while */
		printf("\nInserisci il codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInTesta(&movies);
		else if (scelta == 2)
			inserisciInCoda(&movies);
		else if (scelta == 3)
			visualizzaElenco(movies);
		else if (scelta == 4)
			cancellaTesta(&movies);
		else if (scelta == 5)
			cancellaCoda(&movies);
		else if (scelta == 6)
			ordinaDurata(&movies);
	}
	/* Salvo contenuto della lista su un file */
	salvaSuBin(movies);
	/* Fine programma */
	printf("Chiusura programma...\n");
}
/* -----> Definizione funzioni di supporto <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con tutte le funzionalità del programma associate */
void reminder(){
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un film in testa all'elenco.");
	printf("\n2 - Inserisci un film in coda all'elenco.");
	printf("\n3 - Visualizza l'elenco corrente di pellicole registrate.");
	printf("\n4 - Cancella il primo film dell'elenco.");
	printf("\n5 - Cancella l'ultimo film dell'elenco.");
	printf("\n6 - Ordina la lista di pellicole in base alla durata del film.\n");
}

/* Funzione che legge le informazioni di un film */
void campoDati(N *leggi){
	printf("\nRegistro le informazioni della prossima pellicola...\n");
	/* Nome del film */
	printf("\nInserisci il nome del film : ");
	fgets(leggi->film.nome, 30, stdin);
	leggi->film.nome[strlen(leggi->film.nome) - 1] = '\0';

	/* Nome del regista */
	printf("Dammi il nome del regista del film : ");
	fgets(leggi->film.regista, 30, stdin);
	leggi->film.regista[strlen(leggi->film.regista) - 1] = '\0';

	/* Durata del film (in minuti) : viene inserito finchè non è maggiore di 0 */
	do {
		printf("Quanto tempo dura il fim ? ");
		scanf("%d%*c", &leggi->film.durata);
		if (leggi->film.durata <= 0)
			printf("\nRegistazione fallita...\n");
	} while (leggi->film.durata <= 0);

	/* Anno d'uscita del film */
	do {
		printf("Quando %c uscito il film nei cinema ? ", 138);
		scanf("%d%*c", &leggi->film.anno);
		if (leggi->film.anno < 0)
			printf("\nRegistazione fallita...\n");
	} while (leggi->film.anno < 0);

	/* Indicazione se il film è per tutti o se è vietato ai minori di 18 anni :
	 * anche qui un while che controlla se il valore è consono o meno */
	do {
		printf("Il film %c per tutti o %c vietato ai minori di 18 anni ? ", 138, 138);
		scanf("%c%*c", &leggi->film.limite);
		if (leggi->film.limite != 't' && leggi->film.limite != 'v')
			printf("\nRegistrazione fallita, riprovare...\n");
	} while (leggi->film.limite != 't' && leggi->film.limite != 'v');
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisce un film in testa all'elenco */
void inserisciInTesta(N **nuovo) {
	N *registra = malloc(sizeof(N));		// Alloco nodo per la registrazione nell'heap
	/* Leggo le informazioni da registrare */
	campoDati(registra);

	registra->next = *nuovo;				// Collego testa della lista al nodo successivo a quello in cui ho registrato i dati
	*nuovo = registra;						// Ricollego nuovamente i nodi : registra è adesso la nuova lista
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisce un film in coda */
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

/* Funzione che stampa a schermo le informazioni del singolo film */
void stampaFilm(F *stampa){
	/* Output */
	printf("\nNome del film : %s", stampa->nome);
	printf("\nRegista : %s", stampa->regista);
	printf("\nDurata : %d h, %d min", stampa->durata/60, stampa->durata%60);
	printf("\nAnno d'uscita : %d", stampa->anno);
	if (stampa->limite == 't')
		printf("\nFilm per tutti!\n");
	else if (stampa->limite == 'v')
		printf("\nFilm vietato ai minori di 18 anni!\n");
}

/* Funzione che stampa a schermo l'elenco corrente di film che sono stati registrati */
void visualizzaElenco(N *head){
	/* Lista vuota ? */
	if (head == NULL)
		printf("\nNessun film in lista...\n");
	else {
		printf("\nFilm in lista:\n");

		/* Stampo finchè ho qualcosa in lista */
		while (head != NULL) {
			stampaFilm(&head->film);		// Stampo il film
			head = head->next;				// Passo al nodo successivo
		}
	}
}

/* Funzione che riceve l'indirizzo della testa della lista e cancella l'elemento in testa all'elenco */
void cancellaTesta(N **elenco){
	/* Lista vuota ? */
	if (*elenco == NULL)
		printf("\nNulla da cancellare...\n");
	else {
		N *cancella = *elenco;			// Collego la testa della lista a un nodo di supporto
		*elenco = (*elenco)->next;		// Mi sposto
		free(cancella);					// Dealloco la memoria del nodo d'appoggio

		printf("\nFilm in testa all'elenco cancellato...\n");
	}
}

/* Funzione che riceve l'indirizzo della testa della lista e cancella l'elemento in coda all'elenco */
void cancellaCoda(N **elenco) {
	/* Lista vuota ? */
	if (*elenco == NULL)
		printf("\nNulla da cancellare...\n");
	else {
		N *check;				// Nodo di supporto (controllo nodi)
		N *cancella;			// Nodo di supporto (collegamento e scambio nodi)

		/* Caso speciale : ho un solo elemento in lista : diventa una cancellazione della testa */
		if ((*elenco)->next == NULL) {		
			check = *elenco;				// Collego la testa della lista a un nodo di supporto
			*elenco = (*elenco)->next;		// Mi sposto
			free(check);					// Dealloco la memoria del nodo d'appoggio

			printf("\nUn solo elemento in lista : cancellato correttamente...\n");
		}
		/* Ho più di un elemento solo in lista */
		else {
			/* Assegno i nodi */
			check = (*elenco)->next;
			cancella = *elenco;

			/* Vado avanti nella lista per il controllo di nodi finchè il prossimo non punta a NULL */
			while (check->next != NULL) {
				cancella = check;				// Vai avanti
				check = check->next;			// Vai avanti
			}
			cancella->next = check->next;		// Cancellazione
			free (check);						// Dealloco memoria
			printf("\nCancellazione in coda riuscita...\n");
		}
	}
}

/* Funzione che riceve gli indirizzi dei film di due nodi differenti e controlla se il secondo precede il primo :
 * questo avviene se il secondo film dura più del primo oppure, a parità di durata, se il secondo film è uscito
 * prima al cinema rispetto al primo */
int nuovoMinimoDA(F *f1, F *f2) {
	return ((f1->durata < f2->durata) || (f1->durata == f2->durata && f1->anno > f2->anno));
}

/* Funzione che scambia il contenuto di due nodi della lista ricevuti come parametri */
void scambia(N *n1, N *n2) {
	F temp;						// Variabile d'appoggio per non salvare temporaneamente il campo dati di un nodo
	temp = n1->film;
	n1->film = n2->film;
	n2->film = temp;
}

/* Funzione che riceve l'indirizzo della testa della lista e ordina l'elenco per durata dei film (decrescente) */
void ordinaDurata(N **ordina) {
	/* Controllo il contenuto della lista : sia se è vuota 
	 * sia se ho un solo elemento non devo ordinare nulla */
	if (*ordina == NULL || (*ordina)->next == NULL)
		printf("\nOrdinamento non riuscito per quantit%c di elementi insufficiente...\n", 133);
	else {
		N *minimo;				// Nodo di supportio (memorizza minimo)
		N *check;				// Nodo di supporto (controllo nodi)
		N *copia = *ordina;				// Nodo d'appoggio per copiare la lista

		/* Controllo tutti gli elementi in lista fino al penultimo */
		while (copia->next != NULL) {
			/* Assegno i nodi a ogni passo del while */
			minimo = copia;
			check = copia->next;

			/* Uso nodo check che controllare tutti i nodi successivi fino all'ultimo */
			while (check != NULL) {
				/* Ho trovato un elemento che va scambiato */
				if (nuovoMinimoDA(&minimo->film, &check->film))
					minimo = check;							// Nuovo minimo
				check = check->next;			// Prossimo nodo da controllare
			}
			/* Scambio di posto il minimo e il corrente nodo della lista copiata e passo avanti nella copia */
			scambia(copia, minimo);
			copia = copia->next;
		}
		/* Fine */
		printf("\nFilm in lista ordinati per durata correttamente...\n");
	}
}

/* Funzione che legge il contenuto di un file binario e lo memorizza all'interno di una lista */
void leggiDaBin(N **crea){
	*crea = NULL;				// Inizializzo la lista a NULL

	/* Apro file binario in lettura */
	FILE *leggi = fopen("Film.dat", "rb");

	/* Controllo apertura del file */
	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		F appoggio;				// Struct d'appoggio per la lettura

		/* File aperto correttamente : eseguo un primo controllo sul suo contenuto */
		if (fread(&appoggio, sizeof(F), 1, leggi) > 0) {
			N *memorizza = malloc(sizeof(N));				// Alloco memoria per il primo nodo della lista
			memorizza->film = appoggio;						// Memorizzo dati letti nel campo dati del nodo
			*crea = memorizza;								// Collego nodi

			/* Ciclo di controllo del file : leggo e memorizzo struct
			 * nei vari nodi della lista finchè non raggiungo la fine del file */
			while (fread(&appoggio, sizeof(F), 1, leggi) > 0) {
				memorizza->next = malloc(sizeof(N));				// Alloco memoria per prossimo nodo da registrare
				memorizza = memorizza->next;						// Passo avanti nella lista di supporto
				memorizza->film = appoggio;							// Registro il contenuto
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
	FILE *salva = fopen("Film.dat", "wb");

	/* Controllo apertura del file */
	if (salva == NULL) {
		printf("\nApertura file fallita...\n");
	}
	else {
		/* Salvo contenuto di ogni nodo della lista finchè non raggiungo quello che contiene NULL */
		while (elenco != NULL) {
			fwrite(&elenco->film, sizeof(F), 1, salva);			// Scrivo sul file
			elenco = elenco->next;								// Vai avanti
		}

		printf("\nSalvataggio effettuato...\n");
		/* Chiudo il file : scrittura terminata */
		fclose(salva);
	}
}
