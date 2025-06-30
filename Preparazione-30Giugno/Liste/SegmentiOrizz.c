#include <stdio.h>
#include <stdlib.h>

/*****************************/
/********* STRUTTURE *********/
/*****************************/
typedef struct Estremo {
	float x;
	float y;
} PUNTO;

typedef struct Segmento {
	PUNTO estSx;
	float lung;
} S;

typedef struct Lista {
	S segmento;
	struct Lista *next;
} N;

/* ********************************************/
/************* FUNZIONI SECONDARIE ************/
/**********************************************/
void campoDati(N *leggi);
void inserisciInCoda(N **nuovo);
void stampaSegmento(S *stampa);
void visualizzaLista(N *lista);
void cancellaSeg12(N **cancella);

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/
int main() {
	/* Inizializza la lista */
	N *segmenti = NULL;
	int risposta = -1;			// Per interazione con utente

	while(risposta != 0) {
		/* Richiedi un'operazione all'utente */
		printf("\nChe operazione vuoi svolgere?\n");
		printf("1 -> Inserimento\n");
		printf("2 -> Visualizzazione\n");
		printf("3 -> Cancellazione\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* Gestisci le operazioni dell'utente */
		if(risposta==1)
			inserisciInCoda(&segmenti);
		else if(risposta==2)
			visualizzaLista(segmenti);
		else if(risposta==3)
			cancellaSeg12(&segmenti);
		else if(risposta==0)
			printf("\nChiusura programma...\n");
		else printf("Selezione non valida!\n");
	}
}

/**********************************************
 **************** INSERIMENTO *****************
 **********************************************/
void campoDati(N *leggi) {
	printf("\nInserisci i dati...\n");
	printf("\nCoordinata x dell'estremo sinistro : ");
	scanf("%f", &leggi->segmento.estSx.x);
	printf("Coordinata y dell'estremo sinistro : ");
	scanf("%f", &leggi->segmento.estSx.y);
	printf("Lunghezza del segmento : ");
	scanf("%f", &leggi->segmento.lung);
	printf("\nRegistrazione effettuata...\n");
}

void inserisciInCoda(N **nuovo) {
	N *registra = malloc(sizeof(N));

	campoDati(registra);
	registra->next = NULL;

	if (*nuovo == NULL)
		*nuovo = registra;
	else {
		N *appoggio = *nuovo;
		while (appoggio->next != NULL)
			appoggio = appoggio->next;

		appoggio->next = registra;
	}
}

/**********************************************
 **************** CANCELLAZIONE ***************
 **********************************************/
void cancellaSeg12(N **cancella) {
	if (*cancella == NULL)
		printf("\nNon c'%c nulla da cancellare.\n", 138);
	else {
		N *check;
		N *prec;
		int trovato = 0;
		if ((*cancella)->segmento.lung == 12) {
			check = *cancella;
			*cancella = (*cancella)->next;
			free(check);
			printf("\nCancellazione effettuata...\n");
		}
		else {
			check = (*cancella)->next;
			prec = *cancella;
			while (check != NULL && !trovato) {
				if (check->segmento.lung == 12) {
					trovato = 1;
					prec->next = check->next;
				}
				else {
					prec = check;
					check = check->next;
				}
			}
			if (trovato)
				printf("\nCancellazione effettuata...\n");
			else
				printf("\nNon esiste nessun segmento lungo 12.\n");
		}
	}
}

/**************************************/
/*********** VISUALIZZAZIONE **********/
/**************************************/
void stampaSegmento(S *stampa) {
	printf("\nEstremo sinistro : (%.2f,%.2f)", stampa->estSx.x, stampa->estSx.y);
	printf("\nEstremo destro : (%.2f,%.2f)", stampa->estSx.x + stampa->lung, stampa->estSx.y);
	printf("\nLunghezza segmento : %.2f\n", stampa->lung);
}

void visualizzaLista(N *lista) {
	if (lista == NULL)
		printf("\nLista vuota...\n");
	else {
		printf("\nEcco la lista dei segmenti orizzontali :\n");
		while (lista != NULL) {
			stampaSegmento(&lista->segmento);
			lista = lista->next;
		}
	}
}