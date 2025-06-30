/* Realizzare un'applicazione per gestire una lista di rettangoli con lati paralleli agli assi coordinati.
 *
 * L’applicazione deve gestire ciascun rettangolo come una struttura con due campi, che rappresentano il vertice in basso a sinistra 
 * (bs in figura) ed il vertice in alto a destra (ad in figura) del rettangolo. 
 * Inoltre ciascun vertice deve essere gestito come una struttura con due campi, che rappresentano le coordinate del vertice nel piano. 
 * L’applicazione deve permettere all’utente di svolgere le seguenti funzionalità:

	- Inserimento di un nuovo rettangolo in testa alla lista, dopo aver letto: le coordinate del vertice in basso a sinistra,
		 la lunghezza del lato orizzontale e la lunghezza del lato verticale.
	- Cancellazione di tutti i rettangoli che hanno area maggiore di 10.
	- Visualizzazione della lista corrente di rettangoli, ciascuno comprensivo dei quattro vertici, di perimetro ed area 
		 e dell’indicazione se il rettangolo è un quadrato oppure no.
	- Calcolo dell’intersezione fra due rettangoli r1 ed r2 a scelta dell’utente e, nel caso in cui tale intersezione sia 
		 un rettangolo r3 di area>0 diverso da r1 ed r2, inserisca r3 in testa alla lista.

 * All’avvio dell’esecuzione l’applicazione deve inizializzare la lista di rettangoli con i valori letti da un file;
 * al termine dell’esecuzione l’applicazione deve salvare i dati della lista nello stesso file. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Strutture */
/* Struct che gestisce le coordinate di un punto */
typedef struct Coordinate {
	float x;
	float y;
} P;

typedef struct Rettangolo {
	P bs;
	P ad;
} FIGURA;

/* Struct che gestisce il nodo della lista */
typedef struct Lista {
	FIGURA rett;
	struct Lista *next;
} N;

/* Dichiarazione funzioni secondarie */
void reminder();
void campoDati(N *nodo);
void inserimentoInTesta(N **puntaHead);
int isQuadrato(FIGURA *rett);
float area(FIGURA *rett);
void stampaRett(FIGURA *rett);
void visualizzaLista(N *head);
int quantiAreaMagg10(N *head);
void cancellaRettArea10(N **puntaHead);
void salvaSuFile(N *head);
void leggiDaFile(N **puntaHead);

/* Corpo del programma */
int main() {
	/* Input */
	N *head;
	leggiDaFile(&head);
	int scelta = -1;

	while (scelta != 0) {
		reminder();
		printf("\nInserisci codice comando: ");
		scanf("%d", &scelta);

		if (scelta == 1)
			inserimentoInTesta(&head);
		else if (scelta == 2)
			cancellaRettArea10(&head);
		else if (scelta == 3)
			visualizzaLista(head);
		else if (scelta == 4)
			printf("\n");			// Intersezione (!?)
	}
	/* Salvo su file */
	salvaSuFile(head);
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -------> Defininizione funzioni secondarie <------- */

/* Funzione che stampa a schermo una legenda dei comandi (e funzionalità associate) a disposizione dell'utente */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un rettangolo in testa alla lista.");
	printf("\n2 - Cancella tutti i rettangoli con area > 10.");
	printf("\n3 - Visualizza la lista corrente di rettangoli.");
	printf("\n4 - Calcola l'intersezione.\n");
}

/* Funzione che legge il campo dati di un nodo della lista ricevuto come parametro */
void campoDati(N *nodo) {
	float base;					// Base rettangolo
	float altezza;				// Altezza rettangolo
	/* Leggo il campo dati */
	printf("\nInserisci i dati del rettangolo...\n");
	/* Coordinate vertice in basso a sinistra */
	printf("\nCoordinata x del vertice basso sinistra : ");
	scanf("%f", &nodo->rett.bs.x);
	printf("Coordinata y del vertice basso sinistra : ");
	scanf("%f", &nodo->rett.bs.y);

	/* Leggo base e altezza del rettangolo per calcolare 
	 * poi il vertice in alto a destra finchè sono positive entrambe */
	do {
		printf("\nLunghezza della base : ");
		scanf("%f", &base);
		printf("Altezza del rettangolo : ");
		scanf("%f", &altezza);
		/* Se non vanno bene stampa messaggio di reinserimento */
		if (base <= 0 || altezza <= 0) {
			printf("\nHo bisogno di valori positivi.");
			printf("\nReinserisci la base e l'altezza del rettangolo...\n");
		}
	} while (base <= 0 || altezza <= 0);

	/* Memorizzo adesso le coordinate del vertice in alto a destra */
	nodo->rett.ad.x = nodo->rett.bs.x + base;
	nodo->rett.ad.y = nodo->rett.bs.y + altezza;
}

