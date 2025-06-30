/* Programma che gestisce una rubrica di contatti */

/* Ogni contatto è definito come una struttura con 4 campi :
	
	- Il primo campo è una struct di due campi che contiene nome e cognome del contatto
	- Il secondo campo indica il prefisso del numero di telefono del contatto
	- Il terzo campo è un array di 10 interi che sono le 10 cifre del numero di telefono
	- L'ultimo campo indica il tipo di contatto (ufficio, famiglia, amici)

 * Funzioni secondarie :

 	- Funzione per registrare un nuovo contatto in coda all'interno della rubrica
 	- Funzione che stampa la rubrica richiamando una funzione che stampa ogni singolo contatto
 	- Funzione che cancella tutti i contatti che hanno un prefisso diverso da quello italiano

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Strutture */
/* Struct che gestisce i dati di una persona */
typedef struct Persona {
	char nome[20];
	char cognome[20];
} P;

/* Struct che gestisce i dati di un contatto in rubrica */
typedef struct Contatto {
	P persona;
	int prefisso;
	int numero[10];
	char tipo;
} C;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	C contatto;
	struct Lista *next;
} N;

/* Dichiarazione funzioni secondarie */
void reminder();
void registrazione(N *leggi);
void inserisciCoda(N **nuovo);
void stampaContatto(C *stampa);
void vediRubrica(N *head);
void cancellaPreNonITA(N **elenco);
int precede(C *c1, C *c2);
void scambia(N *n1, N *n2);
void ordinaTipo(N **elenco);

