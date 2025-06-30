/* Realizzare un'applicazione per gestire una lista di punti nel piano cartesiano.

 * L’applicazione deve gestire ciascun punto come una struttura con tre campi, che rappresentano il colore del punto 
 * (rappresentato da una stringa di 20 caratteri) e le coordinate del punto nel piano. 

 * L’applicazione deve permettere all’utente di svolgere le seguenti funzionalità:

		- Inserimento di un nuovo punto in testa alla lista, dopo aver letto le sue coordinate e il suo colore da tastiera. 
 		- Visualizzazione della lista di punti.
		- Cancellazione del punto a coordinata y minima.
		- Calcolo e stampa dei due punti nella lista la cui distanza Euclidea è minima.
		- Visualizzazione dei punti che hanno un certo colore (a scelta dell'utente).

 * Promemoria: La distanza fra due punti (x1, y1) e (x2, y2) è la radice quadrata di ((x2-x1)^2 + (y2-y1)^2). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Strutture */
/* Struct che gestisce ogni punto */
typedef struct Punto {
	float x;
	float y;
	char colore[20];
} P;

/* Struct che gestisce la lista di punti */
typedef struct Lista {
	P punto;
	struct Lista *next;
} NODO;

/* Dichiarazione funzioni di supporto */
void reminder();
void lettura(NODO *head);
void inserimentoInTesta(NODO **puntaHead);
void stampaPunto(P punto);
void visualizzaLista(NODO *head);
float trovaOrdinataMin(NODO *head);
void cancellaYMinima(NODO **puntaHead);
float distanza(P punto1, P punto2);
float cercaDistMinima(NODO *head);
void stampaDistMinima(NODO *head);
void visuallizzaColorati(NODO *head);

