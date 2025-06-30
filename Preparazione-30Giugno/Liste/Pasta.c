/* Realizzare un programma che gestisce un elenco di pacchi di pasta.
 * 
 * Definire due strutture, una per rappresentare un elemento della lista e una per rappresentare un pacco di pasta appartenente all'elenco.
 * Ogni pacco di pasta dev'essere gestito come una struttura con cinque campi : tipo di pasta, nome dell'azienda produttrica, tempo di cottura,
 * peso del pacco e indicazione se la pasta è integrale o raffinata.
 *
 * Definire una funzione che visualizza l'elenco di pacchi di pasta stampando per ognuno di loro le informazioni di ogni campo.
 *
 * Definire una funzione che inserisce un pacco di pasta in testa all'elenco.
 * Definire una funzione che inserisce un pacco di pasta in coda all'elenco.
 *
 * Definire una funzione che cancella il pacco di pasta in testa all'elenco.
 * Definire una funzione che cancella il pacco di pasta in coda all'elenco.
 *
 * Definire una funzione che ordina i pacchi di pasta dell'elenco in ordine di tempo di cottura.
 *
 * Definire una funzione main che crea la lista e gestisce l'interazione con l'utente. All'avvio del programma l'elenco di pacchi di pasta
 * dev'essere inizializzato con i valori letti da un file; al termine i dati presenti nell'elenco devono essere salvati nello stesso file. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Strutture */
/* Struct che gestisce le informazioni del singolo pacco di pasta */
typedef struct Dati {
	char tipo[30];
	char azienda[30];
	int cottura;
	int peso;
	char impasto;
} P;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	P pasta;
	struct Lista *next;
} N;

/* Dichiarazione delle funzioni secondarie */
void reminder();
void campoDati(N *leggi);
void inserisciInTesta(N **nuovo);
void inserisciInCoda(N **nuovo);
void stampaPacco(P *stampa);
void visualizzaElenco(N *head);
void cancellaTesta(N **elenco);
void cancellaCoda(N **elenco);
int nuovoMinimoTC(P *p1, P *p2);
void scambia(N *n1, N *n2);
void ordinaCottura(N **ordina);
void leggiDaBin(N **crea);
void salvaSuBin(N *elenco);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che gestisce una lista di pacchi di pasta.\n");

	/* Input */
	N *pacchi;					// Lista di pacchi di pasta
	leggiDaBin(&pacchi);		// Leggo nel file e "costruisco" la lista
	int scelta = -1;			// Scelta dell'utente

	/* Ciclo d'interazione con l'utente sfruttando la variabile scelta */
	while (scelta != 0) {
		reminder();
		/* Lettura codice comando da utilizzare all'interno del while */
		printf("\nInserisci il codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInTesta(&pacchi);
		else if (scelta == 2)
			inserisciInCoda(&pacchi);
		else if (scelta == 3)
			visualizzaElenco(pacchi);
		else if (scelta == 4)
			cancellaTesta(&pacchi);
		else if (scelta == 5)
			cancellaCoda(&pacchi);
		else if (scelta == 6)
			ordinaCottura(&pacchi);
	}
	/* Salvo contenuto della lista su un file */
	salvaSuBin(pacchi);
	/* Fine programma */
	printf("Chiusura programma...\n");
}
/* -----> Definizione funzioni di supporto <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con tutte le funzionalità del programma associate */
void reminder(){
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un pacco di pasta in testa all'elenco.");
	printf("\n2 - Inserisci un pacco di pasta in coda all'elenco.");
	printf("\n3 - Visualizza l'elenco corrente di pacchi di pasta registrati.");
	printf("\n4 - Cancella il primo pacco di pasta dell'elenco.");
	printf("\n5 - Cancella l'ultimo pacco di pasta dell'elenco.");
	printf("\n6 - Ordina la lista di pacchi di pasta in base al tempo di cottura.\n");
}