/* Funzione che riceve come parametro l'indirizzo della testa della lista e inserisce un elemento in testa */
void inserimentoInTesta(N **puntaHead) {
	N* nuovoNodo = malloc(sizeof(N));	// Alloco nuovo nodo della lista nell'heap

	/* Leggo i dati del nuovo nodo della lista */
	campoDati(nuovoNodo);

	nuovoNodo->next = *puntaHead;		// Collego la testa passata come parametro al nodo successivo del nuovo nodo
	*puntaHead = nuovoNodo;				// Collego il nuovo nodo creato alla testa della lista del main
}

/* Funzione che controlla se un rettangolo è un quadrato */
int isQuadrato(FIGURA *rett) {
	return (rett->ad.x - rett->bs.x) == (rett->ad.y - rett->bs.y);
}

/* Funzione che calcola l'area di un rettangolo */
float area(FIGURA *rett) {
	return (rett->ad.x - rett->bs.x)*(rett->ad.y - rett->bs.y);
}

/* Funzione che stampa i dati di un rettangolo ricevuto come parametro in input */
void stampaRett(FIGURA *rett) {
	/* Stampo le coordinate dei quattro vertici del rettangolo */
	printf("\nVertice in basso a sinistra : (%.2f,%.2f)", rett->bs.x, rett->bs.y);
	printf("\nVertice in basso a destra : (%.2f,%.2f)", rett->ad.x, rett->bs.y);
	printf("\nVertice in alto a sinistra : (%.2f,%.2f)", rett->bs.x, rett->ad.y);
	printf("\nVertice in alto a destra : (%.2f,%.2f)", rett->ad.x, rett->ad.y);
	/* Stampo area e perimetro del rettangolo */
	printf("\nPerimetro : %.2f", (2*(rett->ad.x - rett->bs.x) + 2*(rett->ad.y - rett->bs.y)));
	printf("\nArea : %.2f", area(rett));
	/* Stampo un messaggio che indica se il rettangolo è un quadrato o no */
	if (isQuadrato(rett))
		printf("\nLa figura rappresentata %c un quadrato.\n", 138);
	else
		printf("\nLa figura rappresentata %c un rettangolo.\n", 138);
}

/* Funzione che stampa a schermo la lista corrente di rettangoli ognuno comprensivo delle informazioni richieste:
 * coordinate dei quattro vertici, perimetro, area e indicazione se è un quadrato o no */
void visualizzaLista(N *head) {
	/* Lista vuota */
	if (head == NULL)
		printf("\nLista vuota.\n");
	/* La lista non è vuota */
	else {
		printf("\nECCO LA LISTA DI RETTANGOLI:\n");
		/* Vado avanti finchè non punta a NULL */
		while (head != NULL) {
			stampaRett(&head->rett);		// Stampo rettangolo del nodo corrente
			head = head->next;				// Passo al nodo successivo
		}
	}
}

/* Funzione che conta quanti rettangoli della lista hanno area maggiore di 10 */
int quantiAreaMagg10(N *head) {
	int conta = 0;					// Conta quanti rettangoli hanno area > 10
	/* Vado avanti finchè nel nodo è presente del contenuto */
	while (head != NULL) {
		/* Controllo l'area del rettangolo del nodo controllato */
		if (area(&head->rett) > 10)
			conta++;				// Incremento contatore

		head = head->next;			// Passo al nodo successivo
	}
	return conta;					// Valore di ritorno
}

