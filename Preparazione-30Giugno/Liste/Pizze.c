/* Relizzare un'applicazione per gesire il menù di una pizzeria.
 *
 * Definire due strutture, una per rappresentare un elemento della lista e una per rappresentare
 * una pizza che fa parte del menu. In particolare, l'applicazione deve gestire ciascuna pizza
 * come una struttura con tre campi. Il primo campo è una stringa che indica il nome della pizza,
 * il secondo è un valore reale che indica il suo prezzo e il terzo campo è un carattere che indica
 * se la pizza è vegetariana.

 * Definizire una funzione che visualizza il menu di pizze, stampando per ogni pizza nome, prezzo
 * e se è vegetariana oppure no.

 * Definire una funzione che inserisce una pizza in testa al menù.

 * Definizire una funzione che cancella dal menù la prima pizza vegetariana. Se il menù non contiene
 * alcuna pizza vegetariana viene stampato un messagio che informa l'utente */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che contiene le informazioni di una pizza */
typedef struct Alimento {
	char nome[20];
	float prezzo;
	char tipo;
} P;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	P pizza;
	struct Lista *next;
} N;

/* Dichiarazione funzioni secondarie */
void reminder();
void lettura(N *leggi);
void inserisciInTesta(N **head);
void stampaPizza(P *stampa);
void visualizzaMenu(N *menu);
void cancellaPrimaVeg(N **head);
void cancellaCoda(N **head);

/* Corpo del programma */
int main() {
	/* Input */
	printf("\nCiao utente, con questo programma puoi gestire il menu' di una pizzeria.\n");

	N *menu = NULL;			// Inizializzo la lista
	int scelta = -1;		// Codice scelta per utente
	/* Ciclo d'interazione con l'utente */
	while (scelta != 0) {
		reminder();
		/* Lettura codice comando */
		printf("\nInserisci il codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciInTesta(&menu);
		else if (scelta == 2)
			visualizzaMenu(menu);
		else if(scelta == 3)
			cancellaPrimaVeg(&menu);
		else if (scelta == 4)
			cancellaCoda(&menu);
	}
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione funzioni di supporto <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con le funzionalità del programma associate */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci una pizza in testa al menu'.");
	printf("\n2 - Visualizza il menu' corrente.");
	printf("\n3 - Cancella dal menu' la prima pizza vegetariana.");
	printf("\n4 - Cancella l'ultima pizza del menu'.\n");
}

/* Funzione che legge il campo dati di un nodo ricevuto come parametro */
void lettura(N *leggi) {
	printf("\nInserisci i dati della pizza...\n");
	/* Leggi nome della pizza */
	printf("\nNome : ");
	fgets(leggi->pizza.nome, 20, stdin);
	leggi->pizza.nome[strlen(leggi->pizza.nome) - 1] = '\0';

	/* Leggi il prezzo della pizza */
	do {		
		printf("Prezzo : ");
		scanf("%f%*c", &leggi->pizza.prezzo);
		if (leggi->pizza.prezzo <= 0)
			printf("Impossible registrare il prezzo: reinserisci il dato...\n");
	} while (leggi->pizza.prezzo <= 0);

	/* Leggi il tipo della pizza */
	do {	
		printf("Vegetariana ? ");
		scanf("%c%*c", &leggi->pizza.tipo);
		if (leggi->pizza.tipo != 'v' && leggi->pizza.tipo != 'n')
			printf("\nNon mi hai fornito informazioni sul tipo: reinserisci il dato...\n");
	} while (leggi->pizza.tipo != 'v' && leggi->pizza.tipo != 'n');
}

/* Funzione che inserisce una pizza in testa al menù */
/* Riceve l'indirizzo della testa del main */
void inserisciInTesta(N **head) {
	N *nuovo = malloc(sizeof(N));		// Alloco memoria per il nuovo nodo nell'heap
	/* Leggo il campo dati del nuovo nodo da collegare */
	lettura(nuovo);
	nuovo->next = *head;				// Collego testa passata come parametro al seguito del nuovo nodo

	*head = nuovo;						// Collego la testa della nuova lista a quella ricevuta dal main
}

/* Funzione che stampa a schermo le informazioni di una singola pizza */
void stampaPizza(P *stampa) {
	/* Output */
	printf("\nNome della pizza : %s", stampa->nome);
	printf("\nPrezzo : %.2f", stampa->prezzo);
	if (stampa->tipo == 'v')
		printf("\nPizza vegetariana\n");
	else if (stampa->tipo == 'n')
		printf("\nPizza non vegetariana\n");
}

/* Funzione che stampa a schermo il menu corrente di pizze */
void visualizzaMenu(N *menu) {
	/* Lista vuota ? */
	if (menu == NULL)
		printf("\nMenu' vuoto...\n");
	else {
		printf("\nEcco il menu'\n");
		/* Stampa finchè il nodo non punta a NULL */
		while (menu != NULL) {
			stampaPizza(&menu->pizza);
			menu = menu->next;				// Vai avanti
		}
	}
}

/* Funzione che cancella dal menù la prima pizza vegetariana */
void cancellaPrimaVeg(N **head) {
	/* Lista vuota ? */
	if (*head == NULL)
		printf("\nMenu' vuoto...\n");
	else {
		N *check;		// Nodo di supporto per controllare il corrente
		N *prec;		// Nodo di supporto per collegare

		/* Pizza vegetariana in testa al menù */
		if ((*head)->pizza.tipo == 'v') {
			check = *head;			// Collego i nodi
			*head = (*head)->next;	// Cancello
			free(check);			// Dealloco la memoria
			printf("\nPizza vegetariana in testa al menu' cancellata correttamente...\n");
		}
		/* Pizza vegetariana in mezzo al menù */
		else {
			int trovato = 0;			// Vegetariana trovata
			check = (*head)->next;		// Collego nodo di controllo
			prec = *head;				// Collego altro nodo di supporto

			/* Cerco finchè non raggiungo la fine della lista o non trovo la pizza da cancellare */
			while (check != NULL && !trovato) {
				/* Ho trovato una pizza vegetariana */
				if (check->pizza.tipo == 'v') {
					trovato = 1;				// Cambio variabile di ricerca
					prec->next = check->next;	// Scambio nodi
					free(check);
					printf("\nCancellazione avvenuta con successo...\n");
				}
				/* Non ho (ancora) trovato una pizza vegetariana : vado avanti con i nodi di supporto */
				else {
					prec = check;
					check = check->next;
				}
			}
			/* Nessuna pizza vegetariana nel menù: informo l'utente */
			if (!trovato)
				printf("\nIl menu' non contiene pizze vegetariane: 0 cancellazioni effettuate.\n");
		}
	}
}

/* Funzione che cancella l'ultima pizza della lista */
void cancellaCoda(N **head) {
	/* Lista vuota ? */
	if (*head == NULL)
		printf("\nMenu' vuoto...\n");
	else {
		N *appoggio;
		N *collego;
		if ((*head)->next == NULL) {
			appoggio = *head;			// Collego i nodi
			*head = (*head)->next;		// Cancello
			free(appoggio);				// Dealloco la memoria
			printf("\nUna sola pizza nel menu'. Cancellazione effettuata...\n");
		}
		else {
			appoggio = (*head)->next;
			collego = (*head);
			while (appoggio->next != NULL) {			
				collego = appoggio;
				appoggio = appoggio->next;
			}
			collego->next = appoggio->next;
			free(appoggio);
			printf("\nCancellazione in coda effettuata...\n");
		}
	}
}

