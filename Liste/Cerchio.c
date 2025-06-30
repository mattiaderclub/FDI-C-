/* Realizzare un'applicazione per gestire una lista di cerchi nel piano.
 *
 * L’applicazione deve gestire ciascun cerchio come una struttura con due campi, 
 * che rappresentano il centro ed il raggio del cerchio. 
 * Il centro è a sua volta una struttura con due campi, che rappresentano le coordinate del centro nel piano. 
 *
 * L’applicazione deve permettere all’utente di svolgere le seguenti funzionalità:

		- inserimento di un nuovo cerchio in testa alla lista.
		- cancellazione di un cerchio con dato centro e raggio.
		- visualizzazione della lista corrente di cerchi.
		- verifica se il primo cerchio è strettamente interno al secondo.

 * All’avvio dell’esecuzione l’applicazione deve inizializzare la lista di cerchi con i valori letti da un file;
 * al termine dell’esecuzione l’applicazione deve salvare i dati della lista nello stesso file. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Strutture */
/* Struct che contiene le coordinate di un punto */
typedef struct Punto {
	float x;
	float y;
} P;

/* Struct che contiene i dati del cerchio */
typedef struct Figura {
	P centro;
	float raggio;
} C;

/* Struct che definisce la lista di cerchi */
typedef struct Lista {
	C cerchio;
	struct Lista *next;
} NODO;

/* Dichiarazione funzioni secondarie */
void reminder();
void lettura(NODO *head);
void inserimentoInTesta(NODO **puntaHead);
void cancella(NODO **puntaHead);
int cerchioInterno(NODO **puntaHead);
void stampaCerchio(C *cerchio);
void visualizza(NODO *head);
void leggiDaFile(NODO *head);
void salvaSuFile(NODO *head);