/* Funzione che riceve come parametro l'indirizzo della testa della lista
 * e cancella tutti i rettangoliche hanno un'area maggiore di 10 */
void cancellaRettArea10(N **puntaHead) {
	int daCancellare = quantiAreaMagg10(*puntaHead);			// Quanti rettangoli devo cancellare
	N *check;													// Nodo di supporto che controlla valori
	N *prec;													// Nodo di supporto per fare scambio nodi
	/* Lista vuota */
	if (*puntaHead == NULL) {
		printf("\nLista vuota.\n");
	}
	/* C'è qualcosa all'interno della lista */
	else {
		/* Se non c'è nulla da cancellare esco subito sennò devo cancellare */
		if (daCancellare == 0) {
			printf("\nNessun rettangolo da cancellare.\n");
		}
		else {
			/* Cancello in testa o finchè o roba da cancellare o finchè devo cancellare perchè l'area
			 * è maggiore di 10 o perchè la testa non è vuota */
			while (*puntaHead != NULL && area(&(*puntaHead)->rett) > 10 && daCancellare!=0) {
				N *cancInTesta = *puntaHead;			// Dichiaro nodo per cancellare in testa
				*puntaHead = (*puntaHead)->next;		// Cancello
				daCancellare--;							// Un elemento in meno da cancellare
				free(cancInTesta);						// Dealloco nodo di supporto
			}
			/* Devo cancellare altro in mezzo alla lista */
			if (daCancellare == 0)
				printf("\nCancellazione terminata...\n");
			else {
				check = (*puntaHead)->next;				// Nodo che segue valore controllato
				prec = *puntaHead;						// Nodo per scambio
				/* Vado avanti finchè non punta a NULL o ho qualcosa da cancellare */
				while (check != NULL && daCancellare!=0) {
					if (area(&check->rett) > 10) {
						daCancellare--;					// Devo cancellare un rettangolo in meno
						prec->next = check->next;		// Prec->next è check (da cencellare)
														// ci memorizzo quindi il valore successivo
						free(check);
						check = prec->next;				// Resetto check
					}
					else {
						/* Porto avanti entrambi i nodi di supporto */
						prec = check;
						check = check->next;

					}
				}
				/* Cancellazione finita */
				printf("\nCancellazione terminata...\n");
			}
		}
	}		 	
}

/* Funzione che salva il contenuto della lista su un file binario */
void salvaSuFile(N *head) {
	/* Apro file binario in scrittura */
	FILE *fpout = fopen("Rettangoli.dat", "wb");

	/* Apertura file fallita */
	if (fpout == NULL)
		printf("\nApertura file fallita...\n");
	else {
		if (head == NULL)
			printf("\nNon c'%c nulla da salvare.\n", 138);
		else {
			while (head != NULL) {
				fwrite(&head->rett, sizeof(FIGURA), 1, fpout);
				head = head->next;
			}
			printf("\nSalvataggio effettuato...");
		}
		fclose(fpout);
	}
}

/* Funzione che legge il contenuto di un file binario e lo inserisce in una lista */
/* Meccaniscmo doppio puntatore */
void leggiDaFile(N **puntaHead) {
	*puntaHead = NULL;
	
	/* Apro file binario in lettura */
	FILE *fpin = fopen("Rettangoli.dat", "rb");

	/* Apertura file fallita */
	if (fpin == NULL)
		printf("\nApertura file fallita...\n");
	/* File aperto */
	else {
		FIGURA rettangolo;			// Struct per lettura
		if (fread(&rettangolo, sizeof(FIGURA), 1, fpin) != EOF) {
			N* check = malloc(sizeof(N));
			check->rett = rettangolo;
			*puntaHead = check;
			while (fread(&rettangolo, sizeof(FIGURA), 1, fpin) > 0) {
				check->next = malloc(sizeof(N));
				check = check->next;
				check->rett = rettangolo;
			}
			check->next = NULL;
			/* Lettura terminata */
			printf("\nLettura effettuata...\n");
		}
		else
			printf("\nFile vuoto...\n");
		/* Chiusura file per la lettura */
		fclose(fpin);
	}
}