/* Corpo del programma */
int main() {
	/* Input */
	N *rubrica = NULL;				// Inizializzo la lista
	int scelta = -1;				// Scelta dell'utente
	printf("\nCiao utente, sono un programma che gestisce la rubrica di un telefono.\n");

	/* Ciclo d'interazione con l'utente */
	while (scelta != 0) {
		reminder();
		printf("\nInserisci un codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserisciCoda(&rubrica);
		else if (scelta == 2)
			vediRubrica(rubrica);
		else if (scelta == 3)
			cancellaPreNonITA(&rubrica);
		else if (scelta == 4)
			ordinaTipo(&rubrica);

	}
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con le funzionalità associate */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Registri un contatto in coda all'interno della rubrica.");
	printf("\n2 - Visualizza la rubrica corrente.");
	printf("\n3 - Cancella multipla dei contatti che hanno un prefisso diverso da quello italiano..");
	printf("\n4 - Ordina i contatti per tipo.\n");
}

/* Funzione che registra i dati del nuovo nodo della lista */
void registrazione(N *leggi) {
	printf("\nRegistro il prossimo contatto...\n");

	/* Nome contatto */
	printf("\nInserisci il nome del contatto : ");
	fgets(leggi->contatto.persona.nome, 20, stdin);
	leggi->contatto.persona.nome[strlen(leggi->contatto.persona.nome) - 1] = '\0';

	/* Cognome contatto */
	printf("Inserisci il cognome del contatto : ");
	fgets(leggi->contatto.persona.cognome, 20, stdin);
	leggi->contatto.persona.cognome[strlen(leggi->contatto.persona.cognome) - 1] = '\0';

	/* Prefisso contatto */
	do {
		printf("\nInserisci il prefisso del numero di telefono : ");
		scanf("%d", &leggi->contatto.prefisso);
		if (leggi->contatto.prefisso < 0)
			printf("\nRegistrazione fallita...");
	} while (leggi->contatto.prefisso < 0);

	/* Numero di telefono */
	printf("Salva il numero di telefono del contatto...\n\n");
	for (int i = 0; i < 10; i++) {
		printf("Prossima cifra = ");
		scanf("%d", &leggi->contatto.numero[i]);

		if (leggi->contatto.numero[i] < 0 || leggi->contatto.numero[i] > 9)
			while (leggi->contatto.numero[i] < 0 || leggi->contatto.numero[i] > 9) {
				printf("\nInserire di nuovo la cifra di posto %d : ", i);
				scanf("%d", &leggi->contatto.numero[i]);
			}
	}
	scanf("%*c");

	/* Tipo di contatto */
	do {
		printf("\nIl tuo contatto %c relativo a ufficio, famiglia o amici ? ", 138);
		scanf("%c%*c", &leggi->contatto.tipo);
		if (leggi->contatto.tipo != 'a' && leggi->contatto.tipo != 'f' && leggi->contatto.tipo != 'u')
			printf("\nRegistrazione fallita...");
	} while (leggi->contatto.tipo != 'a' && leggi->contatto.tipo != 'f' && leggi->contatto.tipo != 'u');
}

/* Funzione che inserisce un contatto in coda alla rubrica */
void inserisciCoda(N **nuovo) {
	N *registra = malloc(sizeof(N));			// Alloco nodo nell'heap
	/* Lettura campo dati */
	registrazione(registra);
	registra->next = NULL;

	/* Caso speciale (testa vuota) : diventa inserimento in testa */
	if (*nuovo == NULL)
		*nuovo = registra;
	/* Inserimento in coda normale */
	else {
		N *appoggio = *nuovo;					// Nodo d'appoggio

		while (appoggio->next != NULL)
			appoggio = appoggio->next;			// Vai avanti
		appoggio->next = registra;				// Collega i nodi
	}
	printf("\nContatto registrato!\n");
}

/* Funzione che stampa le informazioni del singolo contatto ricevuto come parametro */
void stampaContatto(C *stampa) {
	printf("\n%s %s", stampa->persona.nome, stampa->persona.cognome);
	printf("\n+%d ", stampa->prefisso);
	for (int i = 0; i < 10; i++)
		printf("%d", stampa->numero[i]);
	if (stampa->tipo == 'a')
		printf("\nAmici\n");
	else if (stampa->tipo == 'f')
		printf("\nFamiglia\n");
	else if (stampa->tipo == 'u')
		printf("\nUfficio\n");
}

/* Funzione che stampa a schermo la rubrica corrente */
void vediRubrica(N *head) {
	/* Lista vuota ? */
	if (head == NULL)
		printf("\nRubrica vuota...\n");
	else {
		printf("\nCONTATTI\n");
		printf("\n**********************************\n");

		/* Sfoglia lista */
		while (head != NULL) {
			stampaContatto(&head->contatto);	// Stampa contatto
			head = head->next;					// Nodo successivo
		}
		printf("\n**********************************\n");
	}
}

/* Funzione che cancella dall'elenco tutti i contatti che hanno un prefisso diverso da quello italiano */
void cancellaPreNonITA(N **elenco) {
	/* Lista vuota ? */
	if ((*elenco) == NULL)
		printf("\n0 contatti in rubrica, non devo cancellare nulla...\n");
	else {
		N *check;			// Nodo di supporto 1 (serve per controllare la lista)
		N *prec;			// Nodo di supporto 2 (serve per collegare nodi)

		/* Cancellazioni multiple in testa */
		while ((*elenco) != NULL && (*elenco)->contatto.prefisso != 39) {
			N *dealloca = *elenco;			// Dichiaro nodo per cancellare
			*elenco = (*elenco)->next;		// Cancello
			free(dealloca);					// Dealloco nodo dalla memoria
		}
		/* Inizializzo nodi di supporto */
		check = (*elenco)->next;
		prec = *elenco;

		/* Sfoglio la lista */
		while (check != NULL) {
			/* Ho trovato un contatto da cancellare */
			if (check->contatto.prefisso != 39) {
				prec->next = check->next;				// Cancello
				free(check);							// Deallocazione
				check = prec->next;						// Resetto il nodo di controllo
			}
			/* Non ho trovato il contatto da cancellare -> vado avanti con i nodi normalmente */
			else {
				prec = check;								// Vai avanti
				check = check->next;						// Vai avanti		
			}
		}
		printf("\nCancellazione dei contatti con prefisso straniero riuscita...\n");
	}
}

int precede(C *c1, C *c2) {
	return ((c1->tipo == 'f' && c2->tipo != 'f') || (c1->tipo == 'a' && c2->tipo == 'u') || (c1->tipo == c2->tipo && 
			strcmp(c1->persona.nome, c2->persona.nome) < 0) || c1->tipo == c2->tipo && strcmp(c1->persona.nome, c2->persona.nome) == 0
			&& strcmp(c1->persona.cognome, c2->persona.cognome) < 0);
}

void scambia(N *n1, N *n2) {
	C temp = n1->contatto;
	n1->contatto = n2->contatto;
	n2->contatto = temp;
}

void ordinaTipo(N **elenco) {

	if (*elenco == NULL)
		printf("\nRubrica vuota...\n");
	else {
		N *check;
		N *min;
		N *copia;

		copia = *elenco;

		while (copia->next != NULL) {
			min = copia;
			check = copia->next;

			while (check != NULL) {
				if (precede(&check->contatto, &min->contatto))
					min = check;
				check = check->next;
			}
			scambia(min, copia);
			copia = copia->next;
		}
		printf("\nContatti ordinati per tipo...\n");
	}
}

