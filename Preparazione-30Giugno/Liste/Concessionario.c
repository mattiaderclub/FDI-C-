/* Programma che gestisce un concessionario di macchine

/* Ordinamento in base al prezzo decrescente */
/* Cancellazione multipla
/* File
/* Visualizza
/* Inserimento ordinato */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Strutture */
/* Struct che gestisce i dati di una macchina */
typedef struct Dati {
	char nome[20];
	char colore[20];
	float prezzo;
} M;

/* Struct che gestisce il nodo di una lista */
typedef struct Lista {
	M macchina;
	struct Lista *next;
} N;

/* Dichiarazione funzioni secondarie */
void reminder();
void campoDati(N *leggi);
void inserimentoOrdinato(N **nuovo);
void stampaMacchina(M *stampa);
void visualizzaElenco(N *head);
int daCancellare(N *elenco);
void cancellaMagg10k(N **elenco);
void leggiDaBin(N **crea);
void salvaSuBin(N *elenco);

/* Corpo del programma */
int main() {
	printf("\nCiao utente, sono un programma che gestisce un concessionario di auto.\n");

	/* Input */
	N *automobili = NULL;					// Lista di auto
	//leggiDaBin(&automobili);		// Leggo nel file e "costruisco" la lista
	int scelta = -1;				// Scelta dell'utente

	/* Ciclo d'interazione con l'utente sfruttando la variabile scelta */
	while (scelta != 0) {
		reminder();
		/* Lettura codice comando da utilizzare all'interno del while */
		printf("\nInserisci il codice comando : ");
		scanf("%d%*c", &scelta);

		if (scelta == 1)
			inserimentoOrdinato(&automobili);
		else if (scelta == 2)
			visualizzaElenco(automobili);
		else if (scelta == 3)
			cancellaMagg10k(&automobili);
	}
	/* Salvo contenuto della lista su un file */
	//salvaSuBin(automobili);
	/* Fine programma */
	printf("Chiusura programma...\n");
}

/* -----> Definizione funzioni secondarie <----- */

/* Funzione che stampa a schermo la legenda di comandi a disposizione dell'utente con tutte le funzionalità del programma associate */
void reminder() {
	printf("\nCOMANDI:\n");
	printf("\n0 - Termina il programma.");
	printf("\n1 - Inserisci un auto nell'elenco ordinandola.");
	printf("\n2 - Visualizza l'elenco corrente di auto nel concessionario.");
	printf("\n3 - Cancella tutte le auto che hanno un prezzo maggiore di 10.000 €.\n");
}


void campoDati(N *leggi) {
	printf("\nRegistro le informazioni della prossima auto...\n");

	/* Nome della macchina */
	printf("\nInserisci il nome della macchina : ");
	fgets(leggi->macchina.nome, 20, stdin);
	leggi->macchina.nome[strlen(leggi->macchina.nome) - 1] = '\0';

	/* Colore della macchina */
	printf("Di che colore %c ? ", 138);
	fgets(leggi->macchina.colore, 20, stdin);
	leggi->macchina.colore[strlen(leggi->macchina.colore) - 1] = '\0';

	/* Prezzo dell'auto */
	do {
		printf("Quanto costa la vettura ? ");
		scanf("%f", &leggi->macchina.prezzo);
		if (leggi->macchina.prezzo <= 0)
			printf("\nRegistrazione fallita, riprovare...\n");
	} while (leggi->macchina.prezzo <= 0);
}


void inserimentoOrdinato(N **nuovo) {
	N *registra = malloc(sizeof(N));

	campoDati(registra);

	if (*nuovo == NULL || registra->macchina.prezzo > (*nuovo)->macchina.prezzo) {
		registra->next = *nuovo;
		*nuovo = registra;
	}
	else {
		N *prec = *nuovo;
		N *check = (*nuovo)->next; 

		while (check != NULL && registra->macchina.prezzo <= check->macchina.prezzo) {
			prec = prec->next;
			check = check->next;
		}
		prec->next = registra;
		registra->next = check;
	}
	printf("\nInserimento ordinato effettuato...\n");
}

/* Funzione che stampa a schermo le informazioni del singolo veicolo */
void stampaMacchina(M *stampa) {
	printf("\nNome : %s", stampa->nome);
	printf("\nColore : %s", stampa->colore);
	printf("\nPrezzo : %.2f $\n", stampa->prezzo);
}	

/* Funzione che stampa a schermo l'elenco corrente di automobili che sono state registrate */
void visualizzaElenco(N *head) {
	/* Lista vuota ? */
	if (head == NULL)
		printf("\nConcessionario vuoto...\n");
	else {
		printf("\nVetture registrate:\n");
		printf("\n*******************************\n");
		/* Stampo finchè ho qualcosa in lista */
		while (head != NULL) {
			stampaMacchina(&head->macchina);		// Stampo le informazioni dell'auto
			head = head->next;				// Passo al nodo successivo
		}
	}
}

int daCancellare(N *elenco) {
	int conta = 0;
	while (elenco != NULL) {
		if (elenco->macchina.prezzo >= 10000)
			conta++;
		elenco = elenco->next;
	}
	return conta;
}

/*void cancellaMagg10k(N **elenco) {
	if ((*elenco) == NULL)
		printf("\nNulla da cancellare...\n");
	else {
		int quanti = daCancellare(*elenco);
		if (quanti == 0)
			printf("\nNessuna vettura costa piu' di 10k\n");
		else {
			N *check;
			N *prec;

			while ((*elenco) != NULL && (*elenco)->macchina.prezzo >= 10000 && quanti != 0) {
				check = *elenco;
				*elenco = (*elenco)->next;
				free(check);
				quanti--;
			}

			check = (*elenco)->next;
			prec = *elenco;

			while (check != NULL && quanti != 0) {
				if (check->macchina.prezzo >= 10000) {
					prec->next = check->next;
					quanti--;
					free(check);
				}
				prec = check;
				check = check->next;
			}
			printf("\nCancellazione multipla riuscita...");
			printf("\n%d vetture cancellate...\n", daCancellare(*elenco));
		}
	}
}*/

void leggiDaBin(N **crea);
void salvaSuBin(N *elenco);

