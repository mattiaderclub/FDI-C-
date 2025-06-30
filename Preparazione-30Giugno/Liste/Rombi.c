/* L’applicazione deve gestire ciascun rombo come una struttura con tre campi, che rappresentano 

 *  - Vertice alto
 *	- Vertice basso 
 *	- Lunghezza diagonale orizzontale

 * Inoltre ciascun vertice deve essere gestito come una struttura con due campi, che rappresentano le coordinate del vertice nel piano. 
 * L’applicazione deve permettere all’utente di svolgere le seguenti funzionalità.

 *  - Inserimento di un nuovo rombo in testa alla lista, dopo aver letto la lunghezza della diagonale orizzontale e 
 		le coordinate dei due vertici a e b (deve essere letta la coordinata x di un solo vertice fra a e b, in quanto x(a)=x(b)).
 *	- Cancellazione dell’ultimo rombo della lista.
 *	- Visualizzazione della lista corrente di rombi, ciascuno comprensivo di:

		o	Vertice in alto, vertice in basso e lunghezza della diagonale orizzontale
		o	Perimetro 
		o	Area 
		o	Indicazione se il rombo è un quadrato oppure no.

 * Promemoria: Un rombo è “composto” da quattro triangoli rettangoli uguali, osservazione che, applicando il teorema di Pitagora, 
 * permette di calcolare il perimetro del rombo.  
 * All’avvio dell’esecuzione l’applicazione deve inizializzare la lista di rombi con i valori letti da un file; 
 * al termine dell’esecuzione l’applicazione deve salvare i dati della lista nello stesso file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Strutture */
/* Struct che gestisce le coordinate di un punto */
typedef struct Coordinate {
	float x;			// Ascissa
	float y;			// Ordinata
} P;

/* Struct che gestisce i dati di un rombo */
typedef struct Rombo {
	P alto;				// Vertice 1
	P basso;			// Vertice 2
	float orizzontale;			// Lunghezza diagonale orizzontale
} R;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	R rombo;
	struct Lista *next;
} N;

/* Funzioni di supporto */
void reminder();
void campoDati(N *leggi);
void inserisciTesta(N **nuovo);
float perimetro();
float area(R *rombo);
int isQuadrato();
void stampaRombo(R *stampa);
void visualizzaElenco(N *lista);
void cancellaCoda(N **rombi);
void acquisizione(N **crea);
void salvataggio(N *lista);

/* Corpo del programma */
int main() {
	/* Input */
	int scelta = -1;				// Scelta utente
	N *figure;						// Dichiaro lista
	acquisizione(&figure);			// Acquisisco lista da file

	printf("\nCiao utente, sono un programma che gestisce una lista di rombi.\n");

	/* Ciclo d'interazione con l'utente con lettura di un codice comando */
	while (scelta != 0) {
		reminder();
		printf("\nInserisci un codice comando : ");
		scanf("%d", &scelta);

		/* Funzioni a disposizione */

	}
	/* Salvo su un file */
	salvataggio(figure);
	/* Fine programma */
	printf("\nChiusura programma...\n");
}

/* -----> Definizione funzioni di supporto <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con le funzionalità del programma associate a ciascun codice */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma");
	printf("\n1 - Inserimento in testa");
	printf("\n2 - Visualizzazione");
	printf("\n3 - Cancellazione della coda");
}

/* Funzione che registra il campo dati del nodo ricevuto come parametro */
void campoDati(N *leggi) {
	printf("Registro i dati del prossimo rombo...\n");

	/* Lettura coordinata x */
	printf("\nInserisci la coordinata x dei vertici : ");
	scanf("%f", leggi->rombo.basso.x);
	leggi->rombo.alto.x = leggi->rombo.basso.x;

	/* Lettura coordinata y */
	printf("Inserisci la coordinata y del vertice in basso : ");
	scanf("%f", leggi->rombo.basso.y);
	do {
		printf("Inserisci la coordinata y del vertice in alto : ");
		scanf("%f", leggi->rombo.alto.y);
		if (leggi->rombo.alto.y <= leggi->rombo.basso.y)
			printf("\nRegistrazione fallita...\n");
	} while (leggi->rombo.alto.y <= leggi->rombo.basso.y);

	/* Lettura lunghezza diagonale orizzontale */
	do {
		printf("\nLunghezza della diagonale orizzontale del rombo : ");
		scanf("%f", leggi->rombo.orizzontale);
		if (leggi->rombo.orizzontale <= 0)
			printf("\nRegistrazione fallita...\n");
	} while (leggi->rombo.orizzontale <= 0);

	printf("\nRombo registrato !\n");
}

/* Funzione che riceve l'indirizzo della testa della lista e inserisci un rombo in testa ad essa */
void inserisciTesta(N **nuovo) {
	N *registra = malloc(sizeof(N));		// Alloco nodo da registrare nell'heap
	campoDati(registra);					// Registro campo dati

	registra->next = *nuovo;				// Creo nuova lista dentro nodo per registrazione
	*nuovo = registra;						// Collego le testa -> Ho inserito in testa
	printf("Inserimento in testa riuscito...\n");
}