/* Corpo del programma */
int main() {
	/* Input */
	NODO *head = NULL;				// Inizializzo la lista
	int scelta = -1;				// Comando per while
	printf("\nSono un programma che gestisce una lista di punti nel piano cartesiano.\n");

	/* Ciclo while di comandi che termina quando il codice comando letto è il numero 0 */
	while (scelta != 0) {
		reminder();				// Funzione che stampa a schermo i comandi del programma
		/* Lettura codice comando da usare */
		printf("\nInserisci codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserimentoInTesta(&head);
		if (scelta == 2)
			visualizzaLista(head);
		if (scelta == 3)
			cancellaYMinima(&head);
		if (scelta == 4)
			stampaDistMinima(head);
		if (scelta == 5)
			visuallizzaColorati(head);
	}
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione che stampa a schermo le funzionalità possibili all'interno del programma con i codici associati */
void reminder() {
	printf("\nCOMANDI.\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un nuovo punto in testa alla lista.");
	printf("\n2 - Visualizza la lista corrente di punti.");
	printf("\n3 - Cancella il punto con l'ordinata (y) minima.");
	printf("\n4 - Calcola e stampa i 2 punti la cui distanza euclidea %c minima.", 138);
	printf("\n5 - Visuallizza i punti che hanno un certo colore dato dall'utente.\n");
}

/* Funzione che legge il campo dati da inserire all'interno del nodo: coordinate e colore del punto */
void lettura(NODO *head) {
	/* Lettura informazioni del punto */
	printf("\nInserisci i dati del punto\n");

	/* Lettura coordinate */
	printf("\nCoordinata x del punto : ");
	scanf("%f", &(head->punto.x));
	printf("Coordinata y del punto : ");
	scanf("%f%*c", &(head->punto.y));

	/* Lettura colore */
	printf("\nColore : ");
	fgets(head->punto.colore, 20, stdin);
	/* Rimuovi \n */
	head->punto.colore[strlen(head->punto.colore) - 1] = '\0';
}

/* Funzione che inserisce un nuovo elemento in testa alla lista */
void inserimentoInTesta(NODO **puntaHead) {
	NODO *nuovoNodo;					// Nuovo nodo della lista
	nuovoNodo = malloc(sizeof(NODO));	// Alloca nodo nell'heap

	/* Lettura campo dati */
	lettura(nuovoNodo);

	nuovoNodo->next = *puntaHead;		// Testa della lista si collega al nodo successivo
	/* Il nuovo nodo comprende campo dati inserito seguito
	 * da testa della lista ricevuta dalla funzione */
	*puntaHead = nuovoNodo;				// Nuovo nodo si collega alla testa
}

/* Funzione che riceve in input un punto e ne stampa le informazioni */
void stampaPunto(P punto) {
	/* Output */
	printf("\nCoordinate del punto : (%.2f,%.2f)", punto.x, punto.y);
	printf("\nColore del punto : %s\n", punto.colore);
}

/* Funzione che riceve in input la testa della lista e ne stampa il contenuto */
void visualizzaLista(NODO *head) {
	/* Controllo contenuto della lista */
	if (head == NULL) {						// Lista vuota
		printf("\nçLista vuota.\n");
	}
	else {									// Presente del contenuto in lista
		/* Output */
		printf("\nEcco la lista di punti:\n");
		while (head != NULL) {
			stampaPunto(head->punto);		// Stampa informazioni del punto nel nodo corrente
			head = head->next;				// Passa al nodo successivo
		}
	}
}

float trovaOrdinataMin(NODO *head) {
	/* Controllo contenuto della lista */
	if (head == NULL) {						// Lista vuota
		printf("\nLista vuota.\n");
	}
	else {									// Presente del contenuto in lista
		float minimaY = head->punto.y;		// Ordinata minima inizializzata all'ordinata della testa
		head = head->next;					// Passo al nodo successivo (testa non è da controllare)
		/* Vado avanti finchè nodo non punta NULL */
		while (head != NULL) {
			/* Controllo se ordinata del nodo corrente è più piccola del minimo */
			if (minimaY > head->punto.y)
				minimaY = head->punto.y;	// Memorizzo nuovo valore

			head = head->next;				// Passo al prossimo nodo
		}
		return minimaY;						// Valore di ritorno
	}
}

/* Funzione che riceve come parametro l'indirizzo della testa della lista e cancella
 * l'elemento con ordinata minima all'interno della lista */
void cancellaYMinima(NODO **puntaHead) {
	/* Lista vuota ? */
	if (*puntaHead == NULL) {
		printf("\nLista vuota.\n");
	}
	else {
		float cercato = trovaOrdinataMin(*puntaHead);			// Minimo lista da cercare

		NODO *corrente;
		NODO *prec;

		if (cercato == (*puntaHead)->punto.y) {
			corrente = *puntaHead;
			*puntaHead = (*puntaHead)->next;
			free(corrente);
			printf("\nCancellazione effettuata.\n");
		}
		else {
			int cancellato = 0;
			corrente = (*puntaHead)->next;
			prec = *puntaHead;

			while (corrente != NULL && !cancellato) {
				if (cercato == corrente->punto.y) {

					prec->next = corrente->next;
					cancellato = 1;
					printf("\nCancellazione effettuata.\n");
					free(corrente);

				}
				else {
					prec = corrente;
					corrente = corrente->next;					
				}
			}
		}
	}
}

/* Funzione che riceve come parametri due punti e ne calcola la distanza */
float distanza(P p1, P p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float cercaDistMinima(NODO *head) {

	if (head == NULL || head->next == NULL) {
		printf("\nNon sono presenti almeno due punti in lista.\n");
	}
	else {
		float minDist = distanza(head->punto, head->next->punto);	// i del for è la head
		float calcolo;
		NODO *check = head->next;									// j del for 

		while (head->next != NULL) {
			while (check != NULL) {
				if (minDist > distanza(head->punto, check->punto))
					minDist = distanza(head->punto, check->punto);

				check = check->next;
			}
			head = head->next;
		}
		return minDist;
	}
}

void stampaDistMinima(NODO *head) {

	float cerca = cercaDistMinima(head);

	if (head == NULL || head->next == NULL) {
		printf("\nNon sono presenti almeno due punti in lista.\n");
	}
	else {
		int trovato = 0;
		NODO *check = head->next;

		while (head->next != NULL && !trovato) {
			while (check != NULL && !trovato) {
				if (cerca == distanza(head->punto, check->punto)) {
					trovato = 1;
					printf("\nLa distanza minima tra i due punti:\n");
					stampaPunto(head->punto);
					stampaPunto(check->punto);
					printf("\nmisura %.3f\n", cerca);
				}
				check = check->next;
			}
			head = head->next;
		}
	}
}

/* Funzione che chiede all'utente di inserire un colore e stampa a schermo 
 * la lista di punti dello stesso colore letto da tastiera */
void visuallizzaColorati(NODO *head) {
	/* Controllo contenuto della lista */
	if (head == NULL) {						// Lista vuota
		printf("\nLista vuota.\n");
	}
	else {									// Presente del contenuto nella lista
		int trovato = 0;					// Trovato il colore cercato ?
		char cercaColore[20];				// Colore da cercare

		/* Lettura colore da cercare */
		printf("\nColore dei punti da cercare: ");
		fgets(cercaColore, 20, stdin);
		/* Rimuovi \n */
		cercaColore[strlen(cercaColore) - 1] = '\0';

		/* Vado avanti finchè il nodo non punta NULL */
		while(head != NULL) {
			/* Confronto la stringa "colore" del nodo corrente con la stringa letta da tastiera */
			if (strcmp(head->punto.colore, cercaColore) == 0) {
				trovato = 1;
				if (trovato) {
					/* Output: hai trovato un punto dal colore cercato */
					stampaPunto(head->punto);
				}
			}
			head = head->next;				// Passa al nodo successivo
		}
		/* Output */
		if (!trovato)
			printf("\nNon ho trovato cerchi di colore %s.\n", cercaColore);
	}
}