/* Funzione che legge le informazioni di un pacco di pasta */
void campoDati(N *leggi){
	printf("\nRegistro le informazioni del prossimo pacco di pasta...\n");
	/* Nome del tipo di pasta */
	printf("\nInserisci il nome del tipo di pasta : ");
	fgets(leggi->pasta.tipo, 30, stdin);
	leggi->pasta.tipo[strlen(leggi->pasta.tipo) - 1] = '\0';

	/* Nome dell'azienda produttrice */
	printf("Dammi il nome dell'azienda produttrice : ");
	fgets(leggi->pasta.azienda, 30, stdin);
	leggi->pasta.azienda[strlen(leggi->pasta.azienda) - 1] = '\0';

	/* Tempo di cottura della pasta : viene inserito finchè non è maggiore di 0 */
	do {
		printf("Quanto tempo impiega per cuocere ? ");
		scanf("%d%*c", &leggi->pasta.cottura);
		if (leggi->pasta.cottura <= 0)
			printf("\nRegistazione fallita...\n");
	} while (leggi->pasta.cottura <= 0);

	/* Peso del pacco di pasta : viene inserito finchè non è maggiore di 0 */
	do {
		printf("Quanto pesa il pacco ? ");
		scanf("%d%*c", &leggi->pasta.peso);
		if (leggi->pasta.peso <= 0)
			printf("\nRegistazione fallita...\n");
	} while (leggi->pasta.peso <= 0);

	/* Indicazione se la pasta è integrale, raffinata o all'uovo :
	 * anche qui un while che controlla se il valore è consono o meno */
	do {
		printf("La pasta %c integrale, raffinata o all'uovo ? ", 138);
		scanf("%c%*c", &leggi->pasta.impasto);
		if (leggi->pasta.impasto != 'i' && leggi->pasta.impasto != 'r' && leggi->pasta.impasto != 'u')
			printf("\nRegistrazione fallita, riprovare...\n");
	} while (leggi->pasta.impasto != 'i' && leggi->pasta.impasto != 'r' && leggi->pasta.impasto != 'u');
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisce un pacco di pasta in testa all'elenco */
void inserisciInTesta(N **nuovo) {
	N *registra = malloc(sizeof(N));		// Alloco nodo per la registrazione nell'heap
	/* Leggo le informazioni da registrare */
	campoDati(registra);

	registra->next = *nuovo;				// Collego testa della lista al nodo successivo a quello in cui ho registrato i dati
	*nuovo = registra;						// Ricollego nuovamente i nodi : registra è adesso la nuova lista
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisce un pacco di pasta in coda */
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

/* Funzione che stampa a schermo le informazioni del singolo pacco di pasta */
void stampaPacco(P *stampa){
	/* Output */
	printf("\nTipo di pasta : %s", stampa->tipo);
	printf("\nAzienda produttrice : %s", stampa->azienda);
	printf("\nTempo di cottura : %d min, %d min (al dente)", stampa->cottura, stampa->cottura - 2);
	printf("\nPeso : %d g", stampa->peso);
	if (stampa->impasto == 'i')
		printf("\nPasta integrale!\n");
	else if (stampa->impasto == 'r')
		printf("\nPasta raffinata!\n");
	else if (stampa->impasto == 'u')
		printf("\nPasta all'uovo!\n");
}

/* Funzione che stampa a schermo l'elenco corrente di pacchi di pasta che sono stati registrati */
void visualizzaElenco(N *head){
	/* Lista vuota ? */
	if (head == NULL)
		printf("\nNessun pacco di pasta %c stato registrato...\n", 138);
	else {
		printf("\nPacchi di pasta in dispensa:\n");

		/* Stampo finchè ho qualcosa in lista */
		while (head != NULL) {
			stampaPacco(&head->pasta);		// Stampo il pacco di pasta
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

		printf("\nPacco di pasta in testa all'elenco cancellato...\n");
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

/* Funzione che riceve gli indirizzi dei pacchi di pasta di due nodi differenti e controlla se il secondo precede il primo :
 * questo avviene se la pasta del secondo pacco ci mette di più a cuocersi oppure, a parità di cottura, se il secondo pacco
 * pesa meno del primo */
int nuovoMinimoTC(P *p1, P *p2) {
	return ((p1->cottura < p2->cottura) || (p1->cottura == p2->cottura && p1->peso > p2->peso));
}

/* Funzione che scambia il contenuto di due nodi della lista ricevuti come parametri */
void scambia(N *n1, N *n2) {
	P temp;						// Variabile d'appoggio per non salvare temporaneamente il campo dati di un nodo
	temp = n1->pasta;
	n1->pasta = n2->pasta;
	n2->pasta = temp;
}

/* Funzione che riceve l'indirizzo della testa della lista e ordina l'elenco per tempo di cottura della pasta (decrescente) */
void ordinaCottura(N **ordina) {
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
				if (nuovoMinimoTC(&minimo->pasta, &check->pasta))
					minimo = check;							// Nuovo minimo
				check = check->next;			// Prossimo nodo da controllare
			}
			/* Scambio di posto il minimo e il corrente nodo della lista copiata e passo avanti nella copia */
			scambia(copia, minimo);
			copia = copia->next;
		}
		/* Fine */
		printf("\nDispensa ordinata per tempo di cottura dei pacchi di pasta...\n");
	}
}

/* Funzione che legge il contenuto di un file binario e lo memorizza all'interno di una lista */
void leggiDaBin(N **crea){
	*crea = NULL;				// Inizializzo la lista a NULL

	/* Apro file binario in lettura */
	FILE *leggi = fopen("Pasta.dat", "rb");

	/* Controllo apertura del file */
	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {
		P appoggio;				// Struct d'appoggio per la lettura

		/* File aperto correttamente : eseguo un primo controllo sul suo contenuto */
		if (fread(&appoggio, sizeof(P), 1, leggi) > 0) {
			N *memorizza = malloc(sizeof(N));				// Alloco memoria per il primo nodo della lista
			memorizza->pasta = appoggio;					// Memorizzo dati letti nel campo dati del nodo
			*crea = memorizza;								// Collego nodi

			/* Ciclo di controllo del file : leggo e memorizzo struct
			 * nei vari nodi della lista finchè non raggiungo la fine del file */
			while (fread(&appoggio, sizeof(P), 1, leggi) > 0) {
				memorizza->next = malloc(sizeof(N));				// Alloco memoria per prossimo nodo da registrare
				memorizza = memorizza->next;						// Passo avanti nella lista di supporto
				memorizza->pasta = appoggio;						// Registro il contenuto
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
	FILE *salva = fopen("Pasta.dat", "wb");

	/* Controllo apertura del file */
	if (salva == NULL) {
		printf("\nApertura file fallita...\n");
	}
	else {
		/* Salvo contenuto di ogni nodo della lista finchè non raggiungo quello che contiene NULL */
		while (elenco != NULL) {
			fwrite(&elenco->pasta, sizeof(P), 1, salva);		// Scrivo sul file
			elenco = elenco->next;								// Vai avanti
		}

		printf("\nSalvataggio effettuato...\n");
		/* Chiudo il file : scrittura terminata */
		fclose(salva);
	}
}