/* Funzione che calcola il perimetro di un rombo */
float perimetro() {
	return (sqrt((rombo->orizzontale/2 * rombo->orizzontale/2) + (((rombo->alto.y - rombo->basso.y)/2)* ((rombo->alto.y - rombo->basso.y)/2)))) * 4;
}

/* Funzione che calcola l'area di un rombo */
float area(R *rombo) {
	return ((rombo->orizzontale)*(rombo->alto.y - rombo->basso.y))/2;
}

/* Funzione che controlla se un rombo è un quadrato oppure no */
int isQuadrato(R *rombo) {
	return rombo->orizzontale == (rombo->alto.y - rombo->basso.y);
}

/* Funzione che stampa i dati di un singolo rombo */
void stampaRombo(R *stampa) {
	/* Output */
	printf("\nVertice alto : (%.2f, %.2f)", stampa->alto.x, stampa->alto.y);
	printf("\nVertice basso : (%.2f, %.2f)", stampa->basso.x, stampa->basso.y);
	printf("\nPerimeto : %.2f", perimetro(stampa));
	printf("\nArea : %.2f", area(stampa));

	if (isQuadrato(stampa))
		printf("\nIl rombo %c un quadrato !\n", 138);
	else
		printf("\nIl rombo non %c un quadrato !\n", 138);
}

/* Funzione che stampa a schermo l'elenco di rombi registrati in lista */
void visualizzaElenco(N *lista) {
	/* Lista vuota ? */
	if (lista == NULL)
		printf("\nNessun rombo da visualizzare...\n");
	else {
		printf("\nROMBI:\n");
		printf("\n*****************************\n");

		/* Stampo finchè non incontro il nodo nullo */
		while(lista != NULL) {
			stampaRombo(&lista->rombo);
			lista = lista->next;			// Vai avanti
		}
		printf("\n*****************************\n");
	}
}

/* Funzione che riceve l'indirizzo della testa della lista e cancella la coda */
void cancellaCoda(N **rombi) {
	/* Lista vuota ? */
	if (*rombi == NULL)
		printf("\nNessun rombo da cancellare...\n");
	else {

		/* Caso speciale : cancellazione in testa */
		if ((*rombi)->next == NULL) {
			N *appoggio = *rombi;			// Copio lista per non perdere nulla
			*rombi = (*rombi)->next;		// Cancello
			free(appoggio);					// Dealloco nodo
			printf("\nCancellazione effettuata...\n");
		}

		/* No caso speciale -> Cerco la coda */
		else {
			N *check = (*rombi)->next;		// Nodo di controllo	
			N *prec = *rombi;				// Nodo di collegamento

			/* Sfoglio la lista fino ad arrivare alla coda */
			while (check->next != NULL) {
				/* Vado avanti con entrambi i nodi */
				prec = check;
				check = check->next;
			}
			prec->next = check->next;		// Cancello
			free(check);					// Dealloco

			printf("\nCancellazione in coda riuscita...\n");
		}
	}
}

/* Funzione che legge da file e crea la lista con i dati memorizzati sul file */
void acquisizione(N **crea) {
	*crea = NULL;				// Inizializzo la lista

	/* Apro file binario in lettura */
	FILE *leggi = fopen("Rombi.dat", "rb");

	/* Controllo esistenza del file */
	if (leggi == NULL)
		printf("\nFile inesistente...\n");
	else {

		R lettura;			// Appoggio per lettura
		/* Controllo se ho elementi da leggere */
		if (fread(&lettura, sizeof(R), 1, leggi) > 0) {

			N *memorizza = malloc(sizeof(N));			// Alloco nodo nell'heap
			memorizza->rombo = lettura;					// Memorizzo valore letto
			*crea = memorizza;							// Collego le teste
			/* Continuo la lettura finchè non raggiungo fine file */
			while (fread(&lettura, sizeof(R), 1, leggi) > 0) {

				memorizza->next = malloc(sizeof(N));	// Alloco nodo successivo
				memorizza = memorizza->next;			// Mi sposto
				memorizza->rombo = lettura;				// Memorizzo rombo
			}
			printf("\nDati recuperati...\n");
		}
		else
			printf("\nFile vuoto...\n");
		fclose(leggi);							// Chiudo file
	}
}

/* Funzione che salva il contenuto di una lista all'interno di un file binario */
void salvataggio(N *lista) {
	/* Apro file binario in scrittura */
	FILE *salva = ("Rombi.dat", "wb");

	/* Controllo apertura file */
	if (salva == NULL)
		printf("\nApertura file fallita...");
	else {

		/* Salvo ogni nodo della lista finchè non incontro nodo nullo */
		while (lista != NULL) {
			fwrite(&lista->rombo, sizeof(R), 1, salva);		// Scrivo su file
			lista = lista->next;							// Vai avanti
		}
		printf("\nDati memorizzati...");
		fclose(salva);						// Chiudo file
	}
}