/* Corpo del programma */
int main() {
	/* Input */
	NODO *head = NULL;						// Inizializzazione lista
	int comando = -1;						// Comando per while

	/* Ciclo while di comandi che termina quando il codice comando letto è il numero 0 */
	while (comando != 0) {
		reminder();				// Funzione che stampa a schermo i comandi del programma
		/* Lettura codice comando da usare */
		printf("\nInserisci codice comando: ");
		scanf("%d", &comando);

		if (comando == 1)
			inserimentoInTesta(&head);
		if (comando == 2)
			cancella(&head);
		if (comando == 3)
			visualizza(head);
		if (comando == 4) {
			/* Il primo cerchio in lista è contenuto nel secondo */
			if (cerchioInterno(&head)) {
				printf("\nIl primo cerchio %c interno al secondo.\n", 138);
			}
			else {
				printf("\nIl primo cerchio non %c interno al secondo.\n", 138);				
			}
		}
	}
	/* Salvo su file il contenuto della lista */
	salvaSuFile(head);
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione che ricorda all'utente i comandi a disposizione */
void reminder() {
	printf("\nComandi:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un nuovo cerchio in testa alla lista.");
	printf("\n2 - Cancella un cerchio con dato centro e raggio dato in input.");
	printf("\n3 - Visualizza la lista corrente di cerchi.");
	printf("\n4 - Verifica se il primo cerchio %c strettamente interno al secondo.\n", 138);
}

/* Funzione che legge i valori da salvare nel nodo della lista ricevuto in input */
void lettura(NODO *head) {
	/* Lettura coordinate del centro */
	printf("\nCoordinate del centro\n");
	printf("\nAscissa di O : ");
	scanf("%f", &(head->cerchio.centro.x));
	printf("Ordinata di O : ");
	scanf("%f", &(head->cerchio.centro.y));

	/* Lettura misura del raggio del cerchio */
	printf("Raggio del cerchio : ");
	scanf("%f", &(head->cerchio.raggio));

	/* Se viene letto un raggio negativo, l'utente deve reinserirlo */
	while (head->cerchio.raggio <= 0) {
		printf("\nIl raggio dev'essere positivo. Nuovo valore : ");
		scanf("%f", &(head->cerchio.raggio));
	}
}

/* Funzione che inserisce un elemento in testa alla lista */
void inserimentoInTesta(NODO **puntaHead) {
	NODO *nuovoNodo;							// Nuovo nodo della lista
	nuovoNodo = malloc(sizeof(NODO));			// Allocazione nodo nell'heap

	lettura(nuovoNodo);							// Lettura campo dati

	/* Collega lista ricevuta dalla funzione alla testa del nuovo nodo
	 * (*puntaHead) perchè è stato passato un indirizzo quindi serve un doppio puntatore */
	nuovoNodo->next = *puntaHead;				

	/* Salvo adesso il nuovo nodo nella testa della lista che viene 
	 * automaticamente copiata nel main in quanto passata per indirizzo */
	*puntaHead = nuovoNodo;	
}

/* Funzione che cancella un cerchio dalla lista letti da tastiera il raggio e le coordinate del centro */
void cancella(NODO **puntaHead) {
	float cercaX;					// Ascissa del centro da cercare
	float cercaY;					// Ordinata del centro da cercare
	float cercaRaggio;				// Lunghezza del raggio da cercare

	NODO *nodo;						// Nodo generico di supporto
	NODO *nodoPrec;					// Nodo precedente a quello sopra

	/* Lista vuota ? */
	if ((*puntaHead) == NULL) {
		printf("\nImpossibile cancellare.\n");
	}
	/* Esistono elementi all'interno della lista */
	else {
		/* Lettura valori da cercare */
		printf("\nInserisci i dati del cerchio da cancellare.\n");
		printf("Coordinata x del centro: "),
		scanf("%f", &cercaX);
		printf("Coordinata y del centro: "),
		scanf("%f", &cercaY);
		printf("Lunghezza del raggio: "),
		scanf("%f", &cercaRaggio);

		/* Cerca l'elemento in lista con ascissa, ordinata e raggio letti da tastiera */
		/* Il nodo da cancellare è il primo */
		if (cercaX == (*puntaHead)->cerchio.centro.x &&
			cercaY == (*puntaHead)->cerchio.centro.y &&
			cercaRaggio == (*puntaHead)->cerchio.raggio) {
			
			nodo = *puntaHead;					// da deallocare
			*puntaHead = (*puntaHead)->next;	// Secondo diventa primo (cancella)
			free(nodo);							// Dealloca il nodo
			/* Output */
			printf("\nCancellazione effettuata.\n");
		}
		/* Il nodo da cancellare potrebbe essere in mezzo alla lista */
		else {
			int cancellato = 0;				// Trovato e cancellato ?
			/* Setto i nodi di supporto */
			nodo = (*puntaHead)->next;
			nodoPrec = *puntaHead;		

			/* Finche il nodo che punta più avanti non punta a NULL o non ho cancellato il valore continua */
			while (nodo != NULL && !cancellato) {
				/* Trovato ? */
				if (cercaX == nodo->cerchio.centro.x &&
					cercaY == nodo->cerchio.centro.y &&
					cercaRaggio == nodo->cerchio.raggio) {
					
					cancellato = 1;					// Trovato
					nodoPrec->next = nodo->next;	// Cancello elemento collegando successivo del nodo
													// a successivo del nodo precedente (Rompo collegamento)
					free(nodo);						// Deallocazione
				}
				/* Passo al prossimo elemento facendo avanzare i nodi */
				else {
					nodoPrec = nodo;
					nodo = nodo->next;
				}
			}
			/* Output */
			if (cancellato)
				printf("\nCancellazione effettuata.\n");
			else
				printf("\nCancellazione fallita.\n");			
		}
	}
}

/* Funzione che controlla se il primo cerchio in lista è strettamente interno al secondo */
int cerchioInterno(NODO **puntaHead) {
	int interno = 0;					// è interno al secondo ?
	float calcolo_x = pow((*puntaHead)->cerchio.centro.x - (*puntaHead)->next->cerchio.centro.x, 2);	// Quadrato differenza ascisse
	float calcolo_y = pow((*puntaHead)->cerchio.centro.y - (*puntaHead)->next->cerchio.centro.y, 2);	// Quadrato differenza ordinate
	float distanza = sqrt(calcolo_x + calcolo_y);			// Distanza tra 2 punti

	/* Ho almeno 2 elementi in lista */
	if (*puntaHead != NULL && (*puntaHead)->next != NULL) {
		/* Il primo è contenuto nel secondo se e solo se la distanza tra i centri più
		 * il raggio del primo cerchio è minore o uguale al raggio del secondo cerchio */
		if (distanza + (*puntaHead)->cerchio.raggio <= (*puntaHead)->next->cerchio.raggio)
			interno = 1;				// Primo interno al secondo
	}
	return interno;						// Valore di ritorno
}

/* Funzione che stampa i dati del cerchio ricevuto in input */
void stampaCerchio(C *cerchio) {
	/* Output */
	printf("\nCentro del cerchio : (%.2f,%.2f)", cerchio->centro.x, cerchio->centro.y);
	printf("\nIl raggio %c lungo %.2f\n", 138, cerchio->raggio);
}

/* Funzione che stampa la lista di cerchi salvati in lista */
void visualizza(NODO *head) {
	/* Lista vuota ? */
	if (head == NULL) {
		printf("\nLista vuota!\n");
	}
	/* Ho qualcosa in lista */
	else {
		/* Output */
		printf("\nLista di cerchi:\n");
		while (head != NULL) {
			/* Richiamo funzione finchè nodo non punta a NULL */
			stampaCerchio(&head->cerchio);
			head = head->next;				// Passo al nodo successivo
		}
	}
}

/* Funzione che legge il contenuto di un file binario */
void leggiDaFile(NODO *head) {
	FILE *fpin = fopen("Cerchi.dat", "rb");

	if (fpin == NULL)
		printf("\nApertura file fallita.\n");
}

/* Funzione che salva su file il contenuto della lista */
void salvaSuFile(NODO *head) {
	/* Apro file in scrittura */
	FILE *fpout = fopen("Cerchi.dat", "wb");

	/* Scrivo dentro al file finchè non arrivo all'ultimo nodo */
	while (head != NULL) {
		fwrite(&(head->cerchio), sizeof(C), 1, fpout);
		head = head->next;				// Passo al nodo successivo
	}
	/* Chiusura file */
	fclose(fpout);
}
